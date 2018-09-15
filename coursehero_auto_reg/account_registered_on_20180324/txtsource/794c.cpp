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
const int N = 3e5+10; 

string s,t;
char ans[N];
int main(){
  fast;
  cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  int n=sz(s);
  int of=0,ob=(n+1)/2-1,igf=0,igb=n/2-1,ansf=0,ansb=n-1;
  FOR(i,1,n)
  {
  	if(i%2)
  	{
 		if(s[of]<t[igf])
 		{
 			ans[ansf]=s[of];
 			ansf++;
 			of++;
 		}
 		else
 		{
 			ans[ansb]=s[ob];
 			ansb--;
 			ob--;
 		} 		
  	}
  	else
  	{
  		if(s[of]<t[igf])
  		{
  			ans[ansf]=t[igf];
 			ansf++;
 			igf++;	
  		}
  		else
  		{
  			ans[ansb]=t[igb];
  			ansb--;
  			igb--;
  		}
  	}
  }
  ans[n]='\0';
  cout<<ans<<endl;
  return 0;
}