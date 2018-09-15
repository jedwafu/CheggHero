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

ll arr[100];
int main(){
  fast;
  ll n;
  cin>>n;

  string s;
  cin>>s;
  FOR(i,0,sz(s)-1)
  arr[i]=s[i]-'0';

  int cur=sz(s)-1;
  ll ans=0;
  ll temp=0;
  ll pows=0;
  ll index=1;
  int len=0;

  while(cur>=0)
  {
  	while(cur>=0 and ((index*arr[cur])+temp)<=n)
  	{

        if(((index*arr[cur])+temp)==n)
        {
        	temp=1;
        	pows++;
        	cur--;
        	break;
        }

  		temp=index*arr[cur]+temp;
  		cur--;
  		index*=10;
  		len++;
  	}

  	ans+=(temp)*pow(n,pows);
  	pows++;

  	if(temp==0 and len>1)
  	{
  	  index/=10;  
  	  len--;	
  	}
    else
  	{
  		temp=0;
  	    index=1;
  	    len=0;
    }
  }
  
  cout<<ans;
  return 0;
}