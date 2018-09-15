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
const int N = 1e5+10; 

vector<int> f;
vector<int> s;
vector<int> temp;

int main(){
  fast;
  int n;
  cin>>n;
  f.clear();
  s.clear();
  
  s.push_back(1);
  f.push_back(1);
  f.push_back(0);

  FOR(i,2,n)
  {
  	temp=f;
  	f.push_back(0);
  	int x=f.size()-1;
  	int y=s.size()-1;
  	while(x>=0 and y>=0)
  	{
  		f[x]=f[x]+s[y];
  		f[x]%=2;
  		if(f[x]<0)
  			f[x]+=2;

  		x--;
  		y--;
  	}
  	s=temp;
  }

    cout<<f.size()-1<<endl;
  	NFOR(i,sz(f)-1,0)
  	cout<<f[i]<<" ";
  	cout<<endl;

  	cout<<s.size()-1<<endl;
  	NFOR(i,sz(s)-1,0)
  	cout<<s[i]<<" ";
  	cout<<endl;
  return 0;
}