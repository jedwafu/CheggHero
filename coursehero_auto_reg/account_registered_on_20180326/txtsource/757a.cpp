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

int arr[30];
int main(){
  fast;
  string s;
  cin>>s;
  fill(arr,0);
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]=='B')
  		arr[0]++;
  	if(s[i]=='b')
  		arr[1]++;
  	if(s[i]=='u')
  		arr[2]++;
  	if(s[i]=='l')
  		arr[3]++;
  	if(s[i]=='a')
  		arr[4]++;
  	if(s[i]=='s')
  		arr[5]++;
  	if(s[i]=='r')
  		arr[6]++;
  }

  	arr[2]/=2;
  	arr[4]/=2;
  	int mini=100000;
  	FOR(i,0,6)
  	mini=min(mini,arr[i]);

  	cout<<mini;

  

  return 0;
}