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

map<string,int> freq;
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  int cnt=0;
  FOR(i,1,n)
  {
  	string s;
  	cin>>s;
  	freq[s]++;
  	if(freq[s]==2)
  		cnt++;
  }
  FOR(i,1,m)
  {
  	string s;
  	cin>>s;
  	freq[s]++;
  	if(freq[s]==2)
  		cnt++;
  }

  int x=n-cnt;
  int y=m-cnt;

  if(cnt%2)
  {
  	if(y>x)
  		cout<<"NO";
  	else
  		cout<<"YES";
  }
  else
  {
  	if(x>y)
  		cout<<"YES";
  	else
  		cout<<"NO";
  }
  return 0;
}