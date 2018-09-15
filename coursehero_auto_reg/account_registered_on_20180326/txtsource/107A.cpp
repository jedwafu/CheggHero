#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define spresent(c,x) ((c).find(x) != (c).end())  // for set,map
#define present(c,x) (find(all(c),x) != (c).end())  // for vector
#define F first
#define S second
#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nloop(i,a,b) for(int i= int(a);i>=int(b);--i)

vii edges[1010];
int in_deg[1010];
set<pair<ii,int> > ans;

int main()
{
	int n,p;
	cin>>n>>p;
	memset(in_deg,0,n+1);
	
	loop(i,1,p)
	{
		int a,b,d;
		cin>>a>>b>>d;
		
		edges[a].pb(mp(b,d));
		in_deg[b]=1;
	}
	
	loop(i,1,n)
	{
		if(in_deg[i]==0)
		{
			int start=i;
			int end=i;
			int water=1e6;
			
			while(edges[end].empty()==false)
			{
				water=min(water,edges[end][0].S);
				end=edges[end][0].F;
			}
			
			if(end!=start)
			{
				ans.insert(mp(mp(start,end),water));
			}
		}
	}
	
	cout<<ans.size()<<endl;
	
	tr(ans,it)
	cout<<it->F.F<<" "<<it->F.S<<" "<<it->S<<endl;
	
	return 0;	
}
