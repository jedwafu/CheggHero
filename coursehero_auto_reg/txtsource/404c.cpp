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

si nums[100010];
int attached[100010];
int main()
{
	int n,k;
	cin>>n>>k;
	memset(attached,0,n+1);
	
	loop(i,1,n)
	{
		int temp;
		cin>>temp;
		nums[temp].insert(i);
	}
	
	if(sz(nums[0])!=1 || sz(nums[1])>k)
	{
		cout<<-1;
		return 0;
	}
	
	ll prev=sz(nums[1]);
	
	loop(i,2,n-1)
	{
		if((ll)sz(nums[i])>(k-1)*prev)
		{
			cout<<-1;
			return 0;
		}
		
		prev=sz(nums[i]);
	}
	
	cout<<n-1<<endl;
	
	loop(i,1,n-1)
	{
		typeof(nums[i-1].begin()) it2=nums[i-1].begin();
		
		if(nums[i].empty())
		return 0;
		
		tr(nums[i],it)
		{
			if(attached[*it2]==k)
			it2++;
			
			cout<<*it2<<" "<<*it<<endl;
			attached[*it2]++;
			attached[*it]++;
		}
	}
	return 0;
}
