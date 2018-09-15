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
const int N = 50+10; 

int w[N][N];
int n,k;
bool FloydWarshall (){
  
  for (int k = 1; k <= n; k++){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (w[i][j] > w[i][k] + w[k][j]){
          w[i][j] = w[i][k] + w[k][j];
        }
      }
    }
  }
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	FOR(i,1,50)
  	FOR(j,1,50)
  	w[i][j]=mod;

  	cin>>n>>k;
  	FOR(i,1,n-1)
  	w[i][i+1]=w[i+1][i]=1;

  	FOR(i,1,k)
  	{
  		int a,b;
  		cin>>a>>b;
  		w[a][b]=w[b][a]=1;
  	}

  	FloydWarshall();
  	ll ans=0;
  	FOR(i,1,n)
  	FOR(j,1,i-1)
  	if(w[i][j]!=mod)
  	ans+=w[i][j];

  	cout<<ans<<endl;
  }
  return 0;
}