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
	int l1,l2,l3,b1,b2,b3;
	cin>>l1>>b1;
	cin>>l2>>b2;
	cin>>l3>>b3;
	
	int flag=0;
	
	if(l2+l3<=l1 && b2<=b1 && b3<=b1)
	flag=1;
	
	else if(l2+l3<=b1 && b2<=l1 && b3<=l1)
	flag=1;
	
	else if(l2+b3<=l1 && b2<=b1 && l3<=b1)
	flag=1;
	
	else if(l2+b3<=b1 && b2<=l1 && l3<=l1)
	flag=1;
	
	else if(b2+b3<=l1 && l2<=b1 && l3<=b1)
	flag=1;
	
	else if(b2+b3<=b1 && l2<=l1 && l3<=l1)
	flag=1;
	
	else if(b2+l3<=l1 && l2<=b1 && b3<=b1)
	flag=1;
	
	else if(b2+l3<=b1 && l2<=l1 && b3<=l1)
	flag=1;
	
	if(flag)
	cout<<"YES";
	else
	cout<<"NO";
	
	return 0;
}
