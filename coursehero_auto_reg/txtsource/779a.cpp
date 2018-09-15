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

int main(){
  fast;
  ll n,k;
  cin>>n>>k;
  ll temp=n;
  int zero=0;
  int dig=0;

  if(n==0)
  {
  	cout<<0;
  	return 0;
  }

  while(temp>0)
  {
  	int rem=(temp%10);
  	temp=temp/10;
  	if(rem==0)
  		zero++;
  	dig++;
  	if(zero==k)
  	{
  		cout<<dig-zero;
  		return 0;
  	}
  }

  cout<<dig-1;
  return 0;
}