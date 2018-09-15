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
ll a[N];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,d;
  	ll total=0;
  	cin>>n>>d;
  	ll target=0;
  	for(int i=0;i<n;i++)
  	{
  		cin>>a[i];
  		target+=a[i];
  	}

  	if(target%n)
  	{
  		cout<<-1<<endl;
  		continue;
  	}

  	target/=n;
  	bool flag=true;
  	for(int i=0;i<d;i++)
  	{
  		ll sum=0;
  		ll elem=0;
  		for(int j=i;j<n;j+=d)
  		{
  			sum+=a[j];
  			elem++;
  		}

  		if(sum%elem or (sum/elem)!=target)
  		{
  			cout<<-1<<endl;
  			flag=false;
  			break;
  		}

  		for(int j=i;j<n;j+=d)
  		{
  			if(a[j]==target)
  				continue;
  			else
  			{
  				//cout<<"at "<<j<<" and adding "<<abs(target-a[j])<<" steps"<<endl;
  				total+=abs(target-a[j]);
  				a[j+d]-=(target-a[j]);
  				a[j]=target;
  			}
  		}

  	}

  	if(!flag)
  		continue;

  	cout<<total<<endl;
  } 
  return 0;
}