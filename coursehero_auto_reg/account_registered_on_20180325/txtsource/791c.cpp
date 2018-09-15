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

string names[100];
char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
  fast;
  int n,k;
  cin>>n>>k;

  FOR(i,1,26)
  {
  	names[i]='A';
  	names[i]+=alphabet[i-1];
  }
  FOR(i,27,52)
  {
  	names[i]='B';
  	names[i]+=alphabet[i-27];
  }
  FOR(i,1,n-k+1)
  {
  	string s;
  	cin>>s;
  	if(s=="NO")
  	names[i+k-1]=names[i];
  }

  FOR(i,1,n)
  cout<<names[i]<<" ";
  cout<<endl;
  return 0;
}