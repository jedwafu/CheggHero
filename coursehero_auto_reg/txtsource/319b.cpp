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

stack<int> st;
int death[N];
int used[N];
int arr[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i];
  fill(used,0);
  fill(death,0);
  st.push(arr[1]);
  death[arr[1]]=-1;
  FOR(i,2,n)
  {
  	 death[arr[i]]=0;
     while(!st.empty())
     {
     	int f=st.top();
     	if(f<arr[i])
     	{
     		if(death[f] ==-1)
     		{
     		    death[arr[i]]=-1;
     		    //cout<<"popping "<<f<<endl;
     		    st.pop();
     		    //cout<<"pushing "<<arr[i]<<endl;
     		    st.push(arr[i]);
     		    break;	
     		}
     		else
     		{
     			
     				death[arr[i]]=max(death[arr[i]],death[f]);
     	            st.pop();
     	      //      cout<<"popping "<<f<<endl;
     	        
     	    }
     	}
     	else
     	{
     		used[f]++;
     		if(used[f]==death[f])
     		{
     			//cout<<"popping "<<f<<endl;
     			st.pop();
     		}
     		//cout<<"pushing "<<arr[i]<<endl;
     		st.push(arr[i]);
     		death[arr[i]]++;
     		break;
     	}
     }
  }

  int ans=0;
  FOR(i,1,n)
  ans=max(ans,death[i]);

  cout<<ans;
  return 0;
}