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
map<ll,ll> answers;
ll F(ll n)
{
	return (n*(n-1))/2;
}

ll R(ll n){
    if(n==1) return 0;
    
	if(answers[n]) return answers[n];
    
	ll sum = F(n);
    ll i=2;
    ll sum2=0;
    for(i=2;i<=n;i++)
    {
    	 sum2+=R(n/i);
	}
	
	return sum-sum2;
}

int main()
{
	int t;
	ll n,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d %I64d",&n,&d);
		printf("%I64d\n",1+R(n/d));
	}
	return 0;
}
