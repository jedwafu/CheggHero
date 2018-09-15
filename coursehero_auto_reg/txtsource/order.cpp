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

long long buy[100010];
long long sell[100010];
vector<int> arr;

int main()
{
	for(int i=0;i<100010;i++)
	{
		buy[i]=sell[i]=0;
	}
	
	int n,s;
	char c;
	int p,q;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
	  cin>>c>>p>>q;
	  if(c=='B')
	  buy[p]+=q;
	  else
	  sell[p]+=q;
	}
	
	int count=0;
	for(int i=0;i<=100000;i++)
	{
		if(count==s)
		break;
		
		if(sell[i]!=0)
		{
			arr.pb(i);
			count++;
		}
	}
	
	for(int i=arr.size()-1;i>=0;i--)
	{
		cout<<"S "<<arr[i]<<" "<<sell[arr[i]]<<endl;
	}
	
	count=0;
	for(int i=100000;i>=0;i--)
	{
		if(count==s)
		break;
		if(buy[i]!=0)
		{
			cout<<"B "<<i<<" "<<buy[i]<<endl;
			count++;
		}
	}
	return 0;
}
