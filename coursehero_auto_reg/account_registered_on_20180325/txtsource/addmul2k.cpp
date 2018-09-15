#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;

int n,q;
long long int st,ed,value,ch;

long long int arr[100010];
long long int tree[10000000];
long long int adds[10000000];
long long int mul[10000000];
long long int ini[10000000];

long long int add(long long int f,long long int s )
{
	long long int temp=f+s;
	while(temp>=m)
	temp-=m;
	return temp;
}

void build_tree(long long int node,long long  int a,long long  int b) {
 
if(a == b) {
tree[node] = arr[a];

adds[node]=0,mul[node]=1,ini[node]=-1;
return;
}
 
long long int mid=(a+b)/2;

build_tree(2*node, a, mid); 
build_tree(2*node+1, mid+1, b);

tree[node]=add(tree[2*node],tree[2*node+1]);
adds[node]=0,mul[node]=1,ini[node]=-1;
}

 
void laziness(long long int node, long long int child,long long int a,long long int b)
{
if(ini[node]!=-1)
{

ini[child]=ini[node];
adds[child]=adds[node];
mul[child]=mul[node];

tree[child]=((b-a+1)*ini[child])%m;
tree[child]=(tree[child]*mul[child])%m;
tree[child]=add(tree[child],((b-a+1)*adds[node])%m);
}

else
{
tree[child]=(tree[child]*mul[node])%m;	
tree[child]=add(tree[child],((b-a+1)*adds[node])%m);
adds[child]=(adds[child]*mul[node])%m;
adds[child]=add(adds[child],adds[node]);
mul[child]=(mul[child]*mul[node])%m;
}
 
//cout<<"mul "<<node<<" "<<mul[node]<<endl;
//cout<<"adds "<<node<<" "<<adds[node]<<endl; 

//tree[node]=multiply(tree[node],mul[node]);
//tree[node]=add(tree[node],((b-a+1)*adds[node])%m);
 
//cout<<"tree "<<node<<" is now"<<tree[node]<<endl;
}
 

 
void update_tree1(long long int node,long long int a,long long int b) {
 
if(a > ed || b < st)
return;
 
if(a >= st && b <= ed)
{
tree[node]=add(tree[node],((b-a+1)*value)%m);
adds[node]=add(adds[node],value);
return;
}

long long int mid=(a+b)/2;

laziness(node,2*node,a,mid);
laziness(node,2*node+1,mid+1,b);
adds[node]=0,mul[node]=1,ini[node]=-1;
 
 
update_tree1(node*2, a, (a+b)/2);
update_tree1(1+node*2, (a+b)/2+1, b);

tree[node] = add(tree[node*2],tree[node*2+1]);
}
 
void update_tree2(long long int node, long long int a, long long int b) {



if(a > ed || b < st)
return;
 
if(a >= st && b <= ed)
{
tree[node]=(tree[node]*value)%m;
mul[node]=(mul[node]*value)%m;
adds[node]=(adds[node]*value)%m;
return;
}

long long int mid=(a+b)/2;

laziness(node,2*node,a,mid);
laziness(node,2*node+1,mid+1,b);
adds[node]=0,mul[node]=1,ini[node]=-1;
 
 
update_tree2(node*2, a, (a+b)/2);
update_tree2(1+node*2, (a+b)/2+1,b);

tree[node] = add(tree[node*2],tree[node*2+1]);
}
 
void update_tree3(long long int node,long long int a, long long int b) {

if(a > ed || b < st)
return;
  
if(a >= st && b <= ed)
{
ini[node]=value;
adds[node]=0;
mul[node]=1;
tree[node]=((b-a+1)*value)%m;
return;
}

long long int mid=(a+b)/2;

laziness(node,2*node,a,mid);
laziness(node,2*node+1,mid+1,b);
adds[node]=0,mul[node]=1,ini[node]=-1;
 
 
update_tree3(node*2, a, (a+b)/2);
update_tree3(1+node*2, (a+b)/2+1, b);

tree[node] = add(tree[node*2],tree[node*2+1]);

}
 
long long int query_tree(int node, int a, int b) {

if(a > ed || b < st) return 0;
 
if(a >= st && b <= ed)
return tree[node];

long long int mid=(a+b)/2;

laziness(node,2*node,a,mid);
laziness(node,2*node+1,mid+1,b);

adds[node]=0,mul[node]=1,ini[node]=-1;
 
tree[node] = add(tree[node*2],tree[node*2+1]);

return add(query_tree(2*node,a,mid),query_tree(2*node+1,mid+1,b));
}


int main() {

scanf("%d %d",&n,&q);

for(int i=0;i<=10000000;i++)
{
tree[i]=0;	
adds[i]=0;
mul[i]=1;
ini[i]=-1;
}

for(int i = 1; i <= n; i++)
scanf("%lld",&arr[i]);

build_tree(1, 1, n);

while(q--)
{
scanf("%lld %lld %lld",&ch,&st,&ed);
if(ch==1)
{
scanf("%lld",&value);
update_tree1(1,1,n);
}
else if(ch==2)
{
scanf("%lld",&value);
update_tree2(1,1,n);
}
else if(ch==3)
{
scanf("%lld",&value);
update_tree3(1,1,n);
}
else if(ch==4)
{
printf("%lld\n",query_tree(1,1,n));
}
}
return 0;
} 
