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

int n;
ll k;
ll L[N];
ll prefixsum[N];

bool check(int index,int pos)
{
	ll sums=prefixsum[pos]-prefixsum[index-1];
	sums=k*(pos-index+1)-sums;

	return sums<=(n-pos);
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int q;
  	cin>>n>>q;
  	
  	FOR(i,1,n)
  	cin>>L[i];

  	sort(L+1,L+n+1);
  	reverse(L+1,L+n+1);

  	prefixsum[0]=0;
  	FOR(i,1,n)
  	prefixsum[i]=prefixsum[i-1]+L[i];

 	FOR(i,1,q)
 	{
 		
 		cin>>k;
 		if(L[n]>=k)
 		{
 			cout<<n<<endl;
 			continue;
 		}

 		int index;
 		int l=1;
 		int r=n;
 		while(r-l>1)
 		{
 			int mid=(l+r)/2;
 			if(L[mid]>=k)
 				l=mid;
 			else
 				r=mid;
 		}
 		if(L[l]<k)
 			index=l;
 		else
 			index=r;

 		l=index;
 		r=n;

 		while(r-l>1)
 		{
			int mid=(l+r)/2;		 				
			if(check(index,mid))
				l=mid;
			else
				r=mid;
 		}
 		if(check(index,r))
 		cout<<r<<endl;
 		else if(check(index,l))
 		cout<<l<<endl;
 		else
 		cout<<max(0,index-1)<<endl;
 	}

  }
  return 0;
}