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

bool done[N];
vi ans;
int arr[N];
int pos[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  {
  	cin>>arr[i];
  	done[arr[i]]=true;
  	pos[arr[i]]=i;
  }

  FOR(i,1,n)
  {
     if(!done[(int)1e6+1-arr[i]])
     {
     	ans.pb((int)1e6+1-arr[i]);
     	done[(int)1e6+1-arr[i]]=true;
     	arr[i]=0;
     }
  }

  int index=1;
  FOR(i,1,n)
  {
  	if(arr[i])
  	{
        while(done[index] or done[(int)1e6+1-index])
        	index++;
        ans.pb(index);
        ans.pb((int)1e6+1-index);
        done[index]=true;
        done[(int)1e6+1-index]=true;
        arr[pos[(int)1e6+1-arr[i]]]=0;
        arr[i]=0;
        index++;
  	}
  }

  sort(ans.begin(),ans.end());
  cout<<sz(ans)<<endl;
  FOR(i,0,sz(ans)-1)
  cout<<ans[i]<<" ";

  return 0;
}