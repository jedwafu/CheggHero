#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

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

int arr[40][40][40];

struct A
{
  int arr[]
}

vector<ii> solvemin(int dx,int dy,int dz,int size)
{ 
  vector<ii> ans;
  
  if(size==2)
  {
    int sum=0;

    FOR(i,dx,dx+1)
    FOR(j,dy,dy+1)
    FOR(k,dz,dz+1)
    sum+=arr[i][j][k];

    ans.pb(mp(-1,sum));
    ans.pb(mp(1,min(sum,8-sum)));
    if(min(sum,8-sum))
    ans.pb(mp(8,0));
    return ans;
  } 

  int hmm=size>>1;
    
  vector<ii> ans1=solvemin(dx,dy,dz,hmm);
  vector<ii> ans2=solvemin(dx,dy,dz+hmm,hmm);
  vector<ii> ans3=solvemin(dx,dy+hmm,dz,hmm);
  vector<ii> ans4=solvemin(dx,dy+hmm,dz+hmm,hmm);
  vector<ii> ans5=solvemin(dx+hmm,dy,dz,hmm);
  vector<ii> ans6=solvemin(dx+hmm,dy,dz+hmm,hmm);
  vector<ii> ans7=solvemin(dx+hmm,dy+hmm,dz,hmm);
  vector<ii> ans8=solvemin(dx+hmm,dy+hmm,dz+hmm,hmm);
  
  ans.pb(mp(-1,ans1[0].S+ans2[0].S+ans3[0].S+ans4[0].S+ans5[0].S+ans6[0].S+ans7[0].S+ans8[0].S));
  ans.pb(mp(1,min(ans[0].S,(int)pow(size,3)-ans[0].S)));  
  FOR(i1,1,sz(ans1)-1)
  FOR(i2,1,sz(ans2)-1)
  FOR(i3,1,sz(ans3)-1)
  FOR(i4,1,sz(ans4)-1)
  FOR(i5,1,sz(ans5)-1)
  FOR(i6,1,sz(ans6)-1)
  FOR(i7,1,sz(ans7)-1)
  FOR(i8,1,sz(ans8)-1)
  {
    ans.pb(mp(ans1[i1].F+ans2[i2].F+ans3[i3].F+ans4[i4].F+ans5[i5].F+ans6[i6].F+ans7[i7].F+ans8[i8].F,ans1[i1].S+ans2[i2].S+ans3[i3].S+ans4[i4].S+ans5[i5].S+ans6[i6].S+ans7[i7].S+ans8[i8].S));
  }

  return ans;
}

vector<ii> solvemax(int dx,int dy,int dz,int size)
{ 
  vector<ii> ans;
  
  if(size==2)
  {
    int sum=0;

    FOR(i,dx,dx+1)
    FOR(j,dy,dy+1)
    FOR(k,dz,dz+1)
    sum+=arr[i][j][k];

    ans.pb(mp(-1,sum));
    if(min(sum,8-sum))
    ans.pb(mp(8,0));
    else
    {
      ans.pb(mp(8,1));
      ans.pb(mp(1,0));
    }
    return ans;
  } 

  int hmm=size>>1;
    
  vector<ii> ans1=solvemax(dx,dy,dz,hmm);
  vector<ii> ans2=solvemax(dx,dy,dz+hmm,hmm);
  vector<ii> ans3=solvemax(dx,dy+hmm,dz,hmm);
  vector<ii> ans4=solvemax(dx,dy+hmm,dz+hmm,hmm);
  vector<ii> ans5=solvemax(dx+hmm,dy,dz,hmm);
  vector<ii> ans6=solvemax(dx+hmm,dy,dz+hmm,hmm);
  vector<ii> ans7=solvemax(dx+hmm,dy+hmm,dz,hmm);
  vector<ii> ans8=solvemax(dx+hmm,dy+hmm,dz+hmm,hmm);
  
  ans.pb(mp(-1,ans1[0].S+ans2[0].S+ans3[0].S+ans4[0].S+ans5[0].S+ans6[0].S+ans7[0].S+ans8[0].S)); 
  
  if(min(ans[0].S,(int)pow(size,3)-ans[0].S)==0)
  ans.pb(mp(1,0));

  FOR(i1,1,sz(ans1)-1)
  FOR(i2,1,sz(ans2)-1)
  FOR(i3,1,sz(ans3)-1)
  FOR(i4,1,sz(ans4)-1)
  FOR(i5,1,sz(ans5)-1)
  FOR(i6,1,sz(ans6)-1)
  FOR(i7,1,sz(ans7)-1)
  FOR(i8,1,sz(ans8)-1)
  {
    ans.pb(mp(ans1[i1].F+ans2[i2].F+ans3[i3].F+ans4[i4].F+ans5[i5].F+ans6[i6].F+ans7[i7].F+ans8[i8].F,ans1[i1].S+ans2[i2].S+ans3[i3].S+ans4[i4].S+ans5[i5].S+ans6[i6].S+ans7[i7].S+ans8[i8].S));
  }

  return ans;
}


int main(){
  fast;
  int n,k;
  cin>>n>>k;
  int mini=1000000,maxi=0;
  FOR(i,0,n-1)
  FOR(j,0,n-1)
  FOR(k,0,n-1)
  cin>>arr[i][j][k];
  

  if(n==1)
  {
    cout<<1<<" "<<1;
  }

  else if(n==2 or n==4)
  {
    vector<ii> ans=solvemin(0,0,0,n);
    sort(ans.begin(),ans.end());
    
    if(min(ans[0].S,(int)pow(n,3)-ans[0].S)<=k)
      mini=1;
    else
    FOR(i,1,sz(ans)-1)
    {
      if(ans[i].S<=k)
      {
        mini=ans[i].F;
        break;
      }
    }

    ans.clear();
    ans=solvemax(0,0,0,n);
    sort(ans.begin(),ans.end());
    if(min(ans[0].S,(int)pow(n,3)-ans[0].S)==0 and k==0)
      maxi=1;
    else
    {
      reverse(ans.begin(),ans.end());
      FOR(i,0,sz(ans)-2)
      if(ans[i].S<=k)
      {
        maxi=ans[i].F;
        break;
      }
    }

   cout<<mini<<" "<<maxi<<endl;
  }
  else if(n==8)
  {
    
    
  }
  return 0;
}