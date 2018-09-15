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

int a[26];
int ab[26];

int freqa,freqb;
string s,t;
int main(){
  fast;
  int k;
  cin>>k;
  while(k--)
  {
  	cin>>s>>t;
  	freqa=freqb=0;
  	fill(a,0);
  	fill(ab,0);
  	for(int i=0;i<sz(s);i++)
  	a[s[i]-'a']++;
  	for(int i=0;i<sz(t);i++)
  	ab[t[i]-'a']++;

  	for(int i=0;i<=25;i++)
  	{
  		if(a[i] and !ab[i])
  			freqa=max(freqa,a[i]);
  		if(ab[i] and !a[i])
  			freqb=max(freqb,ab[i]);
  	}

  	bool ans;
  	if(freqa>1)
  		ans=true;
  	else if(freqa==0)
  		ans=false;
  	else if(freqa==1)
  	{
  		if(freqb)
  			ans=false;
  		else
  			ans=true;
  	}

  	if(ans)
  		cout<<"A"<<endl;
  	else
  		cout<<"B"<<endl;
  }
  return 0;
}