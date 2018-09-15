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
const int N = 2e3+10; 

bool arr[N][10];
int main(){
  fast;
  int t;
  cin>>t;
  
  while(t--)
  {
  	int n1,n2;
  	cin>>n1>>n2;
  	fill(arr,0);
  	string s;
  	cout<<setprecision(3);
  	cout<<fixed;
  	FOR(i,1,n1+n2)
  	{
       cin>>s;
       FOR(j,0,sz(s)-1)
       {
          arr[i][s[j]-'0']=true;
          //cout<<i<<" "<<s[j]-'0'<<endl;
       }
  	}
    int val;
    int ans=0;
    FOR(i,1,n1)
    {
    	FOR(j,n1+1,n1+n2)
    	{
    		val=0;
    		NFOR(k,9,1)
    		{
    			if(arr[i][k] and arr[j][k])
    			{
    				//cout<<"here";
                   val=k;
                   break; 
    			} 
    		}
    		if(val%2==0)
                ans++;
    	}
    }
    //cout<<ans;
    double final= (1.0)*ans;
    final=final/(n1*n2);
    cout<<final<<endl;
   }
  return 0;
}