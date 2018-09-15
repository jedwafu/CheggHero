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
  string s;
  cin>>s;
  int len=s.length();
  s+='A';
  len++;
  //cout<<s<<endl;
  int prev=-1;
  int maxi=1;
  for(int i=0;i<len;i++)
  {
  	if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U' or s[i]=='Y')
    {
       maxi=max(maxi,i-prev);
       prev=i;		
    }
  }
  cout<<maxi<<endl;
  return 0;
}