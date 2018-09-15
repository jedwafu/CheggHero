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
const int N = 5e5+10; 

char ops[N+10];
int nums[N+10];

int typ[10];

int main(){
  fast;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  	cin>>ops[i]>>nums[i];
  }

  for(int j=0;j<10;j++)
  {
  	int val1=1;
  	int val2=0;
  	for(int i=0;i<n;i++)
  	{
  		int vals=((1<<j) & nums[i]);
  		if(vals)
  		vals=1;
  		if(ops[i]=='&')
  		{
  			val1=val1 & vals;
  			val2=val2 & vals;
  		}
  		if(ops[i]=='^')
  		{
  			val1=val1 ^ vals;
  			val2=val2 ^ vals;
  		}
  		if(ops[i]=='|')
  		{
  			val1=val1 | vals;
  			val2=val2 | vals;
  		}
  	}

  	if(val1==1 and val2==0)
  	typ[j]=0;
  	if(val1==0 and val2==1)
  	typ[j]=1;
  	if(val1==0 and val2==0)
  	typ[j]=2;
  	if(val1==1 and val2==1)
  	typ[j]=3;
  }

  cout<<3<<endl;

  int x=0;
  for(int i=0;i<10;i++)
  if(typ[i]==3)
  x=x+(1<<i);

  cout<<"| "<<x<<endl;
  x=1023;

  for(int i=0;i<10;i++)
  if(typ[i]==2)
  x=x-(1<<i);

  cout<<"& "<<x<<endl;

  x=0;
  for(int i=0;i<10;i++)
  if(typ[i]==1)
  x=x+(1<<i);

  cout<<"^ "<<x<<endl;	
  return 0;
}