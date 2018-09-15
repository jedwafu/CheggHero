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
string small(string s1)
{
	if(s1.length()%2==1)
	return s1;
	
    string sm1=small(s1.substr(0,s1.length()/2));
    string sm2=small(s1.substr(s1.length()/2,s1.length()));
    
    if(sm1<sm2)
    return sm1+sm2;
    else
    return sm2+sm1;
}

int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	
	string sm1=small(s1);
	string sm2=small(s2);
	
	if(sm1==sm2)
	cout<<"YES";
	else
	cout<<"NO";
	
	return 0;
}
