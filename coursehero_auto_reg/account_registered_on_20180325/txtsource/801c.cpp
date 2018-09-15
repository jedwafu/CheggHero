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
double eps=0.00001;
int n;
double p;
double a[N],b[N];

bool check(double val)
{

	double denom=0;
	double num=0;
	FOR(i,1,n)
	{
		if((val-(b[i]/a[i]))>eps)
		{
			denom+=a[i];
			num+=b[i];
		}	
	}

	if(fabs(denom-0)<eps  or (denom-p)<eps)
		return true;

	else 
	{

		if (val-eps<((num)/(denom-p)))
			return true;
		else return false;
	}
}	

int main(){
  fast;
  
  cin>>n>>p;

  cout<<setprecision(12);
  cout<<fixed;

  FOR(i,1,n)
  cin>>a[i]>>b[i];

  double a=0;
  double b=1e12;

  if(check(b))
  {
  	//cout<<"here"<<endl;
  	cout<<-1<<endl;
  	return 0;
  }

  while(b-a>eps)
  {
  	double mid=(a+b)/2;
  	if(check(mid))
  		a=mid;
  	else
  		b=mid;
  }

  if(check(b))
  	cout<<b<<endl;
  else if(check(a))
  	cout<<a<<endl;

  return 0;
}