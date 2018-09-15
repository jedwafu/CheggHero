#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> ii;

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

ll arr[100010];
ll forward[100010];
ll backward[100010];
vector<ii> sorted;
vector<ll> temp;

bool lessthan(int i,int j)
{
  if (sorted[i].F<sorted[j].F)
    return true;
  else if (sorted[i].F==sorted[j].F and sorted[i].S<sorted[j].S)
    return true;
  else 
    return false;
}

void calculateBackSpan(int n)
{
   // Create a stack and push index of first element to it
   stack<int>st;

   st.push(1);
 
   // Span value of first element is always 1
   backward[1] = 1;
 
   // Calculate span values for rest of the elements
   for (int i = 2; i <=n; i++)
   {
      // Pop elements from stack while stack is not empty and top of
      // stack is smaller than price[i]
      while (!st.empty() && lessthan(st.top(),i))
         st.pop();
 
      // If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack
      backward[i] = (st.empty())? (i) : (i - st.top());
 
      // Push this element to stack
      st.push(i);
   }
}

void calculateForwardSpan(int n)
{
   // Create a stack and push index of first element to it
   stack<int>st;

   st.push(n);
 
   // Span value of first element is always 1
   forward[n] = 1;
 
   // Calculate span values for rest of the elements
   for (int i = n-1; i > 0; i--)
   {
      // Pop elements from stack while stack is not empty and top of
      // stack is smaller than price[i]
      while (!st.empty() && lessthan(st.top(),i))
         st.pop();
 
      // If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack
      forward[i] = (st.empty())? (n-i+1) : (st.top()-i);
 
      // Push this element to stack
      st.push(i);
   }
}

int main()
{

  fast;
  int t;
  cin>>t;
  
  while(t--)
  {
  	int n,m;
  	cin>>n>>m;
    sorted.clear();
    sorted.pb(mp(1e9,n+1));
  	FOR(i,1,n)
  	{
  		cin>>arr[i];
  		sorted.pb(mp(arr[i],i));
    }

    //sorted.pb(mp(1e10,n+1));
    calculateBackSpan(n);
    calculateForwardSpan(n);
    
    sort(sorted.begin(),sorted.end());
    std::reverse(sorted.begin(),sorted.end());

    temp.clear();
    temp.pb(0);
    for(int i=1;i<=n;i++)
    temp.pb(forward[sorted[i].S]*backward[sorted[i].S]);
    
    for(int i=2;i<=n;i++)
    temp[i]=temp[i-1]+temp[i];
   
    
    FOR(i,1,m)
    {
    	ll p;
    	cin>>p;
      std::vector<ll>::iterator ans;
    	ans=lower_bound(temp.begin(),temp.end(),p);
      cout<<sorted[ans-temp.begin()].F<<endl;
    }
   
  } 
  return 0;
}