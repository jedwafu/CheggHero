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
  int n;
  cin>>n;
  int mini=5000;
  bool flag=false;
  FOR(i,1,n)
  {
	int a,b;
	cin>>a>>b;
	if(a!=b)
	{
		cout<<"rated"<<endl;
		return 0;
	}	
	if(a>mini)
	{
		flag=true;
	}
	else
		mini=a;
  }

  if(flag)
  {
  	cout<<"unrated"<<endl;
  	return 0;
  }

  cout<<"maybe"<<endl;
  return 0;
}