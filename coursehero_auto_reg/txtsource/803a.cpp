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
const int N = 1e2+10; 

int n,k;
bool arr[N][N];
void print()
{
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
  fast;
  
  cin>>n>>k;
  fill(arr,0);
  if(k>n*n)
  {
  	cout<<-1;
  	return 0;
  }

  FOR(i,1,n)
  {
  	FOR(j,i,n)
  	{
  		if(i==j)
  		{
  			if(k)
  			{
  				arr[i][j]=1;
  				k--;
  			}

  			if(k==0)
  			{
  				print();
  				return 0;
  			}
  		}
  		else
  		{
  			if(k>1)
  			{
  				arr[i][j]=arr[j][i]=1;
  				k-=2;
  			}
  			else if(k==1)
  			{
  				arr[i+1][i+1]=1;
  				k--;
  			}
  			
  			if(k==0)
  			{
  				print();
  				return 0;
  			}
  		}
  	}
  }
  return 0;
}