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
const int N = 9e3+10; 

int val[N];
int temp[N];
int main(){
  fast;
  fill(val,0);
  fill(temp,0);
  val[1]=1;

  int n;
  cin>>n;
  
  int rounds;
  cin>>rounds;	

  
  int cnt=0;
  FOR(i,1,n)
  if(val[i]==1)
  {
  	//cnt+=val[i];
  	cout<<i<<" ";
  }
  cout<<endl;

  
  FOR(i,1,rounds)
  {
  	
  	fill(temp,0);
  	FOR(j,1,n)
  	{
  		if(val[j]==1)
  		{
  			FOR(k,j,n)
  			temp[k]++;
  		}
  	}

  	FOR(j,1,n)
  	if(temp[j]%2)
  	val[j]=1;
  	else
  	val[j]=0;

  	FOR(j,1,n)
  	if(val[j]==1)
  	{
  		//cnt+=val[j];
  		cout<<j<<" ";
  	}
  	cout<<endl;
  }

  //cout<<cnt<<endl;
  return 0;
}