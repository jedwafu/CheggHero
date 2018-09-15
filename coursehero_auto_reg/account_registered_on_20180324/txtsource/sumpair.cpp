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

int arr[100010];
int main()
{
	int t,n,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		loop(i,0,n-1)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		ll sum=0;
		nloop(i,n-1,1)
		{
			if((arr[i]-arr[i-1])<d)
			{
				sum+=arr[i]+arr[i-1];
				i--;
			}
		}
		cout<<sum<<endl;
    }
    return 0;
}
