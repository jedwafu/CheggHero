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

int arr[310][310];
bool done[310][310][8][40];
int dist[40];
int n;

void go(int x,int y,int dir,int level)
{ 
	if(done[x][y][dir][level])
		return;

     done[x][y][dir][level]=true;
	 int fx,fy;
	 int t=dist[level];
	 if(dir==0)
    {
    	for(int i=1;i<=t;i++)
        arr[x][y+i]=1;
        fx=x;fy=y+t;
    }

     if(dir==1)
     {
     	for(int i=1;i<=t;i++)
        arr[x+i][y+i]=1;
        fx=x+t;fy=y+t;
     }   
     if(dir==2)
     {
     	for(int i=1;i<=t;i++)
        arr[x+i][y]=1;
        fx=x+t;fy=y;
     }

     if(dir==3)
     {
     	for(int i=1;i<=t;i++)
        arr[x+i][y-i]=1;
        fx=x+t;fy=y-t;
      }

     if(dir==4)
     {
     	for(int i=1;i<=t;i++)
        arr[x][y-i]=1;
        fx=x;fy=y-t;
     }

     if(dir==5)
     {
     	for(int i=1;i<=t;i++)
        arr[x-i][y-i]=1;
        fx=x-t;fy=y-t;
     }

     if(dir==6)
     {
     	for(int i=1;i<=t;i++)
        arr[x-i][y]=1;
        fx=x-t;fy=y;
     }
     
     if(dir==7)
     {
     	for(int i=1;i<=t;i++)
        arr[x-i][y+i]=1;
        fx=x-t;fy=y+t;
     }

     int l=dir-1;
     int r=dir+1;
     if(dir==7)
     r=0;
     if(dir==0)
     l=7;
    
     if(level!=n)
     {
     	go(fx,fy,l,level+1);
     	go(fx,fy,r,level+1);
     } 
}


int main(){
  fast;
  
  fill(done,0);
  fill(arr,0);
  cin>>n;
  FOR(i,1,n)
  cin>>dist[i];
  
  //end[1].pb(mp(mp(152,152),0));
  go(152,152,0,1);

  ll ans=0;
  FOR(i,1,302)
  FOR(j,1,302)
  if(arr[i][j])
  	ans++;
  cout<<ans;
  return 0;
}