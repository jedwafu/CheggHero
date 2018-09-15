#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e6+10; 

int k;
string s;
int nearest[N];
bool check(int w)
{
	int lines=0;
	int cur=0;
	int newcur=0;

	while(true)
	{
		if(cur+w<sz(s) and s[cur+w-1]=='-')
		{
			lines++;
			newcur=cur+w;
		}
		else if(cur+w<sz(s))
		{
			lines++;
			newcur=nearest[cur+w-1]+1;
			if(newcur<=cur)
				return false;
		}
		else if(cur+w >= sz(s))
		{
			lines++;
			newcur=sz(s);
		}
		else
			return false;

		cur=newcur;
		if(cur>=sz(s))
		{
			if(lines<=k)
			return true;
			else
			return false;
		}
	}
}

int main(){
  fast;
  cin>>k;

  getline(cin,s); //For newline
  getline(cin,s);
  	
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]==' ')
  	{
  		s[i]='-';
  	}
  }
  
  nearest[0]=-1;
  FOR(i,1,sz(s)-1)
  {
  	if(s[i]=='-')
  	nearest[i]=i;
  	else
  	nearest[i]=nearest[i-1];
  }

  int l=1;
  int r=1000000;

  while(r-l>1)
  {
  	int mid=(l+r)/2;
  	if(check(mid))
  	r=mid;
  	else
  	l=mid;
  }

  if(check(l))
  	cout<<l<<endl;
  else
  	cout<<r<<endl;
  return 0;
 }