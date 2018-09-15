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

vector<string> s(110);
string pass;
vector<int> freq(110,0);
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  	cin>>s[i];

  cin>>pass;
  int len;
  
  for(int i=0;i<n;i++)
  {
  	freq[s[i].length()]++;
  	if(!s[i].compare(pass))
     len=s[i].length();
  }
  
  int ans1=0,ans2=0;
  for(int i=0;i<len;i++)
  {
     ans1+=freq[i];
  }
  ans2=ans1;
  ans1+= 5*(ans1/k);
  int mini=ans1+1;
  ans2+=freq[len]-1;
  ans2+=5*(ans2/k);
  int maxi=ans2+1;
  cout<<mini<<" "<<maxi<<endl;
  return 0;
}