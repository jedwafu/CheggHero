#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

map<char,bool> done;
int main(){
  fast;
  string s,t;
  cin>>s>>t;
  set<pair<char,char> > ans;
  ans.clear();
  done.clear();
  for(int i=0;i<sz(t);i++)
  {
      if(s[i]!=t[i])
      {
        if(done[s[i]] and (!done[t[i]]))
        {
          cout<<-1;
          return 0;
        }
        if(done[t[i]] and (!done[s[i]]))
        {
          cout<<-1;
          return 0;
        }
        
      	for(int j=0;j<sz(s);j++)
      	{
      		if(s[j]==s[i])
      		{
               if(t[j]!=t[i])
               {
               	cout<<-1;
               	return 0;
               }
      		}
          if(s[j]==t[i])
          {
            if(t[j]!=s[i])
            {
              cout<<-1;
              return 0;
            }
          }
      	}
      	
        done[t[i]]=true;
        done[s[i]]=true;
        if(t[i]<s[i])
      	ans.insert(mp(t[i],s[i]));
      	else
        ans.insert(mp(s[i],t[i]));
      	
      }
  }

  cout<<sz(ans)<<endl;
  
  set<pair<char,char> >::iterator it;
  for (it = ans.begin(); it != ans.end(); it++) {
      cout << it->F<<" "<<it->S<<endl;
  }

    return 0;
}