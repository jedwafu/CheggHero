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
const int N = 1e3+10; 

int n;
char arr[10][N];
char smallest[N];
char temp[N];

void check()
{
	FOR(i,1,n)
	{
		if(smallest[i]<temp[i])
			return;

		if(temp[i]<smallest[i])
		{
			FOR(j,1,n)
			smallest[j]=temp[j];
			return;
		}
	}
}

int main(){
  fast;
  cin>>n;

  FOR(i,1,n)
  {
  	cin>>arr[0][i];
  	smallest[i]=arr[0][i];
  }
  	
  FOR(j,1,9)
  {
  	FOR(i,1,n)
  	arr[j][i]=(arr[j-1][i]=='9' ? '0':arr[j-1][i]+1);
  }

  FOR(j,0,9)
  {
  	FOR(i,1,n)
  	{
  		int idx=1;
  		FOR(k,i,n)
  		temp[idx++]=arr[j][k];
  		FOR(k,1,i-1)
  		temp[idx++]=arr[j][k];

  		check();
  	}
  }

  FOR(i,1,n)
  cout<<smallest[i];
  return 0;
}