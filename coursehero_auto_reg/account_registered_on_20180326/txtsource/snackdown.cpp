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
const int N = 5e5+10; 

int n;
ll k;
ll arr[N];
ll s[4*N];
ll dp[N];
ll last[N];
ll ctr[N];
set<ll> nums;

void update(int curr,int l,int r,int index,ll val){
  if(l==r){
      s[curr]=val%mod;
      if(s[curr]<0)
      	s[curr]+=mod;
      return ;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  if(index<=mid)
  update(c1,l,mid,index,val);
  else
  update(c2,mid+1,r,index,val);
  s[curr] = ((s[c1] +s[c2]))%mod;
  if(s[curr]<0)
  s[curr]+=mod;
}

ll query(int curr,int l,int r,int x,int y){
  if(l > y || r < x)return 0;
  if(x <= l && r <= y){
    return s[curr];
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  ll q = (query(c1,l,mid,x,y) + query(c2,mid+1,r,x,y))%mod;
  q%=mod;
  if(q<0)
  	q+=mod;

  return q;
}

void mark() 
{
    ll i = n;
    ll j = n+1;
 	nums.clear();
    fill(ctr,0);
    while(i>=1 && j>=1) 
    {

    	ll val;
        val = arr[j-1];


        
        //cout<<j<< ", size: " << nums.size() << endl;     
        
        if (nums.size() < k+1) 
         {
         	j--;

         	if (val <= k) 
        	{
             if (!ctr[val])
                nums.insert(val);
            
          	  ctr[val] ++;
            //cout<<"inserting "<<val<<" "<<j<<" "<<i<<endl;
        	}
    	}
     	

        else 
        {
            last[i] = j+1;
            ctr[arr[i]]--;
            if (!ctr[arr[i]]) {
                nums.erase(arr[i]);
                //cout<<"erasing "<<arr[i]<<" "<<j<<" "<<i<<endl;
            }
			i--;            
        }



    }
    
}

int main()
{
  fast;
  
  cin>>n>>k;
  

  FOR(i,1,n)
  cin>>arr[i];
  
  if(k==0)
  {
  	FOR(i,1,n)
  	if(arr[i]==0)
  	{
  		cout<<0;
  		return 0;
  	}
  }	

  FOR(i,1,n)
  last[i]=1;

  if(k<=n)
  mark();
  
  //cout<<"here"<<endl;
  fill(s,0);

 // update(1,1,n,0,1);
  update(1,1,n,1,1);

  FOR(i,2,n)
  {
  	int idx=last[i];

  	//cout<<i<<" "<<idx<<endl;

  	dp[i]=query(1,1,n,idx-1,i-1);
  	if(idx==1)
  	dp[i]++;
  	//cout<<i<<" "<<dp[i]<<endl;
  	update(1,1,n,i,dp[i]);
  }

  cout<<dp[n]<<endl;

  return 0;
}