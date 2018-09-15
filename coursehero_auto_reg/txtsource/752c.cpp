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

int arr[1000010];
ll pows[50];
int n;
ll k;
bool possible(int val)
{
	ll ans=0;
   FOR(i,1,n)
   {
   	 int temp=arr[i];
   	 int p1=0,p2=0;
     while((temp >> 1) >= val)
     {
        temp=temp >> 1;
        p1++;
     }
     
     temp=arr[i];
     while((temp >> 1) >= val-1 and temp>0)
     {
        temp=temp >> 1;
        p2++;
     }
    
     if(arr[i]>=val)
     ans+=max(pows[p1],(arr[i]%pows[p2])); 
     
     if(ans>=k)
     	return true;
   }
   return (ans>=k);
}

int main(){
  fast;
  int maxi=0;
  cin>>n>>k;
  pows[0]=1;
  
  FOR(i,1,25)
  pows[i]=2*pows[i-1];

  FOR(i,1,n)
  {
  	cin>>arr[i];
  	maxi=max(maxi,arr[i]);
  }
  int l=1;
  int r=maxi;

  while(r-l>1)
  {
  	int mid=(l+r) >> 1;
  	if(possible(mid))
  		l=mid;
  	else
  		r=mid;
  }
  
  if(possible(r))
  	cout<<r;
  else if(possible(l))
  	cout<<l;
  else
  	cout<<-1;


  return 0;
}