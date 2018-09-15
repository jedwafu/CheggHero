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

int main(){
  fast;
  int t;
  cin>>t;
  FOR(T,1,t)
  {
  	int h,s,x,y,z=0;
  	cin>>h>>s;
  	FOR(i,1,s)
  	{
  		string arr;
  		cin>>arr;

  		if(arr[1]=='d')
  			{
  		        char c=arr[0];
  				x=atoi(&c);
  			    //string temp=arr.substr(2,sz(arr)-2);
  			    y=atoi(&arr[2]);
  			}
  		else
  		if(arr[2]=='d')
  		{
  		   x=(arr[0]-'0')*10;
  		   x+=(arr[1]-'0');
  		   y=atoi(&arr[3]);
  		}
        

  		cout<<x<<" "<<y<<endl;

  	}

  }
  return 0;
}