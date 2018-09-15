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

bool bad[27];
int trie[1126000][27];
int ans;

int main(){
  fast;
  string s,t;
  int k;
  cin>>s>>t;
  cin>>k;
  int n=sz(s);

  FOR(i,1,26)
  bad[i]=(t[i-1]=='0');
  
  int count=1;

  FOR(i,0,n-1)
  {
    int badch=0;
    int point=0;
  	FOR(j,i,n-1)
  	{
  	   if(bad[s[j]-'a'+1])
  		badch++;
       if(badch>k)
       	break;
       
       if(trie[point][s[j]-'a'+1]==0)
       {
       	ans++;
       	trie[point][s[j]-'a'+1]=count++;
       }
       point=trie[point][s[j]-'a'+1];   
  	}
  }

  cout<<ans;
  return 0;
}