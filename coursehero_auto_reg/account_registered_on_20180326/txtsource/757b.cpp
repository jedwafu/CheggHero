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


int d[N];
int arr[N];
int present[N];

int calc()
{
	int maxi=0;
	FOR(i,2,N)
	{
		for(int j=1;j*i<=N;j++)
		{
			d[i]+=present[j*i];
		}
		maxi=max(maxi,d[i]);	
	}
	return maxi;
}

int main(){
  fast;
  int n;
  cin>>n;
  fill(d,0);
  fill(present,0);
  FOR(i,1,n)
  {
  	cin>>arr[i];
  	present[arr[i]]++;
  }
  cout<<max(1,calc());
  return 0;
}