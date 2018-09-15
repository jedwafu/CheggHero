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

int rows[3][N];
int cols[3][N];
int diag[3][2*N];
int diag2[3][2*N];
int R[N],C[N];
int final[10];

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(final,0);
  int offset=N-10;

  FOR(i,1,N-1)
  {
  	rows[0][i]=cols[0][i]=0;
  	rows[1][i]=cols[1][i]=0;
  	rows[2][i]=cols[2][i]=N;
  }
  FOR(i,1,2*N-1)
  {
  	diag[0][i]=diag[1][i]=diag2[0][i]=diag2[1][i]=0;
  	diag[2][i]=diag2[2][i]=2*N;
  }

  FOR(i,1,m)
  {
  	int r,c;
  	cin>>r>>c;
  	R[i]=r;
  	C[i]=c;
  	rows[0][r]++;
  	rows[1][r]=max(rows[1][r],c);
  	rows[2][r]=min(rows[2][r],c);

  	cols[0][c]++;
  	cols[1][c]=max(cols[1][c],r);
  	cols[2][c]=min(cols[2][c],r);

  	diag[0][r-c+offset]++;
  	diag[1][r-c+offset]=max(diag[1][r-c+offset],c);
  	diag[2][r-c+offset]=min(diag[2][r-c+offset],c);

  	diag2[0][r+c]++;
  	diag2[1][r+c]=max(diag2[1][r+c],c);
  	diag2[2][r+c]=min(diag2[2][r+c],c);
  }

  FOR(i,1,m)
  {
  	int ans=0;

  	if(rows[0][R[i]]==2)
  		ans++;
  	else if(rows[0][R[i]]>2)
  	{
  		if(rows[1][R[i]]>C[i] and rows[2][R[i]]<C[i])
  			ans+=2;
  		else
  			ans++;
  	}

  	if(cols[0][C[i]]==2)
  		ans++;
  	else if(cols[0][C[i]]>2)
  	{
  		if(cols[1][C[i]]>R[i] and cols[2][C[i]]<R[i])
  			ans+=2;
  		else
  			ans++;
  	}

  	if(diag[0][R[i]-C[i]+offset]==2)
  		ans++;
  	else if(diag[0][R[i]-C[i]+offset]>2)
  	{
  		if(diag[1][R[i]-C[i]+offset]>C[i] and diag[2][R[i]-C[i]+offset]<C[i])
  			ans+=2;
  		else
  			ans++;
  	}

  	if(diag2[0][R[i]+C[i]]==2)
  		ans++;
  	else if(diag2[0][R[i]+C[i]]>2)
  	{
  		if(diag2[1][R[i]+C[i]]>C[i] and diag2[2][R[i]+C[i]]<C[i])
  			ans+=2;
  		else
  			ans++;
  	}
  	final[ans]++;
  }

  FOR(i,0,8)
  cout<<final[i]<<" ";
  return 0;
}