#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

int n;
long long int arr[100010];
long long int tree[10000000];
long long int adds[10000000];
long long int mul[10000000];
long long int ini[10000000];
 
long long int add(long long int f,long long int s)
{
	long long int temp=f+s;
	
	while(temp>=m)
	temp-=m;
	
	return temp;
}

long long int multiply(long long int f,long long int s)
{
	long long int temp=(f*s)%m;
	return temp;
}

void laziness(long long int node,long long int a,long long int b)
{
long long int mid=(a+b)/2;

if(ini[node]!=-1)
{
tree[node]=((b-a+1)*ini[node])%m;

if(a!=b)
{
ini[2*node]=ini[node];
ini[2*node+1]=ini[node];	
adds[2*node]=0;
adds[2*node+1]=0;
mul[2*node]=1;
mul[2*node+1]=1;
}
ini[node]=-1;
}
 
//cout<<"mul "<<node<<" "<<mul[node]<<endl;
//cout<<"adds "<<node<<" "<<adds[node]<<endl; 

if(mul[node]!=1||adds[node]!=0)
{

tree[node]=multiply(tree[node],mul[node]);
tree[node]=add(tree[node],((b-a+1)*adds[node])%m);
 
//cout<<"tree "<<node<<" is now"<<tree[node]<<endl;
if(a!=b) 
{
mul[2*node]=multiply(mul[2*node],mul[node]);
mul[2*node+1]=multiply(mul[2*node+1],mul[node]);

adds[2*node]=multiply(adds[2*node],mul[node]);
adds[2*node+1]=multiply(adds[2*node+1],mul[node]);		
adds[2*node]=add(adds[2*node],adds[node]);
adds[2*node+1]=add(adds[2*node+1],adds[node]);
}

adds[node]=0;
mul[node]=1;
}

}

void build_tree(long long int node,long long  int a,long long  int b) {
if(a > b) return;
 
if(a == b) {
tree[node] = arr[a];
return;
}
 
build_tree(node*2, a, (a+b)/2);
build_tree(node*2+1, (a+b)/2+1, b);
tree[node] = add((tree[node*2]),(tree[node*2+1]));
}
 
void update_tree1(long long int node,long long int a,long long int b,long long int i,long long int j, long long int value) {
 
laziness(node,a,b);
  
if(a > b || a > j || b < i)
return;
 
if(a >= i && b <= j)
{
tree[node]=add(tree[node],((b-a+1)*value)%m);
//cout<<"tree "<< node<<" is now"<<tree[node]<<endl;
 
if(a != b) {
adds[2*node]=add(adds[2*node],value);
//cout<<"adds "<<2*node<<" is now"<<adds[2*node]<<endl;
adds[2*node+1]=add(adds[2*node+1],value);
//cout<<"adds "<<2*node+1<<" is now"<<adds[2*node+1]<<endl;
}
return;
}
 
update_tree1(node*2, a, (a+b)/2, i, j, value);
update_tree1(1+node*2, (a+b)/2+1, b, i, j, value);
tree[node] = add(tree[node*2],tree[node*2+1]);
}
 
void update_tree2(long long int node, long long int a, long long int b, long long int i, long long int j, long long int value) {

laziness(node,a,b);

if(a > b || a > j || b < i)
return;
 
if(a >= i && b <= j)
{
tree[node]=multiply(tree[node],value);
 
if(a != b) {
mul[2*node]=multiply(mul[2*node],value);
mul[2*node+1]=multiply(mul[2*node+1],value);
adds[2*node]=multiply(adds[2*node],value);
adds[2*node+1]=multiply(adds[2*node+1],value);
}
return;
}
update_tree2(node*2, a, (a+b)/2, i, j, value);
update_tree2(1+node*2, (a+b)/2+1, b, i, j, value);

tree[node] = add(tree[node*2],tree[node*2+1]);
}
 
void update_tree3(long long int node,long long int a, long long int b, long long int i, long long int j, long long int value) {


 
if(a > b || a > j || b < i)
return;
  
if(a >= i && b <= j)
{
tree[node]=multiply((b-a+1),value);
//cout<<"tree "<<node<<" "<<tree[node]<<endl;
 
if(a != b) {
ini[2*node]=value;
ini[2*node+1]=value;
adds[2*node]=0;
adds[2*node+1]=0;
mul[2*node]=1;
mul[2*node+1]=1;
//cout<<"ini "<<2*node<<" is"<<ini[2*node]<<endl;
//cout<<"ini "<<2*node+1<<" is"<<ini[2*node+1]<<endl;
}
return;
}

laziness(node,a,b);

update_tree3(node*2, a, (a+b)/2, i, j, value);
update_tree3(1+node*2, (a+b)/2+1, b, i, j, value);
tree[node] = add(tree[node*2],tree[node*2+1]);
}
 
long long int query_tree(int node, int a, int b, int i, int j) {



if(a > b || a > j || b < i) return 0;
 
if(a >= i && b <= j)
return tree[node];

laziness(node,a,b);

long long int q1 = query_tree(node*2, a, (a+b)/2, i, j);
long long int q2 = query_tree(1+node*2, (a+b)/2+1, b, i, j);
long long int res = add(q1,q2);

return res;
}

int main() {
int q;
scanf("%d %d",&n,&q);
for(int i=0;i<10000000;i++)
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
long long int dec,a,b;
long long int v;
scanf("%lld %lld %lld",&dec,&a,&b);
//cout<<"dec "<<dec<<" a "<<a<<" b "<<b<<endl;
if(dec==1)
{
scanf("%lld",&v);
update_tree1(1,1,n,a,b,v);
}
else if(dec==2)
{
scanf("%lld",&v);
update_tree2(1,1,n,a,b,v);
}
else if(dec==3)
{
scanf("%lld",&v);
update_tree3(1,1,n,a,b,v);
}
else if(dec==4)
{
printf("%lld\n",query_tree(1,1,n,a,b));
}
}
return 0;
} 
