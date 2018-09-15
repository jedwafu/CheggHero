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

int trie[50*N][2];
ll arr[N],pre[N],suff[N];

int last=2;
int temp[50];

void insert(ll val)
{
	int cur=1;
	NFOR(i,40,0)
	{
		int bit=(((val) >> (i)) & 1);
		if(!trie[cur][bit])
		{
			trie[cur][bit]=last++;
			//cout<<"inserted "<<i<<"'th bit "<<bit<<" at "<<trie[cur][bit]<<endl;
			cur=last-1;
		}
		else
		{
			//cout<<"inserted "<<i<<"'th bit "<<bit<<" at "<<trie[cur][bit]<<endl;
			cur=trie[cur][bit];
		}
	}	
}

ll query(ll val)
{
	int cur=1;

	NFOR(i,40,0)
	{
		int bit= (((val) >> (i)) & 1);
		if(trie[cur][bit^1])
		{
			temp[i]=1;
			cur=trie[cur][bit^1];
		} 
		else
		{
			temp[i]=0;
			cur=trie[cur][bit];
		}
	}

	ll pows=1;
	ll ret=0;
	FOR(i,0,40)
	{
		ret+=pows*temp[i];
		pows*=2;
	}	
	return ret;
}

int main()
{
  fast;
  int n;
  cin>>n;

  
  FOR(i,1,n)
  cin>>arr[i];

  fill(trie,0);

  pre[1]=arr[1];
  ll ans=pre[1];
  FOR(i,2,n)
  {
  	pre[i]=pre[i-1]^arr[i];
  	ans=max(ans,pre[i]);
  }

  suff[n]=arr[n];
  ans=max(ans,suff[n]);

  NFOR(i,n-1,1)
  {
  	suff[i]=suff[i+1]^arr[i];
  	ans=max(ans,suff[i]);
  }
 
  insert(0);	
  NFOR(i,n,2)
  {
  	insert(suff[i]);
  	ans=max(ans,query(pre[i-1]));
  } 	  

  cout<<ans<<endl;
  return 0;
}