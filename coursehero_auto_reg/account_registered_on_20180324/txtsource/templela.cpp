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
const int N = 1e2+10; 

int h[N];
int main(){
  fast;
  int s;
  cin>>s;
  while(s--)
  {
  	int n;
  	cin>>n;
  	FOR(i,1,n)
  	cin>>h[i];
  	bool flag=true;

  	if(n%2)
  	{
		FOR(i,1,(n/2)+1)
		{
			if(h[i]!=i)
			{
				flag=false;
				break;
			}			
		}

		NFOR(i,n,(n/2)+2)
		{
			if(h[i]!=n-i+1)
			{
				flag=false;
				break;
			}
		}

		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
  	}
  	else
  		cout<<"no"<<endl;
  	
  }
  return 0;
}