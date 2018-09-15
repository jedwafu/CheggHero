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
const int N = 3e5+10; 

int arr[N];
int lefts[N];
int rights[N];
bool done[N];
int main(){
  fast;
  int n;
  cin>>n;
  fill(done,0);
  FOR(i,1,n)
  cin>>arr[i];
  lefts[1]=1;
  rights[n]=n;
  FOR(i,2,n)
  {
  	lefts[i]=i;
  	int temp=i-1;
  	while(temp>0 and arr[temp]%arr[i]==0)
  	{
  		lefts[i]=lefts[temp];
  		temp=lefts[temp]-1;
  	}
  }
  NFOR(i,n-1,1)
  {
  	rights[i]=i;
  	int temp=i+1;
  	while(temp<=n and arr[temp]%arr[i]==0)
  	{
  		rights[i]=rights[temp];
  		temp=rights[temp]+1;
  	}
  }
  int maxi=0,count=0;
  FOR(i,1,n)
  maxi=max(maxi,rights[i]-lefts[i]);
  FOR(i,1,n)
  {
  	if(rights[i]-lefts[i]==maxi)
  	{
        if(!done[lefts[i]])
        	count++;
  		done[lefts[i]]=true;
  	}
  }
  cout<<count<<" "<<maxi<<endl;
  //sort(ans.begin(),ans.end());
  FOR(i,1,n)
  if(done[i])
  	cout<<i<<" ";

  return 0;
}