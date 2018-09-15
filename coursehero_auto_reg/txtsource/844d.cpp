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
const int N = 50010; 

int a[N];
int main(){
  fast;
  int n,start;
  ll x;
  cin>>n>>start>>x;
  srand(time(NULL));

  FOR(i,1,n)
  a[i]=i;

  random_shuffle(a+1,a+n+1);
  a[1]=start;

  ll val=-1;
  int index=-1;
  ll v1,n1;
  FOR(i,1,min(n,1000))
  {
  	
  	cout<<"? "<<a[i]<<endl;
  	fflush(stdout);
  	cin>>v1>>n1;
  	if(v1>x)
  		continue;
  	else if(v1==x)
  	{
  		cout<<"! "<<v1<<endl;
  		fflush(stdout);
  		return 0;
  	}
  	else
  	{
  		if(v1>val)
  		{
  			val=v1;
  			index=a[i];
  		}
  	}
  }

  if(val==-1)
  {
  	cout<<"? "<<start<<endl;
  	fflush(stdout);
  	cin>>v1>>n1;
  	cout<<"! "<<v1<<endl;
  	fflush(stdout);
  	return 0;
  }

  int steps=min(n,1000);

  while(steps<2000)
  {
  	cout<<"? "<<index<<endl;
  	fflush(stdout);
  	cin>>v1>>n1;
  	if(v1>=x)
  	{
  		cout<<"! "<<v1<<endl;
  		fflush(stdout);
  		return 0;
  	}
  	if(n1==-1)
  	{
  		cout<<"! "<<-1<<endl;
  		fflush(stdout);
  		return 0;
  	}
  	index=n1;
  	steps++;
  }

  cout<<"! "<<-1<<endl;
  fflush(stdout);
  return 0;
}