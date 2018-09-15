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

map<string,int> word;
vector<int> C(N);
vector<int> opp(N);
int find(int x) { return (C[x] == x) ? x : C[x] = find(C[x]); }
void merge(int x, int y) { C[find(x)] = find(y); }

int main(){
  fast;
  int n,m,q;
  cin>>n>>m>>q;
  FOR(i,1,n)
  {
  	C[i]=i;
  	opp[i]=0;
  	string s;
  	cin>>s;
  	word[s]=i;
  }

  FOR(i,1,m)
  {
  	string s1,s2;
  	int t;
  	cin>>t;
  	cin>>s1>>s2;
  	if(t==1)
  	{
  		if(C[word[s1]]==opp[word[s2]] or C[word[s2]]==opp[word[s1]])
  		{
  			cout<<"NO"<<endl;
  			continue;
  		}
  		else
  		{
  			cout<<"YES"<<endl;
  			merge(C[word[s1]],C[word[s2]]);
  			merge(C[word[s2]],C[word[s1]]);
  			opp[C[word[s1]]]=opp[C[word[s2]]];
  		}
  	}
  	if(t==2)
  	{
  		if(C[word[s1]]==C[word[s2]])
  			{
  				cout<<"NO"<<endl;
  				continue;
  			}
  		else
  		{
  			cout<<"YES"<<endl;
  			if(opp[C[word[s1]]]!=0)
  			{
  				merge(opp[C[word[s1]]],C[word[s2]]);
  				merge(C[word[s2]],opp[C[word[s1]]]);
  			}
  			if(opp[C[word[s2]]]!=0)
  			{
  				merge(opp[C[word[s2]]],C[word[s1]]);
  				merge(C[word[s1]],opp[C[word[s2]]]);
  			}

  			opp[C[word[s1]]]=C[word[s2]];
  			opp[C[word[s2]]]=C[word[s1]];

  		}
  	}
  }

  FOR(i,1,q)
  {
  	string s1,s2;
  	cin>>s1>>s2;
  	if(C[word[s1]]==C[word[s2]])
  		cout<<1<<endl;
  	else if(C[word[s1]]==opp[C[word[s2]]] or C[word[s2]]==opp[C[word[s1]]])
  		cout<<2<<endl;
  	else
  		cout<<3<<endl;
  }
  return 0;
}