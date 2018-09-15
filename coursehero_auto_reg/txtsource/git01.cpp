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

char arr[110][110];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	
  	int n,m;
  	cin>>n>>m;
  	for(int i=0;i<n;i++)
  	for(int j=0;j<m;j++)
  	cin>>arr[i][j];

  	int c1=0;
  	int c2=0;

  	for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<m;j++)
  		{
  			if(i%2==0 and j%2==0 and arr[i][j]=='G')
	  		c1+=3;
	  		if(i%2==0 and j%2==1 and arr[i][j]=='R')
	  		c1+=5;
	  		if(i%2==1 and j%2==0 and arr[i][j]=='R')
	  		c1+=5;
	  		if(i%2==1 and j%2==1 and arr[i][j]=='G')
	  		c1+=3;
	  	}
  	}


  	for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<m;j++)
  		{
  			if(i%2==0 and j%2==0 and arr[i][j]=='R')
	  		c2+=5;
	  		if(i%2==0 and j%2==1 and arr[i][j]=='G')
	  		c2+=3;
	  		if(i%2==1 and j%2==0 and arr[i][j]=='G')
	  		c2+=3;
	  		if(i%2==1 and j%2==1 and arr[i][j]=='R')
	  		c2+=5;
	  	}
  	}

  	cout<<min(c1,c2)<<endl;
  }
  return 0;
}