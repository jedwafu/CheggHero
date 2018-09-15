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

map<string, set<string> > M;
map<string, int> uses;

int bowl(string s)
{
	if(uses[s]!=0)
		return uses[s];
    
    string temp=s;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	if(s.compare(temp)==0)
		return 0;
    
    //cout<<s<<endl;
	int free,used;
    free=used=0;
	vector<int> v;
	v.clear();
	for(set<string>::const_iterator it = M[s].begin(); it != M[s].end(); it++)
    {
    	uses[*it]=bowl(*it);
    	v.pb(uses[*it]);
    }
    
    sort(v.begin(),v.end());
    for(int i=sz(v)-1;i>=0;i--)
    {
    	if(v[i]==0)
    		continue;
    	
    	if(v[i]<=free)
    	{
    		free=max(0,free-1);
    	}
    	else
    	{
    		used+=v[i]-free;
    		free=v[i]-1;
    	}
    }

    uses[s]=used+(!(free>0));
    return uses[s];
}

int main(){
  fast;
  int n,m;
  cin>>n;
  string rec;
  FOR(i,0,n-1)
  {
  	string s,s2;
  	cin>>s;
  	if(i==0)
  	rec=s;
  	cin>>m;
  	FOR(j,0,m-1)
  	{
  		cin>>s2;
  		M[s].insert(s2);
  	}
  }  
    
  cout<<bowl(rec);
  
  return 0;
}