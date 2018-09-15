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

int nums[15];
string ans;
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	string s;
  	cin>>s;
  	ans="";
  	fill(nums,0);
  	for(int i=0;i<sz(s);i++)
  	nums[s[i]-'0']++;
  	
  	for(int i=65;i<=90;i++)
  	{
  		int f=i/10;
  		int s=i%10;

  		if(f==s and nums[f]>1)
  			ans+='A'-65+i;
  		if(f!=s and nums[f]>0 and nums[s]>0)
  			ans+='A'-65+i;
  	}

  	if(ans=="")
  		cout<<endl;
  	else
  		cout<<ans<<endl;
  }
  return 0;
}