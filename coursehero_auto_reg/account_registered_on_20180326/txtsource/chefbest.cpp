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

int ans[N];
int s[N];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  { 
      fill(ans,0);
      int count=0;
      int n;
      cin>>n;
      
      FOR(i,0,n-1)
      cin>>s[i];

      fill(ans,0);
      
      bool flag=false;
      FOR(i,0,n-1)
      {
      	if(s[i]==1 and !flag)
      		count++;

      	if(s[i]==0)
      		flag=true;
         
         if(!flag)
         	continue;
         
         if(s[i]==1)
         {
         	int final=count;
         	count++;
         	int cur=i;
         	if(final==0 or cur-final>ans[final-1])
         		ans[final]=cur-final;
         	else
         		ans[final]=ans[final-1]+1;
          }

       }
      cout<<ans[count-1]<<endl;
  }
  return 0;
}