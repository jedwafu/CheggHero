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

int arr[N];
int lefts[N];
int rights[N];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  FOR(i,1,n)
  cin>>arr[i];
  
  rights[n]=1;
  NFOR(i,n-1,1)
  {
  	if(arr[i]==arr[i+1])
  		rights[i]=rights[i+1]+1;
  	else
  		rights[i]=1;
  }

  lefts[1]=1;
  FOR(i,2,n)
  {
  	if(arr[i]==arr[i-1])
  		lefts[i]=lefts[i-1]+1;
  	else
  		lefts[i]=1;
  }

  FOR(i,1,m)
  {
  	int l,r,k;
  	cin>>l>>r>>k;
  	int total=0;
  	int mid=(l+r)/2;
  	total+=min(rights[mid],r-mid+1);
  	total+=min(lefts[mid],mid-l+1);
  	total--;
  	if(total>=k)
  		cout<<arr[mid]<<endl;
  	else
  		cout<<-1<<endl;
  }
  return 0;
}