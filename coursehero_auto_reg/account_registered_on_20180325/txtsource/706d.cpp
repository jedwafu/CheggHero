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

int trie[3000000][2];
int freq[3000000][2];

int cnt=0;
void Insert(int n,int type)
{
	int point=0;
	int rem;
	NFOR(i,30,0)
	{
		if(n & 1<<i)
			rem=1;
		else
			rem=0;

		if(trie[point][rem]==0)
			trie[point][rem]=cnt++;

		freq[point][rem]+=type;
		point=trie[point][rem];
	}
}

ll query(int n)
{	
	int point=0;
	int rem;
	ll res=0;
	NFOR(i,30,0)
	{	
		if(n & 1<<i)
			rem=1;
		else
			rem=0;

		if(freq[point][1-rem]>0)
		{
			point=trie[point][1-rem];
			res+=(1-rem)*(1<<i);
		}
		else
		{
			point=trie[point][rem];
			res+=(rem)*(1<<i);
		}
	}
	return n^res;
}

int main(){
  fast;
  fill(trie,0);
  fill(freq,0);
  int q;
  cin>>q;
  Insert(0,1);
  FOR(i,1,q)
  {
  	char c;
  	int n;
  	cin>>c>>n;
  	if(c=='+')
  	Insert(n,1);

  	if(c=='-')
  	Insert(n,-1);

  	if(c=='?')
  		cout<<max((ll)n,query(n))<<endl;
  }
  return 0;
}