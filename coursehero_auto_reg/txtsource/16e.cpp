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
const int N = 30; 

ll pows[N];
double arr[N][N];
double prob[262150];
vi bits[N];

int pop(unsigned x)
{
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

void POWS()
{
	pows[0]=1;
	FOR(i,1,N-1)
	pows[i]=2*pows[i-1];
}

int main(){
  fast;
  int n;
  cin>>n;

  cout<<setprecision(12);
  cout<<fixed;
  
  fill(bits,0);
  fill(prob,0);
  POWS();

  FOR(i,1,n)
  FOR(j,1,n)
  cin>>arr[i][j];

  FOR(i,1,pows[n]-1)
  bits[pop(i)].pb(i);

  prob[bits[n][0]]=1;

  NFOR(num,n,1)
  {
  	double denom=(num*(num-1))/2;
  	denom=1/denom;
  	FOR(i,0,sz(bits[num])-1)
  	{
  		int mask=bits[num][i];
  		//cout<<"mask is "<<mask<<endl;
  		FOR(j,0,n-1)
  		FOR(k,0,j-1)
  		{
  			if((mask & (1 << j)) and (mask & (1 << k)))
  			{
  				prob[mask-pows[j]]+=prob[mask]*arr[k+1][j+1]*denom;
  				prob[mask-pows[k]]+=prob[mask]*arr[j+1][k+1]*denom;
  				//cout<<"new masks were "<<mask-pows[j]<<" "<<mask-pows[k]<<endl;
  			}
  		}
  	}
  }	

  FOR(i,0,n-1)
  cout<<prob[pows[i]]<<" ";
  return 0;
}