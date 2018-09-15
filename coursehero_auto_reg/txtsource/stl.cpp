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

long long arr1[100010];
long long arr2[100010];
int main()
{
	int na,nb,k,m;
	cin>>na>>nb;
	cin>>k>>m;
	for(int i=0;i<na;i++)
	{
		cin>>arr1[i];
	}
	for(int i=0;i<nb;i++)
	{
		cin>>arr2[i];
	}
	if(arr1[k-1]<arr2[nb-m])
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
