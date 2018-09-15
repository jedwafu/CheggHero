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

int a[110];
int cnts[14];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n;
  	cin>>n;
  	fill(cnts,0);
  	for(int i=0;i<n;i++)
  	{
  		cin>>a[i];
  		cnts[a[i]]++;
  	}

  	bool ans=true;

  	for(int i=1;i<=7;i++)
  	if(cnts[i]==0)
  	{
  		ans=false;
  		break;
  	}

  	for(int i=8;i<=10;i++)
  	if(cnts[i]!=0)
  	{
  		ans=false;
  		break;
  	}

  	int l=0;
  	int r=n-1;
  	while(l<r)
  	{
  		if(a[l]!=a[r])
  		{
  			ans=false;
  			break;
  		}	
  		l++;
  		r--;
  	}

  	int maxi=n/2;
  	for(int i=0;i<maxi;i++)
  	{
  		if(a[i+1]-a[i]!=0 and a[i+1]-a[i]!=1)
  		{
  			ans=false;
  			break;
  		}
  	}

  	if(ans)
  		cout<<"yes"<<endl;
  	else
  		cout<<"no"<<endl;
  }
  return 0;
}