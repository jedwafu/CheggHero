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

map<long long int,long long int> counts1;
map<long long int,long long int> counts2;
long long int arr[200010];

int main()
{
	int n,k;
	cin>>n>>k;
	
	counts1.clear();
	counts2.clear();
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		counts1[arr[i]]++;
	}
	
	long long ans=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]%k==0)
		{
			if(arr[i]==arr[i]*k)
		    ans+=counts2[arr[i]/k]*(counts1[arr[i]*k]-counts2[arr[i]*k]-1);
		    else
		    ans+=counts2[arr[i]/k]*(counts1[arr[i]*k]-counts2[arr[i]*k]);
	    }
	    
		counts2[arr[i]]++;
	}

	
	cout<<ans;
	return 0;
	
}
