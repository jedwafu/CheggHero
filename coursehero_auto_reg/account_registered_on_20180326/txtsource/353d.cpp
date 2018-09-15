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
const int N = 1e6+10; 

int ans[N];

int main(){
  fast;
  string s;
  int count=0;
  cin>>s;
  fill(ans,0);
  bool flag=false;
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]=='F' and !flag)
  		count++;

  	if(s[i]=='M')
  		flag=true;
     
     if(!flag)
     	continue;
     
     if(s[i]=='F')
     {
     	int final=count;
     	count++;
     	int cur=i;
     	if(final==0 or cur-final>ans[final-1])
     		ans[final]=cur-final;
     	else
     		ans[final]=ans[final-1]+1;

     	//cout<<final<<" "<<ans[final]<<endl;
     }

  }
  cout<<ans[count-1];
  return 0;
}