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

int* z_values(const string &s) {
    int n = sz(s);
    int* z = new int[n];
    int l = 0, r = 0;
    z[0] = n;
    FOR(i,1,n-1) {
        z[i] = 0;
        if (i > r) {
            l = r = i;
            while (r < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--;
        } else if (z[i - l] < r - i + 1) z[i] = z[i - l];
        else {
            l = i;
            while (r < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--; } }
    return z;
}


int main(){
  fast;
  string s;
  cin>>s;
  int len=sz(s);
  int* z=z_values(s);
  int ans=0;
  int maxi=0;
  FOR(i,1,len-1)
  {
  	if(z[i]==len-i and maxi>=len-i)
  	{
  	    ans=len-i;
  	    break;
  	}
  	maxi=max(maxi,z[i]);
  }
  
  if(ans)
  cout<<s.substr(0,ans);
  else
  cout<<"Just a legend";
  
  return 0;
}