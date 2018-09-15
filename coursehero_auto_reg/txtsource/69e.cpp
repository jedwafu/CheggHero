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

map<int,int> cnt;
set<int> s;
int arr[N];
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  FOR(i,1,n)
  cin>>arr[i];

  FOR(i,1,k)
  {
  	if(cnt[arr[i]]==0)
  	s.insert(-arr[i]);
  	
  	else if(cnt[arr[i]]==1)
  	s.erase(-arr[i]);
  	
  	cnt[arr[i]]++;
  }

  if(s.empty())
  	cout<<"Nothing"<<endl;
  else
  	cout<<-(*s.begin())<<endl;

  FOR(i,k+1,n)
  {
  	cnt[arr[i-k]]--;

  	if(cnt[arr[i-k]]==1)
  		s.insert(-arr[i-k]);

  	if(cnt[arr[i-k]]==0)
  		s.erase(-arr[i-k]);

  	if(cnt[arr[i]]==0)
  	s.insert(-arr[i]);
  		
  	else if(cnt[arr[i]]==1)
  	s.erase(-arr[i]);
  
  	cnt[arr[i]]++;

  	if(s.empty())
  	cout<<"Nothing"<<endl;
	else
  	cout<<-(*s.begin())<<endl;

  }

  return 0;
}