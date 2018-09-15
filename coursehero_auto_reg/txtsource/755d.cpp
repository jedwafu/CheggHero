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
int main(){
  fast;
  ll n,k;
  cin>>n>>k;
  k=min(k,n-k);
  ll step=1;
  ll cur=1;
  ll prev=1;
  ll next;
  
  FOR(i,1,n)
  {	
  	next=(prev+k);
  	if(next>n)
  		next=next-n;
  	if(prev>next and next!=1)
  	{
		cout<<cur+step+1<<" ";
		cur+=step+1;
  		step+=2;
  	}
  	else
  	{
  		cout<<cur+step<<" ";
  		cur+=step;
  	}
  	prev=next;
  }
  return 0;
}