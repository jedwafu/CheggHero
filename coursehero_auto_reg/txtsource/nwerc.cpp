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

ll sen[110];
ll qsize[110];
ll d[110];
ll temp;
ll inp[110][110];
int main(){
  fast;
  ll n,q,s;
  cin>>n>>q>>s;

  for(ll i=1;i<=s;i++)
  	cin>>sen[i];

  for(ll i=1;i<=q;i++)
  	cin>>qsize[i];

  for(ll i=1;i<=n;i++)
  	for(ll j=1;j<=s;j++)
  		inp[sen[j]][i]=0;

  for(ll i=1;i<=n;i++)
  {
  	cin>>d[i];
  	inp[sen[i]][0]=0;
  	for(ll j=1;j<=s;j++)
  	{
      cin>>temp;
      inp[sen[j]][i]+=temp;
  	}
  }

  
  
  ll reserve=0;
  ll sum=0;
  for(ll j=1;j<=n-1;j++)
  {
  	reserve+=d[j];

  	 /*  sum=0;
  	   for(ll i=1;i<=q;i++)
  		sum+=inp[i][j]; */

  	for(ll i=1;i<=q;i++)
  	{
       
      /* if(d[j]<sum)
       {
  	   	  cout<<"impossible";
            return 0;
  	   }*/	

  	   if(inp[i][j]>qsize[i])
  	   {
  	   	  cout<<"impossible";
            return 0;
  	   }

       inp[i][j]+=inp[i][j-1];

       if(inp[i][j]+inp[i][j+1]>qsize[i])
       {
            if(reserve>=(inp[i][j]-(qsize[i]-inp[i][j+1])))
            {
               reserve-=(inp[i][j]-(qsize[i]-inp[i][j+1]));
               inp[i][j]=qsize[i]-inp[i][j+1];
            }
            else
            {
            	cout<<"impossible";
            	return 0;
            }
       }
  	}

  	sum=0;
  	for(int i=1;i<=q;i++)
  		sum+=inp[i][j];

  	reserve=min(reserve,sum);

  }
  //cout<<reserve<<endl;
  reserve+=d[n];
  for(int i=1;i<=q;i++)
  {
  	//cout<<inp[i][n]<<endl;
  	if(inp[i][n]>qsize[i])
  	{
  		cout<<"impossible";
  		return 0;
  	}

  	inp[i][n]+=inp[i][n-1];
  //	cout<<reserve<<" "<<inp[i][n]<<endl;
  	if(inp[i][n]<=reserve)
  	{
        reserve-=inp[i][n];
  	}
  	else
  	{
  		cout<<"impossible";
  		return 0;
  	}
  }

  cout<<"possible";
  return 0;
}