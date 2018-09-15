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

vi edge[N];
ll fval1[N];
ll fval2[N];
ll arr[N];
int n,l,k;
int dfs(int source)
{
	if(edge[source].empty())
	{
		fval1[source]=arr[source];
		return 0; 
	}

   int maxb=1;
   FOR(i,0,edge[source].size()-1)
   maxb+=dfs(edge[source][i]);
   
   fval1[source]=-1;
   if(maxb<=n-l-k)
   {
   	 FOR(i,0,edge[source].size()-1)
     fval1[source]=max(fval1[source],fval1[edge[source][i]]);
   }
   else
   {
   	 fval1[source]=(ll)1e15;
   }
   return maxb;
}

int dfs2(int source)
{
	if(edge[source].empty())
	{
		fval2[source]=arr[source];
		return 0; 
	}

	int minb=1;
	FOR(i,0,edge[source].size()-1)
    minb+=dfs2(edge[source][i]);

    fval2[source]=INF;
    if(minb<=k)
    {
      FOR(i,0,edge[source].size()-1)
      fval2[source]=min(fval2[source],fval2[edge[source][i]]);      
    }
    else
    {
    	fval2[source]=-1;
    }
    return minb;
}

ll maxi(int source,int kval)
{
	if(edge[source].size()==1)
		return maxi(edge[source][0],kval);
    
    if(edge[source].size()==0)
    	return arr[source];

	if(kval==0)
	{
		
		return fval2[source];
	}

    ll maxval=-1;
	FOR(i,0,edge[source].size()-1)
	maxval=max(maxval,maxi(edge[source][i],kval-1));
	return maxval;
}

ll mini(int source,int kval)
{
	if(edge[source].size()==1)
		return mini(edge[source][0],kval);

    if(edge[source].size()==0)
    	return arr[source];

	if(kval==0)
	{
		return fval1[source];
	}

    ll minval=INF;
	FOR(i,0,edge[source].size()-1)
	minval=min(minval,mini(edge[source][i],kval-1));
	return minval;
}

int main(){
  fast;
  cin>>n>>k;
  FOR(i,2,n)
  {
  	int p;
  	cin>>p;
  	edge[p].pb(i);
  }
  
  FOR(i,1,n)
  {
  	if(edge[i].empty())
  		l++;
  	fval1[i]=-1;
  	fval2[i]=INF;
  }
  FOR(i,1,n)
  cin>>arr[i];
  
   dfs(1);
  ll ans1=mini(1,k);
  dfs2(1);
  ll ans2=maxi(1,n-l-k);
  

  cout<<ans1<<" "<<ans2<<endl;
  return 0;
}