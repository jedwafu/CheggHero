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
const int N = 1e3+10; 

map<string,int> cnt;
string arr[N];
string alt[N];

int main(){
  fast;
  int n;
  cnt.clear();

  cin>>n;
  FOR(i,0,n-1)
  {
  	string fst,sec;
  	cin>>fst>>sec;
  	string name1=fst.substr(0,3);
  	string name2=fst.substr(0,2)+sec[0];
  	arr[i]=name1;
  	alt[i]=name2;
  	cnt[name1]++;
  }
  	
  FOR(i,0,n-1)
  if(cnt[arr[i]]>1)
  	arr[i]=alt[i];
 
  FOR(k,1,sqrt(n))
  FOR(i,0,n-1)
  {
  	FOR(j,0,n-1)
  	{
  		if(i==j)
  			continue;
  		
  		if(arr[i]==arr[j])
  		{
  			arr[i]=alt[i];
  			arr[j]=alt[j];
  		}
  	}
  }

  FOR(i,0,n-1)
  {
  	FOR(j,0,n-1)
  	{
  		if(i==j)
  			continue;
  		if(arr[i]==arr[j])
  		{
  			cout<<"NO";
  			return 0;
  		}
  	}
  }

  cout<<"YES"<<endl;
  FOR(i,0,n-1)
  cout<<arr[i]<<endl;
  return 0;
}