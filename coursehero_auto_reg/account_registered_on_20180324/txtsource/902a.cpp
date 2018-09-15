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

int a[200],b[200];
int main(){
  fast;
  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++)
  	cin>>a[i]>>b[i];

  bool flag=false;
  int ed=0;
  if(ed<a[0])
  {
    cout<<"NO"<<endl;
    return 0;
  }
  
  for(int i=0;i<n;i++)
  {
  	ed=max(ed,b[i]);
  	if(ed>=m)
  	{
  		flag=true;
  		break;
  	}
  	
  	if(i<n-1 and ed<a[i+1])
  		break;
  }

  if(flag)
  	cout<<"YES"<<endl;
  else
  	cout<<"NO"<<endl;
  return 0;
}