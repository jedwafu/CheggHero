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

int arr[110][110];
int point[110];
int size[110];
void mini(int m)
{
  int p=10005;
  int index=-1;

  FOR(i,0,m-1)
  {
    if(point[i]+1<size[i] and (arr[i][point[i]+1]-arr[i][point[i]])<p)
      {
        p=arr[i][point[i]+1]-arr[i][point[i]];
        index=i;
      }
  }
  
  point[index]++;
}

int main(){
  fast;
  int t,m,k,n;
  cin>>t;

  while(t--)
  {
    cin>>m>>k;

    FOR(i,0,m-1)
    {
      cin>>size[i];

      FOR(j,0,size[i]-1)
      cin>>arr[i][j];
      point[i]=0;
    }

    FOR(i,0,m-1)
    {
      sort(arr[i],arr[i]+size[i]);
    }

    int count=0;
    while(count<k)
    {
      int sum=0;
      
      FOR(i,0,m-1)
      sum+=arr[i][point[i]];

      count++;
      cout<<sum<<" ";
      mini(m);
    }
    cout<<endl;
  }
  return 0;
}