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

string s;
vector<int>sizes;
int main(){
  fast;
  int n;
  cin>>n;
  cin>>s;
  sizes.clear();
  int count=0;

  int sx=0;

  FOR(i,0,n-1)
  {
  	if(s[i]=='B')
  		sx++;
  	if(s[i]=='W' and i>0 and s[i-1]=='B')
  	{
  		sizes.push_back(sx);
  		sx=0;
  	}
  	if(s[i]=='B' and  i==(n-1))
  		sizes.push_back(sx);
  }
   
  cout<<sizes.size()<<endl; 
  for(int i=0;i<sizes.size();i++)
  cout<<sizes[i]<<" ";

  return 0;
}