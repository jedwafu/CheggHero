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

int main()
{
	int x,k1,l1,m,l2,k2;
	cin>>x>>k1>>l1>>m>>l2>>k2;
	if(k1<k2)
	{
		int temp=k1;
		k1=k2;
		k2=temp;
	}
	if(l1<l2)
	{
		int temp=l1;
		l1=l2;
		l2=temp;
	}
	
	ll ans=2*k2*x + k2*k2;
	ans+=2*l2*m + l2*l2;
	ans+=2*(x+k2)*(k1-k2);
	cout<<ans;
}
