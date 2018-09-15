#include <cstdio>
#include<bits/stdc++.h>
#include <cstring>
#define LSOne(S) (S & (-S))
using namespace std;
typedef long long ll;
// B1 and B2 are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
ll B1[100005], B2[100005],arr[100005],sums[100010];
// Array size
int N;
// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query(ll* ft, int b) {
ll sum = 0;
for (; b; b -= LSOne(b)) 
{
sum += ft[b];
cout<<"adding "<<ft[b]<<endl;
}
return sum;
}
// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
return query(B1, b) * b - query(B2, b);
}
// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j) {
if(i>0)	
return query(j) - query(i - 1);
else
return query(j);
}
// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update1(ll* ft, int k, ll v) {
for (; k <= N; k += LSOne(k)) 
{
ft[k] += v;
//cout<<"in update 1"<<ft[k]<<endl;
}
}
void update2(ll *ft,int k,ll v)
{
	for (; k <= N; k += LSOne(k)) 
	{
		ft[k]+=ft[k]*(v-1);
		//cout<<"in update 2"<<ft[k];
	}
}

void update3(ll *ft,int k,ll v)
{
	for (; k <= N; k += LSOne(k)) ft[k]=v;
}

// Range update: Adds v to each element in [i...j]
void range_update1(int i, int j, ll v) {
update1(B1, i, v);
update1(B1, j + 1, -v);
update1(B2, i, v * (i - 1));
update1(B2, j + 1, -v * j);
}

void range_update2(int i, int j, ll v) {
update2(B1, i, v);
update2(B1, j + 1, -v);
update2(B2, i, v * (i - 1));
update2(B2, j + 1, -v * j);
}

void range_update3(int i, int j, ll v) {
update3(B1, i, v);
update3(B1, j + 1, -v);
update3(B2, i, v * (i - 1));
update3(B2, j + 1, -v * j);
}


int main() {
int T, C, p, q, r,cmd;
ll v;
// C -> No. of operations
scanf("%d %d", &N, &q);

arr[0]=sums[0]=0;

for(int i=1;i<=N;i++)
{
  cin>>arr[i];
  sums[i]=sums[i-1]+arr[i];  
}


memset(B1, 0, (N+1) * sizeof(ll));
memset(B2, 0, (N+1) * sizeof(ll));

while (q--) {
scanf("%d %d %d", &cmd, &p, &r);
// cmd is 0 for a range update and 1 for a range query
if (cmd == 1) {
scanf("%lld", &v);
range_update1(p, r, v);
} 

else if(cmd==2)
{
	scanf("%lld",&v);
	range_update2(p,r,v);
}
else if(cmd==3)
{
	scanf("%lld",&v);
	range_update3(p,r,v);
}

else
{
for(int i=1;i<=N;i++)
cout<<arr[i]<<endl;
printf("%lld\n", range_query(p, r)+sums[r]-sums[p-1]);
}
}


return 0;
}

