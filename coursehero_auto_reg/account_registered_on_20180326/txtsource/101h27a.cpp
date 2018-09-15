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

set<ii> bd;
int main()
{
	int bea[5];
	int dif[5];
	int ans=1;
	loop(i,0,4)
	{
		cin>>bea[i]>>dif[i];
		bd.insert(mp(bea[i],dif[i]));
	}
	int count=0;
	tr(bd,it)
	{
		count++;
		if(count==5)
		break;
		
		typeof(it) it2=it;
		it2++;
		if(it->F==it2->F)
		{
		  ans=0;
		  break;
	    }
		
		if(it->S>=it2->S)
		{
			ans=0;
			break;
		}
	}
	
	cout<<ans;
	
	return 0;
	
}
