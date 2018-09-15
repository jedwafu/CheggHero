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
const int N = 150; 

int arr[N][10];
int curfrac[10];

int score1(int j1,int j2,int j3,int j4,int j5)
{
	int ans=0;
	ans+=500*j1;
	ans-=(500*j1*arr[1][1])/250;

	ans+=500*j2;
	ans-=(500*j2*arr[1][2])/250;

	ans+=500*j3;
	ans-=(500*j3*arr[1][3])/250;

	ans+=500*j4;
	ans-=(500*j4*arr[1][4])/250;

	ans+=500*j5;
	ans-=(500*j5*arr[1][5])/250;

	return ans;
}

int score2(int j1,int j2,int j3,int j4,int j5)
{
	int ans=0;
	ans+=500*j1;
	ans-=(500*j1*arr[2][1])/250;

	ans+=500*j2;
	ans-=(500*j2*arr[2][2])/250;

	ans+=500*j3;
	ans-=(500*j3*arr[2][3])/250;

	ans+=500*j4;
	ans-=(500*j4*arr[2][4])/250;

	ans+=500*j5;
	ans-=(500*j5*arr[2][5])/250;

	return ans;
}


bool check(ll a,ll b,ll c)
{
	return (a*b >= c);
}

int req(bool left,int p,int x)
{
	int y=120;
	int q;

	double xx=x;
	double yy=y;
	

	if(p==1)
	{
		if((x/y)>0.5 and (x/y)<=1)
			return 0;
	}

	if(p==1 and left)
	{
		p=1;
		q=2;
	}

	if(p==1 and !left)
	{
		p=1;
		q=1;
	}

	if(p==2)
	{
		if((x/y)>0.25 and (x/y)<=0.5)
			return 0;
	}

	if(p==2 and left)
	{
		p=1;
		q=4;
	}
	if(p==2 and !left)
	{
		p=1;
		q=2;
	}

	if(p==3)
	{
		if((x/y)>0.125 and (x/y)<=0.25)
			return 0;
	}

	if(p==3 and left)
	{
		p=1;
		q=8;
	}
	if(p==3 and !left)
	{
		p=1;
		q=4;
	}

	if(p==4)
	{
		if((x/y)>0.0625 and (x/y)<=0.125)
			return 0;
	}

	if(p==4 and left)
	{
		p=1;
		q=16;
	}
	if(p==4 and !left)
	{
		p=1;
		q=8;
	}

	if(p==5)
	{
		if((x/y)>0.03125 and (x/y)<=0.0625)
			return 0;
	}

	if(p==5 and left)
	{
		p=1;
		q=32;
	}
	
	if(p==5 and !left)
	{
		p=1;
		q=16;
	}

	if(p==6)
	{
		if((x/y)>0 and (x/y)<=0.03125)
			return 0;
	}

	if(p==6 and left)
	{
		p=0;
		q=1;
	}
	if(p==6 and !left)
	{
		p=1;
		q=32;
	}

	



	if((p==0 and x==0) or(p==q and x==y))
  	{
  		return 0;
  	}
  	if(p==0 and x!=0)
  	{
  		return -2;
  	}
  	if(p==q and x<y)
  	{
  		return -2;
  	}

  	if((x/__gcd(x,y))==p and (y/__gcd(x,y))==q)
  	{
  		return -2;
  	}

  	ll ans=0;

  	ll l=1;
  	ll r=INF;
 	while(r-l>1)
 	{
 		ll mid=(l+r)/2;
 		if(check(mid,p,x))
 		r=mid;
 		else
 		l=mid;
 	}
 	if(check(l,p,x))
 	ans=max(ans,l);
 	else if(check(r,p,x))
 	ans=max(ans,r);
 	else
 	{
 		return -2;
 	}

 	 l=1;
  	 r=INF;
 	while(r-l>1)
 	{
 		ll mid=(l+r)/2;
 		if(check(mid,q,y))
 		r=mid;
 		else
 		l=mid;
 	}
 	if(check(l,q,y))
 	ans=max(ans,l);
 	else if(check(r,q,y))
 	ans=max(ans,r);
 	else
 	{
 		return -2;
 	}

 	 l=1;
  	 r=INF;
 	while(r-l>1)
 	{
 		ll mid=(l+r)/2;
 		if(check(mid,q-p,y-x))
 		r=mid;
 		else
 		l=mid;
 	}
 	if(check(l,q-p,y-x))
 	ans=max(ans,l);
 	else if(check(r,q-p,y-x))
 	ans=max(ans,r);
 	else
 	{
 		return -2;
 	}

 	//cout<<ans<<endl;
 	double pp=p;
	double qq=q;
	xx=x;
	yy=y;

 	if(ans)
 	{
 		ans=ans*q-y;
 		if(left and (x/y)>(p/q))
 		{
 			ans--;
 		}
 		else if(left and (x/y)<=(p/q))
 		{
 			ans++;
 		}
 		return ans;
 	}
 	else
 	return 0;
}

int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4]>>arr[i][5];
  
  fill(curfrac,0);
  

  int ans=mod+1;

  FOR(i,1,n)
  {
  	FOR(j,1,5)
  	{
  		if(arr[i][j]!=-1)
  		{
  			curfrac[j]++;
  		}
  	}
  }

  FOR(j1,1,6)
  FOR(j2,1,6)
  FOR(j3,1,6)
  FOR(j4,1,6)
  FOR(j5,1,6)
  {
  	int temp=0;
  	
  	if(req(1,j1,curfrac[1])==-2 or (req(0,j2,curfrac[2])==-2 and req(1,j2,curfrac[2])==-2) or (req(0,j3,curfrac[3])==-2 and req(1,j3,curfrac[3])==-2) or (req(0,j4,curfrac[4])==-2 and req(4,j4,curfrac[4])==-2) or req(0,j5,curfrac[5])==-2)
  	continue;
  	
  	temp=min(req(1,j1,curfrac[1]),req(1,j1,curfrac[1]));
	temp=min(temp,min(req(1,j2,curfrac[2]),req(0,j2,curfrac[2])));
	temp=min(temp,min(req(1,j3,curfrac[3]),req(0,j3,curfrac[3])));
	temp=min(temp,min(req(1,j4,curfrac[4]),req(0,j4,curfrac[4])));
	temp=min(temp,min(req(0,j5,curfrac[5]),req(0,j5,curfrac[5])));

	if(score1(j1,j2,j3,j4,j5)>score2(j1,j2,j3,j4,j5))
	{
		ans=min(ans,temp);
	}  	
  }

  if(ans==(mod+1))
  	cout<<-1<<endl;
  else
  	cout<<ans<<endl;

  return 0;
}