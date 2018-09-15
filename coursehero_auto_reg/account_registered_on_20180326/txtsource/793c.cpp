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
double eps=1e-12;
double r[2][N];
double v[2][N];
double starts[N];
double eds[N];
int main(){
  fast;
  int n;
  cin>>n;
  cout<<setprecision(12);
  cout<<fixed;
  double x1,y1,x2,y2;
  double maxi=-1;
  double mini=INF;
  cin>>x1>>y1>>x2>>y2;
  fill(starts,-1);
  fill(eds,-1);

  FOR(i,1,n)
  {
  	cin>>r[0][i]>>r[1][i]>>v[0][i]>>v[1][i];
  }
  
  FOR(i,1,n)
  {
  	if((r[1][i]==y1 or r[1][i]==y2) and v[1][i]==0)
  	{
  		cout<<-1;
  		return 0;
  	}
  	if((r[0][i]==x1 or r[0][i]==x2) and v[0][i]==0)
  	{
  		cout<<-1;
  		return 0;
  	}

  	double tf=-1,ts=-1;
  	bool flag=false;
  	double tm=(y1-r[1][i])/v[1][i];
  	double check;
  	if(tm>-eps)
  	{ check=r[0][i]+tm*v[0][i];
  	if(check>min(x1,x2)-eps and check<max(x1,x2)+eps)
  	{
  		if(!flag)
  		{
  			tf=tm;
  			flag=true;
  		}
  		else
  		{
  			ts=tm;
  		}

  	}}

  	tm=(y2-r[1][i])/v[1][i];
  	if(tm>-eps)
  	{check=r[0][i]+tm*v[0][i];
  	if(check>min(x1,x2)-eps and check<max(x1,x2)+eps)
  	{
  		if(!flag)
  		{
  			tf=tm;
  			flag=true;
  		}
  		else
  		{
  			ts=tm;
  		}
	}}

	tm=(x1-r[0][i])/v[0][i];
	if(tm>-eps)
  	{check=r[1][i]+tm*v[1][i];
  	if(check>min(y1,y2)-eps and check<max(y1,y2)+eps)
  	{
  		if(!flag)
  		{
  			tf=tm;
  			flag=true;
  		}
  		else
  		{
  			ts=tm;
  		}
	}}

	tm=(x2-r[0][i])/v[0][i];
	if(tm>-eps)
  	{check=r[1][i]+tm*v[1][i];
  	if(check>min(y1,y2)-eps and check<max(y1,y2)+eps)
  	{
  		if(!flag)
  		{
  			tf=tm;
  			flag=true;
  		}
  		else
  		{
  			ts=tm;
  		}
	}}

	starts[i]=min(ts,tf);
	eds[i]=max(ts,tf);

	if(r[0][i]>min(x1,x2)+eps and r[0][i]<max(x2,x1)-eps and r[1][i]>min(y1,y2)+eps and r[1][i]<max(y2,y1)-eps)
	{
		starts[i]=0;
		if(ts>-eps)
			eds[i]=ts;
		else if(tf>-eps)
			eds[i]=tf;
		else
			eds[i]=1e17;
	}

	if(starts[i]<0 or eds[i]<0)
	{
		cout<<-1;
		return 0;
	}
	maxi=max(starts[i],maxi);
	mini=min(eds[i],mini);
  }

  if(maxi==mini)
  {
  	cout<<-1;
  }
  else if(maxi<mini-eps)
  {
  	cout<<maxi<<endl;
  }
  else
  	cout<<-1;
  return 0;
}