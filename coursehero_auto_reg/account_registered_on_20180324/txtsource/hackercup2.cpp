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

int arr[110];
int main(){
  fast;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  FOR(T,1,t)
  {
  	int n;
  	cin>>n;
  	FOR(i,0,n-1)
  	cin>>arr[i];

  	sort(arr,arr+n);
    int index2=n-1;
    int index1=0;
    int ans=0;
    bool flag=false;
    while(index1<index2)
    {
    	int w=arr[index2];
    	if(w>=50)
    		ans++;
    	else
    	{
    		int k=0;
    		if(50%w==0)
    			k=(50/w)-1;
    		else
    			k=50/w;

    		if(index1+k-1 >= index2)
    		{
    			cout<<"Case #"<<T<<": "<<ans<<endl;
    			flag=true;
    			break;
    		}
    		ans++;
    		index1+=k;
    	}
    	index2--;
    }

    if(!flag)
    	cout<<"Case #"<<T<<": "<<ans<<endl;
  }
  return 0;
}	