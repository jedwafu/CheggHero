#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

int ans=0;
int point[4];
int a[7];
int x,y,z;
int a1,a2,a3,a4,a5,a6;
void check(int num, int op, int axis,int val)
{
   if(op) 
   if(point[axis]>val)
   	ans+=a[num];

   if(!op)
   	if(point[axis]<val)
   		ans+=a[num];
}

int main(){
  fast;
  
  cin>>point[1]>>point[2]>>point[3];
  cin>>x>>y>>z;
  cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];
   
  check(1,0,2,0);
  check(2,1,2,y);
  check(3,0,3,0);
  check(4,1,3,z);
  check(5,0,1,0);
  check(6,1,1,x);
   
  cout<<ans;
  return 0;
}