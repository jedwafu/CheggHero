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
string s;
string t;
string k;
int check[30];

int main(){
  fast;
  cin>>s;

  fill(check,0);
  FOR(i,0,sz(s)-1)
  check[s[i]-'a']=1;
  
  cin>>t;
  int pos=-1;

  FOR(i,0,sz(t)-1)
  {
  	if(t[i]=='*')
  	{
  		pos=i;
  	}
  }

  if(pos==-1)
  {
  	int n;
  	cin>>n;
  	FOR(i,1,n)
  	{
  		cin>>k;
  		if(sz(k)!=sz(t))
  			cout<<"NO"<<endl;
  		else
  		{
  			bool val=true;
  			FOR(j,0,sz(k)-1)
  			{
  				if(k[j]!=t[j] and !(t[j]=='?' and check[k[j]-'a']==1))
  				{
  					val=false;
  					break;
  				}
  			}
  			if(val)
  			cout<<"YES"<<endl;
  			else
  			cout<<"NO"<<endl;
  		}
  	}

  }
  else
  {
  	int n;
  	cin>>n;
  	FOR(i,1,n)
  	{
  		cin>>k;
  		if(sz(k)<sz(t)-1)
  		cout<<"NO"<<endl;
  		else
  		{
  			bool val=true;
  			FOR(j,0,pos-1)
  			{
  				if(k[j]!=t[j] and !(t[j]=='?' and check[k[j]-'a']==1))
  				{
  					val=false;
  					break;
  				}
  			}
  			int kpos=sz(k)-1;
  			NFOR(j,sz(t)-1,pos+1)
  			{
  				if(k[kpos]!=t[j] and !(t[j]=='?' and check[k[kpos]-'a']==1))
  				{
  					val=false;
  					break;
  				}
  				kpos--;
  			}

  			if(val==false)
  				cout<<"NO"<<endl;
  			else
  			{
  				FOR(j,pos,kpos)
  				{
  					if(check[k[j]-'a']==1)
  					{
  						val=false;
  						break;
  					}
  				}

  				if(val)
  					cout<<"YES"<<endl;
  				else
  					cout<<"NO"<<endl;
  			}
  		}
  	}
  }


  return 0;
}