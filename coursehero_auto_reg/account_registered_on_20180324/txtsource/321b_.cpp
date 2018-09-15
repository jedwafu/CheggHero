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
int n,m;
vi atk;
vi def;
vi arr;
bool done[110];
int ans=0;

bool func()
{
  int index=0;
  FOR(i,0,sz(def)-1)
  {
    if(index>=m)
     {
      return false;
     }

    while(index<m and arr[index]<=def[i]) 
      index++;

    if(index==m)
      {
        return false;
      }
      else
      {
         done[index]=true;
         index++;
      }
  }
  return true;
}

int main(){
  fast;
  
  cin>>n>>m;
  fill(done,0);
  FOR(i,1,n)
  {
     string s;
     int c;
     cin>>s>>c;
     if(s=="ATK")
     	atk.pb(c);
     else
     	def.pb(c);
  }
  FOR(i,1,m)
  {
  	int c;
  	cin>>c;
  	arr.pb(c);
  }
  sort(atk.begin(),atk.end());
  sort(def.begin(),def.end());
  sort(arr.begin(),arr.end());

  bool val=func();
  if(val)
  {
    int index=sz(atk)-1;
    NFOR(i,m-1,0)
    {
      if(done[i])
        continue;
      
      else if(index==-1)
        ans+=arr[i];

      else if(arr[i]>=atk[index])
      {
        ans+=arr[i]-atk[index];
        index--;
      }
      else
      {
        ans=0;
        break;
      }
    }
  }
  int temp=0;
  int index=0;
  NFOR(i,m-1,0)
  {
     if(index==sz(atk))
      break;

     if(arr[i]>=atk[index])
     {
      temp+=arr[i]-atk[index];
      index++;
     }   
  }

  cout<<max(temp,ans);

  //reverse(arr.begin(),arr.end());
  //reverse(def.begin(),def.end());
  //reverse(atk.begin(),atk.end());
 
 /* FOR(i,0,sz(atk)-1)
  cout<<atk[i]<<endl;
  FOR(i,0,sz(def)-1)
  cout<<def[i]<<endl;
  FOR(i,0,sz(arr)-1)
  cout<<arr[i]<<endl;
  cout<<DP(0,0,0,0);
  */
  return 0;
}