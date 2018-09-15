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

int arr[N];
int sums[N];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	fill(sums,0);
  	int o1,o2,n;
  	cin>>o1>>o2;
  	n=o1*o2;
  	
  	FOR(i,1,n)
  	cin>>arr[i];
  	

  	FOR(i,1,o2)
  	sums[1]+=arr[i];

  	FOR(i,2,n)
  	sums[i]=sums[i-1]-arr[i-1]+arr[(i+o2-1)>n?i+o2-1-n:i+o2-1];
  		
  	int count;
  	FOR(i,1,o2)
  	{
  		count=0;
  		FOR(j,0,o1-1)
  		{
  			if(sums[(i+j*o2)>n?(i+(j*o2)-n):(i+j*o2)]<=o2/2)
  				count++;
  		}
  		if(count<=o1/2)
  		{
  			cout<<1<<endl;
  			break;
  		}
  	}
  	if(count>o1/2)
  	cout<<0<<endl;

  }
  return 0;
}