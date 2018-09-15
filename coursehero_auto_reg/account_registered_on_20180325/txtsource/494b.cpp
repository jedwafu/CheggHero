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
const int N = 2e5+10; 

ll dp[N];
ll temp[N];
ll temp2[N];
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

int main()
{
  fast;
  string s;
  string t;
  cin>>s;
  cin>>t;
  string f=t+'0'+s;
  int sz1=sz(s);
  int sz2=sz(t);

  int* z=z_values(f);
  dp[sz1+sz2+1]=0;
  temp[sz1+sz2+1]=0;
  temp2[sz1+sz1+1]=0;
  NFOR(i,sz1+sz2,sz2+1)
  {
       if(z[i]==sz2)
       dp[i]=(temp2[i+sz2]%mod+(sz1-i+2)%mod)%mod;
       else
       dp[i]=dp[i+1];
       
       temp[i]=(temp[i+1]%mod+dp[i]%mod)%mod;
       temp2[i]=temp2[i+1]+temp[i];
       //cout<<i<<" "<<temp[i]<<endl;
  }
  cout<<temp[sz2+1];
  return 0;
}