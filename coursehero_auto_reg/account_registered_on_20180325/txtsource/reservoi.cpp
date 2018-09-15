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
const int N = 1e3; 

char arr[N][N];
int n,m;
bool check(char block,int x,int y)
{
	if(x<0 or x>n+1 or y<0 or y>m+1)
		return true;

	if(block=='W')
	{
	   if(y==0 or y==(m+1))
	   	return false;

	   if(x>0 and x<=n and y>0 and y<=m and arr[x][y]=='A')
	   	return false;
	}

	if(block=='B')
	{
		if(x>0 and x<=n and y>0 and y<=m and (arr[x][y]=='A' or arr[x][y]=='W'))
			return false;
	}

	return true;
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	cin>>n>>m;
  	FOR(i,1,n)
  	FOR(j,1,m)
  	cin>>arr[i][j];  	

    bool flag=true;
  	FOR(i,1,n)
  	{
  		FOR(j,1,m)
  		{
  			char dummy=arr[i][j];
  			if(arr[i][j]=='W')
  			{
  				if(!check(dummy,i,j-1))
  				flag=false;
  				
  				if(!check(dummy,i,j+1))
  					flag=false;

  				if(!check(dummy,i+1,j))
  					flag=false;
  			}

  			if(arr[i][j]=='B')
  			{
  				if(!check(dummy,i+1,j))
  					flag=false;
  			}

  			if(!flag)
  				break;
  		}
  		if(!flag)
  			break;
  	}

  	if(flag)
  	cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;

  }
  return 0;
}