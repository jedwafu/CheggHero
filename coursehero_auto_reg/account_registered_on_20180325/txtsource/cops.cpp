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
	int t,m,x,y;
	bool arr[101];
	

	
	cin>>t;
	while(t--)
	{
		cin>>m>>x>>y;
		int range =x*y;
	  	memset(arr,true,sizeof(arr));
	  	
	    loop(i,0,m-1)
	    {
	    	int temp;
	    	cin>>temp;
	    	
	    	int mini=max(1,temp-range);
	    	int maxi=min(100,temp+range);
	    	
			loop(j,mini,maxi)
	    	{
	    		arr[j]=false;
			}
		}
		
		int count=0;
		loop(i,1,100)
		{
			if(arr[i]==true)
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
