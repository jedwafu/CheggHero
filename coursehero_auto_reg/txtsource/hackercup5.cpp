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
const ll INF = 1e12;
const ll mod = 1e9+7;
const int N = 1e5+10; 

ll weight[200][200];
ll dps[6000][2];
ll dpd[6000][3];
int s[6000];
int d[6000];
//This code for FloydWarshall is taken from the Standford ACM Notebook.
void FloydWarshall (int n){
  for (int k = 1; k <= n; k++){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (weight[i][j] > weight[i][k] + weight[k][j]){
          weight[i][j] = weight[i][k] + weight[k][j];
        }
      }
    }
  }
}

ll solve(int type,int index,int quant)
{
	if(type==1 and dps[index][quant]!=INF)
		return dps[index][quant];

	if(type==2 and dpd[index][quant]!=INF)
		return dpd[index][quant];

	if(type==1)
	{
		if(quant==0)
			dps[index][0]=solve(2,index-1,1)+weight[d[index-1]][s[index]];	
		if(quant==1)
		{	
			if(index>2)
			dps[index][1]=min(solve(1,index-1,0)+weight[s[index-1]][s[index]],solve(2,index-2,2)+weight[d[index-2]][s[index]]);
			else
			dps[index][1]=(solve(1,index-1,0)+weight[s[index-1]][s[index]]);		
		}
		return dps[index][quant];		
	}

	if(type==2)
	{
		if(quant==1)
		{
			if(index>1)
			dpd[index][1]=min(solve(1,index,0)+weight[s[index]][d[index]],solve(2,index-1,2)+weight[d[index-1]][d[index]]);
			else
			dpd[index][1]=(solve(1,index,0)+weight[s[index]][d[index]]);	
		}
		if(quant==2)
		{
			dpd[index][2]=solve(1,index+1,1)+weight[s[index+1]][d[index]];
		}

		return dpd[index][quant];
	}

}

int main(){

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);	
  fast;
  int t;
  cin>>t;
  FOR(T,1,t)
  {
  	int n,m,k;
  	cin>>n>>m>>k;

  	FOR(i,1,n)
  	FOR(j,1,n)
  	weight[i][j]=((i==j)?0:INF);

  	FOR(i,1,m)
  	{
  		int a,b,g;
  		cin>>a>>b>>g;
  		weight[a][b]=min(weight[a][b],(ll)g);
  		weight[b][a]=weight[a][b];
  	}
  	
  	FloydWarshall(n);
  	
  	FOR(i,1,k)
  	cin>>s[i]>>d[i];
	
	FOR(i,1,k)
	dps[i][0]=dps[i][1]=dpd[i][1]=dpd[i][2]=INF;  	

	dps[1][0]=iweight[1][s[1]];
	ll ans=solve(2,k,1);
    if(ans>=INF)
    	cout<<"Case #"<<T<<": "<<-1<<endl;
    else
    	cout<<"Case #"<<T<<": "<<ans<<endl;
  }

  return 0;
}