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

char arr[410][410];
int toggle[410];
int main(){
  fast;
  int t;
  cin>>t;
  int m,n;
  while(t--)
  {
  	cin>>m>>n;
  	FOR(i,0,m-1)
  	FOR(j,0,n-1)
  	{
  	  cin>>arr[i][j];
  	  toggle[j]=0;
  	}	

    int count;
    int ans=0;
  	FOR(i,0,m-1)
  	{
  		int count=0;
  		NFOR(j,n-1,0)
  		{
           if(arr[i][j]=='0' and !((count+toggle[j])%2))
            {
            	ans++;
            	count++;
            	toggle[j]++;
            }
            if(arr[i][j]=='1' and ((count+toggle[j])%2))
            {
            	ans++;
            	count++;
            	toggle[j]++;
            }
   		}
  	}

  	cout<<ans<<endl;

  }
  return 0;
}