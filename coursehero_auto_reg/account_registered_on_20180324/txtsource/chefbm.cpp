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

vi rows[100010];
map<int,int> query;
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	loop(i,1,p)
	{
		int a,b;
		cin>>a>>b;
		rows[a].pb(b);
	}
	
	loop(i,1,n)
	{
		int ans=m-1;
		
		if(rows[i].empty()==false)
		{
			query.clear();
			tr(rows[i],it)
			{
				query[*it]++;
			}
			
			tr(query,it)
			{
				if(it->F==m) break;
				
				if(query[it->F]-query[it->F+1]>1)
				{
				ans=-1;
				break;
			    }
			    
			    if(!query[it->F+1])
				query.erase(it->F+1);   
			}
			
			if(ans!=-1)
			ans+=query[m]-query[1];
	
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
