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
int p,x,y;
bool check(int n)
{
	int i=n/50;
	i=i%475;
	if(i<0)
		i+=475;

	FOR(k,1,25)
	{
		i=(i*96+42)%475;
		if(i<0)
			i+=475;
		if(26+i==p)
			return true;
	}
	return false;
}

int howmuch(int n)
{
	if(n<=x)
		return 0;

	n=n-x;
	if(n%100)
		return (n/100)+1;
	else
		return n/100;
}

int main(){
  fast;
  
  cin>>p>>x>>y;
  int n=x;
  
  while(n>=y)
  {
  	if(check(n))
  	{
  		cout<<howmuch(n);
  		return 0;
  	}
  	n=n-50;
  }

  n=x;
  while(true)
  {
  	if(check(n))
  	{
  		cout<<howmuch(n);
  		return 0;
  	}
  	n=n+50;
  }

  return 0;
}