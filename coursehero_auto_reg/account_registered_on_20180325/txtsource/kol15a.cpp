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
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	 ll sums=0;
     cin>>s;
     int len=s.length();
     for(int i=0;i<len;i++)
     {
     	if(s[i]>='0' and s[i]<='9')
        sums+=s[i]-'0';
     } 
     cout<<sums<<endl;
  }
  return 0;
}