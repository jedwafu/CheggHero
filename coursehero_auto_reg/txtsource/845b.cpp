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

int nums[10];

int main(){
  fast;
  string s;
  cin>>s;
  for(int i=1;i<=6;i++)
  	nums[i]=s[i-1]-'0';

  int ans=3;
  for(int i1=0;i1<10;i1++)
  for(int i2=0;i2<10;i2++)
  for(int i3=0;i3<10;i3++)
  for(int i4=0;i4<10;i4++)
  for(int i5=0;i5<10;i5++)
  for(int i6=0;i6<10;i6++)
  {
  	if(i1+i2+i3==i4+i5+i6)
  	{
  		int val=0;
  		val+=(i1!=nums[1]);
  		val+=(i2!=nums[2]);
  		val+=(i3!=nums[3]);
  		val+=(i4!=nums[4]);
  		val+=(i5!=nums[5]);
  		val+=(i6!=nums[6]);
  		ans=min(ans,val);
  	}
  }
  cout<<ans<<endl;
  return 0;
}