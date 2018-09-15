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

char arr[510][510];
int rows[510];
int start[510];
int end[510];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  	cin>>arr[i][j];

//  int total=0;
  //int rows=0;
  for(int i=1;i<=n;i++)
  {
    start[i]=-1
    end[i]=-1;
    bool flag=false;
  	for(int j=1;j<=m;j++)
  	{
       if(arr[i][j]=='X')
       {
         rows[i]++; 
         if(!flag)
         start[i]=j;
         end[i]=j;
       } 
    }
  }

  for(int i=1;i<=n;i++)
  {
    if(start[i]>0)
    {
       int k=i;
       while(start[k]>0)
        k++;
    }
  }
  

  cout<<"NO";
  return 0;
}