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

string s;
int trie[N][30];
bool mns[N][30];
bool pls[N][30];
bool eds[N];
vector<string> ans;
int last=2;
string test="abcdefghijklmnopqrstuvwxyz";
void insert(string s,int sn)
{
	int cur=1;
	FOR(i,0,sz(s)-1)
	{
		if(trie[cur][s[i]-'a'])
		{
			if(sn==1)
			pls[cur][s[i]-'a']=1;
			if(sn==0)
			mns[cur][s[i]-'a']=1;

			//cout<<"inserted "<<s[i]<<" at "<<trie[cur][s[i]-'a']<<endl;
			cur=trie[cur][s[i]-'a'];
		}
		else
		{
			trie[cur][s[i]-'a']=last;
			if(sn==1)
			pls[cur][s[i]-'a']=1;
			if(sn==0)
			mns[cur][s[i]-'a']=1;

			//cout<<"inserted "<<s[i]<<" at "<<trie[cur][s[i]-'a']<<endl;
			cur=last;
			last++;
		}

		if(i==sz(s)-1)
		{
			if(sn==0)
			eds[cur]=1;
			//cout<<"ending  at "<<cur<<endl;
		}
	}

}

bool dfs(int cur,string s,bool f)
{
	bool done=false;

	if(eds[cur] and mns[cur] and pls[cur])
		{
			//cout<<"oops at "<<cur<<endl;
			return false;
		}

	FOR(i,0,25)
	{
		if(trie[cur][i])
		{
			if(mns[cur][i])
			{	
				if(pls[cur][i])
				{
					done=dfs(trie[cur][i],s+test.substr(i,1),1);
					if(!done)
					return false;
				}
				else
				{
					ans.pb(s+test.substr(i,1));
					done=true;
				}
			}
		}
	}

	if(f and !done)
		return false;

	return true;
}

int main(){
  fast;
  
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin>>n;
  fill(trie,0);
  fill(mns,0);
  fill(pls,0);
  fill(eds,0);

  FOR(i,1,n)
  {
  	char ch;
  	cin>>ch;
  
  	cin>>s;
  	insert(s,ch=='+');
  }

  string emp="";
  bool val=dfs(1,emp,0);

  sort(ans.begin(),ans.end());
  if(!val)
  {
  	cout<<-1;
  	return 0;
  }

  cout<<sz(ans)<<endl;
  FOR(i,0,sz(ans)-1)
  {
  	cout<<ans[i]<<endl;
  }
  return 0;
}