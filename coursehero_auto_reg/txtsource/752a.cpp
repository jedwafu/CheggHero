#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

int main(){
  fast;
  int n,m,k;
  cin>>n>>m>>k;
  int l,d;
  int temp=2*m;
  if(k%temp==0)
  {
    cout<<k/temp<<" "<<m<<" R";
    return 0;
  }
  cout<<k/temp +1<<" ";
  temp=k/temp;
  temp=2*m*temp;
  temp=k-temp;
  if(temp%2)
  	cout<<temp/2 +1;
  else
  	cout<<temp/2;
  cout<<" ";
  if(k%2)
  	cout<<"L";
  else cout<<"R";

  return 0;
}