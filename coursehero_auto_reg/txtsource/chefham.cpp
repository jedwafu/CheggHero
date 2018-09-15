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
vector<ii> cp;
map<ii,int> assign;
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	cp.clear();
  	assign.clear();
  	int n;
  	cin>>n;
  	FOR(i,1,n)
  	{
  		cin>>arr[i];
  		cp.push_back(make_pair(arr[i],i));
  	}

  	if(n==1)
  	{
  		cout<<0<<endl;
  		cout<<arr[1]<<endl;
  		continue;
  	}

  	if(n==2)
  	{
  		if(arr[1]==arr[2])
  		{
  			cout<<0<<endl;
  			cout<<arr[1]<<" "<<arr[2]<<endl;
  		}
  		else
  		{
  			cout<<2<<endl;
  			cout<<arr[2]<<" "<<arr[1]<<endl;
  		}
  		continue;
  	}

  	if(n==3)
  	{
  		if(arr[1]==arr[2] or arr[2]==arr[3] or arr[1]==arr[3])
  		{
  			cout<<2<<endl;
  			cout<<arr[2]<<" "<<arr[3]<<" "<<arr[1]<<endl;
  		}
  		else
  		{
  			cout<<3<<endl;
  			cout<<arr[2]<<" "<<arr[3]<<" "<<arr[1]<<endl;
  		}
  		continue;
  	}

  	sort(cp.begin(),cp.end());
  	for(int i=0;i<cp.size();i++)
  	{
  		int pos=i+2;
  		if(pos>=n)
  			pos-=n;

  		assign[make_pair(cp[i].F,cp[i].S)]=cp[pos].F;
  	}
  	cout<<n<<endl;
  	for(int i=1;i<=n;i++)
  	cout<<assign[make_pair(arr[i],i)]<<" ";
  	cout<<endl;
  }
  return 0;
}