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

int st[1000010];
int ed[1000010];
long long int rows[1000010];

int main()
{
	int t;
	long long int n,h;
	scanf("%d",&t);
	
	while(t--)
	{
	    
		scanf("%lld %lld",&n,&h);
		
		for(int i=0;i<n;i++)
		{
			st[i]=ed[i]=rows[i]=0;
		}
		
		for(int i=0;i<n;i++)
		{
			int li,hi;
			scanf("%d %d",&li,&hi);
		    st[li]++;
		    ed[hi]++;
		}
		
		int starts=0;
		int ends=0;
		
		for(int i=0;i<n;i++)
		{
		   starts+=st[i];
		   rows[i]=starts-ends;
		   ends+=ed[i];
		}
		
		long long int ans=0,temp=0;
		
		for(int i=0;i<h;i++)
		{
			ans+=rows[i];
		}
		
		temp=ans;
		
		for(int i=h;i<n;i++)
		{
		    temp=temp-rows[i-h]+rows[i];
			ans=max(ans,temp);
		}
		
		cout<<n*h-ans<<endl;	
	}
	return 0;
}
