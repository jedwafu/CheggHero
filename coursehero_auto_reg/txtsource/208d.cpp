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

ll arr[60];
ll quant[6];
ll a,b,c,d,e;
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i];
  cin>>a>>b>>c>>d>>e;
  fill(quant,0);
  ll sum=0;
  FOR(i,1,n)
  {
  	sum+=arr[i];
    quant[5]+=sum/e;
    sum-=e*(sum/e);
    quant[4]+=sum/d;
    sum-=d*(sum/d);
    quant[3]+=sum/c;
    sum-=c*(sum/c);
    quant[2]+=sum/b;
    sum-=b*(sum/b);
    quant[1]+=sum/a;
    sum-=a*(sum/a);
  }

  cout<<quant[1]<<" "<<quant[2]<<" "<<quant[3]<<" "<<quant[4]<<" "<<quant[5]<<endl;
  cout<<sum;

  return 0;
}