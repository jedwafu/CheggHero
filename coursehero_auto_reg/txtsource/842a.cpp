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
const int N = 1e6+2; 

int trie[2][21*N];
bool present[N];
int last=2;
void insert(int x)
{
	int cur=1;
	for(int i=19;i>=0;i--)
	{
		if((1<<i) & x)
		{
			if(!trie[1][cur])
				trie[1][cur]=last++;

			cur=trie[1][cur];
		}
		else
		{
			if(!trie[0][cur])
				trie[0][cur]=last++;

			cur=trie[0][cur];
		}
	}
}


int query(int x)
{
	int cur=1;
	int ans=0;
	for(int i=19;i>=0;i--)
	{
		if((1<<i) & x)
		{
			if(trie[1][cur])
				cur=trie[1][cur];
			else
			{
				ans+=(1<<i);
				cur=trie[0][cur];
			}
		}
		else
		{
			if(trie[0][cur])
				cur=trie[0][cur];
			else
			{
				ans+=(1<<i);
				cur=trie[1][cur];
			}
		}
	}
	return ans;
}
int main(){
  fast;
  fill(trie,0);
  fill(present,0);
  int n,m;
  cin>>n>>m;
  FOR(i,1,n)
  {
  	int x;
  	cin>>x;
  	present[x]=true;
  }

  FOR(i,0,N-1)
  {
  	if(!present[i])
  		insert(i);
  }

  int xorval=0;
  FOR(i,1,m)
  {
  	int x;
  	cin>>x;
  	xorval^=x;
  	cout<<query(xorval)<<endl;
  }

  return 0;
}