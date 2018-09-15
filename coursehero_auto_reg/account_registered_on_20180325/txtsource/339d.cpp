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
#define MID (left+right)/2
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 131100; 

ll arr[N];
ll ST[4*N];
int val[4*N];


int InitTree(int idx, int left, int right)
{
    if (left == right)
    {
        ST[idx] = arr[left];
        val[idx]=0;
        return 0;
    }
   int val1=InitTree(2*idx, left, MID);
   int val2=InitTree(2*idx+1, MID+1, right);

    if(val1==1)
    ST[idx] = (ST[2*idx])^(ST[2*idx+1]);
    if(val1==0)
    ST[idx] = (ST[2*idx])|(ST[2*idx+1]);
    
    val[idx]=1-val1;
    return val[idx];

}

void Update(int idx, int x, ll v, int left, int right)
{
    if (left == right)
    {
        ST[idx] = v;
        return;
    }
    if (x <= MID) Update(2*idx, x, v, left, MID);
    else Update(2*idx+1, x, v, MID+1, right);

    if(val[idx]==0)
    ST[idx] = (ST[2*idx])^(ST[2*idx+1]);
    else
    ST[idx] = (ST[2*idx])|(ST[2*idx+1]);
    return;
}


int main(){
  fast;
  int n,m;
  cin>>n>>m;
  n=pow(2,n);
  for(int i=1;i<=n;i++)
  	cin>>arr[i];

  InitTree(1,1,n);
  FOR(i,1,m)
  {
  	int p;
  	ll b;
  	cin>>p>>b;
  	Update(1,p,b,1,n);
  	cout<<ST[1]<<endl;
  }


  return 0;
}