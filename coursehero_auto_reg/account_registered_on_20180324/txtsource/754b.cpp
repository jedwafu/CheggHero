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
string s[5];

bool check(int i1,int j1,int i2,int j2,int i3,int j3)
{
	if(i1<0 or i1>3 or j1<0 or j1>3 or i2<0 or i2>3 or j2<0 or j2>3 or i3<0 or i3>3 or j3<0 or j3>3)
       return false;	
    if(s[i1][j1]=='x' and s[i2][j2]=='x' and s[i3][j3]=='x')
    return true;
    else return false;	
}

int main(){
  fast;
  cin>>s[0]>>s[1]>>s[2]>>s[3];
  
  FOR(i,0,3)
  {
  	FOR(j,0,3)
  	{
  		if(s[i][j]=='.')
  		{
  			s[i][j]='x';
  			if(check(i,j-2,i,j-1,i,j))
  			{
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i,j-1,i,j,i,j+1))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i,j,i,j+1,i,j+2))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i-2,j,i-1,j,i,j))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i-1,j,i,j,i+1,j))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i,j,i+1,j,i+2,j))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i-2,j-2,i-1,j-1,i,j))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i-1,j-1,i,j,i+1,j+1))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i,j,i+1,j+1,i+2,j+2))
  		    {
  				cout<<"YES";
  				return 0;
  			}
             if(check(i,j,i-1,j+1,i-2,j+2))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i+1,j-1,i,j,i-1,j+1))
  		    {
  				cout<<"YES";
  				return 0;
  			}
  			if(check(i+2,j-2,i+1,j-1,i,j))
  		    {
  				cout<<"YES";
  				return 0;
  			}
            s[i][j]='.';
  		}
  	}

  }

  cout<<"NO";

  return 0;
}