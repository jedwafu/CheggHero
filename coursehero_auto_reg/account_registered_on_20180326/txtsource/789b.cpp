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

map<ll,bool> present;

int main(){
  fast;
  ll b1,q,l,m;
  cin>>b1>>q>>l>>m;

  FOR(i,1,m)
  {
  	ll temp;
  	cin>>temp;
  	present[temp]=true;
  }	
 	
  if(abs(b1)>abs(l))
  {
  	cout<<0<<endl;
  	return 0;
  }

  if(b1==0)
  {
  	if(present[0])
  		cout<<0;
  	else
  		cout<<"inf";
  	return 0;
  }
  else if(q==1 and present[b1]==false)
  {
  	cout<<"inf"<<endl;
  	return 0;
  }
  else if(q==1 and present[b1])
  {
  	cout<<0<<endl;
  	return 0;
  }
  else if(q==0 and present[0]==false)
  {
  	cout<<"inf"<<endl;
  	return 0;
  }
  else if(q==0 and present[0]==true)
  {
  	if(present[b1]==false)
  		cout<<1<<endl;
  	else
  		cout<<0<<endl;
  	return 0;
  }
  else if(q==-1 and (present[b1]==false or present[-b1]==false))
  {
  	cout<<"inf"<<endl;
  	return 0;
  }
  else if(q==-1)
  {
  	cout<<0;
  	return 0;	
  }

  ll cur=b1;
  ll cnt=0;
  while(abs(cur)<=abs(l))
  {
  	if(present[cur]==false)
  	cnt++;
  	
  	cur*=q;
  }
  cout<<cnt;
  return 0;
}