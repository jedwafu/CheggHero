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

int days[N];
int prep[N];

// hp matlab HoPayega.....Tribe se churaya hai !!
int last[N];
int n,m;
bool hp(int index)
{
	FOR(i,0,m)
	last[i]=0;

	FOR(i,1,index)
	last[days[i]]=i;
    
    FOR(i,1,m)
    if(!last[i])
    	return false;

    int free=0;
	FOR(i,1,index)
	{
       if(days[i])
       	{
       	   if(last[days[i]]==i)
       	   {
       	   	  if(free>=prep[days[i]])
       	   	  	free-=prep[days[i]];
       	   	  else
       	   	  	return false;
       	   }
       	   else 
       	   	free++;
        }
        else
        	free++;
	}

return true;
}
int main(){
  fast;
  
  cin>>n>>m;
  FOR(i,1,n)
  cin>>days[i];
  FOR(i,1,m)
  cin>>prep[i];

  int flag=0;
  int low=1;
  int high=n;
  
  while(!flag)
  {
  	if(hp(low))
    flag=low;
    else if(hp(high))
    {
       int mid=(low+high)/2;
       if(hp(mid))
        high=mid;
       else 
       	low=mid+1;
    }
    else
     flag=-1;
  }

  cout<<flag<<endl;
  return 0;
}