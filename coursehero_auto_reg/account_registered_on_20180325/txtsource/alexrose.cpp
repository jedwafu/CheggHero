#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

map<ll,ll> freq;
vector<int> eureka;
vector<int> sorter;
int arr[100010];

int main(){
  fast;

  int t;
  cin>>t;
  while(t--)
  {
  	int n,k;
  	ll temp;
  	cin>>n>>k;
    freq.clear();
    eureka.clear();
    sorter.clear();
    FOR(i,1,n)
    {
    	cin>>temp;
    	freq[temp]++;
    }

    temp=0;
    for (std::map<ll,ll>::iterator it=freq.begin(); it!=freq.end(); ++it)
    {
    	freq[it->F]=freq[it->F]%k;
    	if(freq[it->F]<0)
    		freq[it->F]+=k;

    	temp+=freq[it->F];
    	if(freq[it->F])
    		eureka.pb(freq[it->F]);
    }
  
    int rem=n;
    n=temp;
    int index=n/k;
    ll cumsum=0;
    for(int i=eureka.size()-1;i>=0;i--)
    {
        if(eureka[i]+(cumsum-((n/k)-index)*k) >= k)
        {
        	arr[index]=i;
        	//cout<<index<<" "<<i<<endl;
        	index--;
        }
        cumsum+=eureka[i];
    }
    
    ll ans;

    if(n)
    	ans=0;
    else
    {
    	cout<<0<<endl;
    	continue;
    }

    arr[0]=-1;
    ll maxi=0;
    int taken=0;
    for(int i=1;i<=n/k;i++)
    {
    	maxi=0;
    	index=arr[i];
    	//cout<<index<<endl;
    	for(int j=index;j>=0;j--)
    		if(eureka[j]>maxi)
    		{
    		   maxi=eureka[j];
    		   taken=j;
    		}
        ans+=maxi;
        //cout<<maxi<<taken<<endl;
        eureka[taken]=0;
    }

    cout<<n-ans<<endl;

  }
  return 0;
}