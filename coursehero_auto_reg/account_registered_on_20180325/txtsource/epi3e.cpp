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

set<string> A;
set<string> B;
map<string,int> parent;
map<string,bool> visited;
map<string, set<string> > edges;
set<string> ans;
void DFS(string s)
{ 
	visited[s]=1;
	parent[s]=1;
    for(set<string>::const_iterator it = edges[s].begin(); it != edges[s].end(); it++)
    {
         if(visited[*it]!=1)
         DFS(*it);       
    }

return;
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	A.clear();
  	B.clear();
  	parent.clear();
  	visited.clear();
  	edges.clear();
  	ans.clear();

  	int u,v,m;
  	cin>>u>>v>>m;
    
    FOR(i,0,u-1)
    {
    	string s;
    	cin>>s;
    	A.insert(s);
    	parent[s]=1;
    }
    FOR(i,0,v-1)
    {
    	string s;
    	cin>>s;
    	B.insert(s);
    	if(parent[s]!=1)
        parent[s]=0;

    }
    FOR(i,0,m-1)
    {
      string s1,s2;
      cin>>s1>>s2;
      edges[s1].insert(s2);
    }
    
    for(set<string>::const_iterator it = A.begin(); it != A.end(); it++)     
    {
    	if(visited[*it]!=1)
    	{
    		DFS(*it);
    	}
    }

    for(set<string>::const_iterator it = B.begin(); it != B.end(); it++)     
    {
    	if(parent[*it]==1)
    	   ans.insert(*it); 		    	
    }

    for(set<string>::const_iterator it = ans.begin(); it != ans.end(); it++)     
    cout<<*it<<" ";    	
    
    cout<<endl;
  }

  return 0;
}