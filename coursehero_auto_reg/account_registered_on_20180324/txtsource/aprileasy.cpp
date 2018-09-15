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
const int N = 1e6+10; 

int road[N];
int nr[2][N],nl[2][N];

int calc(int pos,int flip)
{
	if(flip)
	return nl[1][pos]-nr[0][pos]+1;
	else
	return nr[1][pos]-nl[0][pos]+1;
}

int main(){
  fast;
  int n,q;
  cin>>n;
  FOR(i,1,n-1)
  cin>>road[i];

  nr[0][1]=nl[0][1]=1;
  nr[1][n]=nl[1][n]=n;
  FOR(i,2,n)
  {	
  	if(road[i-1])
  	{
  		nr[0][i]=nr[0][i-1];
  		nl[0][i]=i;
  	}
  	else
  	{
  		nr[0][i]=i;
  		nl[0][i]=nl[0][i-1];
  	}
  }

  NFOR(i,n-1,1)
  {
  	if(road[i])
  	{
  		nr[1][i]=nr[1][i+1];
  		nl[1][i]=i;
  	}
  	else
  	{
  		nr[1][i]=i;
  		nl[1][i]=nl[1][i+1];
  	}
  }

  cin>>q;
  int flip=0;

  FOR(i,1,q)
  {
  	char ch;
  	cin>>ch;
  	if(ch=='U')
  	flip=1-flip;
  	else
  	{
  		int t;
  		cin>>t;
  		cout<<calc(t,flip)<<endl;
  	}
  }
  return 0;
}