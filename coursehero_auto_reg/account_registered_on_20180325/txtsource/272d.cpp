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

set<ii> tarr;
vector<int> arr;
map<int,int> cnt;
ll calc(int n,int c,int m)
{
	ll temp=1;
	for(int i=3;i<=c;i+=2)
	temp=(temp*i)%m;
    
    int count=c-n;
    for(int i=2;i<=c;i+=2)
    {
    	int t=i;
    	while(count>0 and t%2==0)
        {
        	t/=2;
        	count--;
        }
        temp=(temp*t)%m;
    }

	return temp%m;
}

int main(){
  fast;
  int n,m;
  cin>>n;
  FOR(i,1,n)
  {
  	int a;
  	cin>>a;
  	cnt[a]++;
  	tarr.insert(mp(a,i));
  }
  FOR(i,1,n)
  {
  	int a;
  	cin>>a;
  	cnt[a]++;
  	tarr.insert(mp(a,i));
  }
  cin>>m;
 set<ii>::iterator it;
 for (it = tarr.begin(); it != tarr.end(); ++it)
 arr.pb(it->F);
 
 ll ans=1;
 int count=1;
 arr.pb(-1);
 //cout<<sz(arr)<<endl;
 FOR(i,1,sz(arr)-1)
 {
   if(arr[i]==arr[i-1])
   	count++;
   else
   {
       ans=(ans*calc(count,cnt[arr[i-1]],m))%m;
       count=1;
   } 
 }
 cout<<ans%m;
  return 0;
}