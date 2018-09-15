#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e3+10; 

int closest[N][N][4];
char arr[N][N];
ii pos[30];
int route[2][100010];
vector<char> ans;

int main(){
  fast;
  int n,m;
  FOR(i,0,29)
  pos[i]=mp(0,0);

  cin>>n>>m;

  FOR(i,1,n)
  FOR(j,1,m)
  {
  	cin>>arr[i][j];
  	if(arr[i][j]!='#' and arr[i][j]!='.')
  	pos[arr[i][j]-'A']=mp(i,j);	
  }

  FOR(j,1,m)
  {
  	int last=0;
  	FOR(i,1,n)
  	{
  		if(arr[i][j]=='#')
  			last=i;
  		closest[i][j][0]=last;
  	}
  }

  FOR(j,1,m)
  {
  	int last=n+1;
  	NFOR(i,n,1)
  	{
  		if(arr[i][j]=='#')
  			last=i;
  		closest[i][j][1]=last;
  	}
  }

  FOR(i,1,n)
  {
  	int last=0;
  	FOR(j,1,m)
  	{
  		if(arr[i][j]=='#')
  			last=j;
  		closest[i][j][2]=last;
  	}
  }

  FOR(i,1,n)
  {
  	int last=m+1;
  	NFOR(j,m,1)
  	{
  		if(arr[i][j]=='#')
  			last=j;
  		closest[i][j][3]=last;
  	}
  }

  int k;
  cin>>k;

  FOR(i,1,k)
  {
  	char c;
  	int num;
  	cin>>c>>num;
  	if(c=='N')
  	route[0][i]=0;
  	if(c=='S')
  	route[0][i]=1;
  	if(c=='E')
  	route[0][i]=3;
  	if(c=='W')
  	route[0][i]=2;
  	route[1][i]=num;
  }

  FOR(i,0,25)
  {
  	if(pos[i].F==0)
  		continue;
  	ii cur=pos[i];
  	bool flag=true;
  	FOR(j,1,k)
  	{
  		//cout<<cur.F<<" "<<cur.S<<endl;
  		if(route[0][j]==0)
  		{
  			if(closest[cur.F][cur.S][0]<cur.F-route[1][j])
  				cur.F-=route[1][j];
  			else
  			{
  				//cout<<"breaking because "<<route[0][j]<<" "<<route[1][j]<<endl;
  				flag=false;
  				break;
  			}
  		}

  		if(route[0][j]==1)
  		{
  			if(closest[cur.F][cur.S][1]>cur.F+route[1][j])
  				cur.F+=route[1][j];
  			else
  			{
  				//cout<<"breaking because "<<route[0][j]<<" "<<route[1][j]<<endl;
  				flag=false;
  				break;
  			}
  		}

  		if(route[0][j]==2)
  		{
  			if(closest[cur.F][cur.S][2]<cur.S-route[1][j])
  				cur.S-=route[1][j];
  			else
  			{
  				//cout<<"breaking because "<<route[0][j]<<" "<<route[1][j]<<endl;
  				flag=false;
  				break;
  			}
  		}		

  		if(route[0][j]==3)
  		{
  			if(closest[cur.F][cur.S][3]>cur.S+route[1][j])
  				cur.S+=route[1][j];
  			else
  			{
  				//cout<<"breaking because "<<route[0][j]<<" "<<route[1][j]<<endl;
  				flag=false;
  				break;
  			}
  		}	
  	}
  	if(flag)
  		ans.pb(arr[pos[i].F][pos[i].S]);
  }

  sort(ans.begin(),ans.end());

  if(sz(ans)==0)
  	cout<<"no solution"<<endl;
  else
  	FOR(i,0,sz(ans)-1)
  cout<<ans[i];

  return 0;
}