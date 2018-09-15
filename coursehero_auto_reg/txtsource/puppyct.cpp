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

map<ll,int> pos;
map<ll,int> neg;
int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		pos.clear();
		neg.clear();
		cin>>n>>k;
		loop(i,1,k)
		{
			ll x,y;
			cin>>x>>y;
			pos[x+y]=1;
			neg[x-y]=1;
		}
		ll count=0;
		loop(i,1,n)
		{
			loop(j,1,n)
			{
				if(pos[i+j] or neg[i-j])
				count++;
			}
		}
		cout<<n*n-count<<endl;	
	}
   return 0;
}
