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
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 3e5+10;
 
int a[N];
int b[250];
ll dp[N];
ll sums[N];
deque<int> help(N);
ll ansfor[N];
int n,m;

void calc(int flag,int level)
{
  int range=b[level-1]-b[level]-1;
  
  if(flag)
  {
    FOR(i,1,range)
    {
      while((!help.empty()) and dp[i]!=inf and dp[i]>=dp[help.back()])
        help.pop_back();

      if(dp[i]!=inf)
      help.push_back(i);
    }

    int index=1;
    FOR(i,range+1,n)
    {
      if(help.empty())
      ansfor[index]=inf;

      else
      ansfor[index]=dp[help.front()];
      
      index++;

      while((!help.empty()) and help.front()<=i-range)
        help.pop_front();

       while((!help.empty()) and  dp[i]!=inf and dp[i]>=dp[help.back()])
        help.pop_back();

      if(dp[i]!=inf)
      help.push_back(i);
    }

    if(help.empty())
    ansfor[index]=inf;
    else    
    ansfor[index]=dp[help.front()];

    while(!help.empty())
      help.pop_back();

    ll maxi=-inf;
    if(dp[n]==inf)
    ansfor[n]=inf;
    else
    maxi=ansfor[n]=dp[n];

    NFOR(i,n-1,index+1)
    {
      if(dp[i]==inf)
        ansfor[i]=maxi;
      else
      {
        maxi=max(maxi,dp[i]);
        ansfor[i]=maxi;
      }
    }

  }

  else
  {
    FOR(i,1,range)
    {
      while((!help.empty()) and dp[i]!=inf and dp[i]<=dp[help.back()])
        help.pop_back();

      if(dp[i]!=inf)
      help.push_back(i);
    }

    int index=1;
    FOR(i,range+1,n)
    {
      if(help.empty())
      ansfor[index]=inf;

      else
      ansfor[index]=dp[help.front()];
      
      index++;

      while((!help.empty()) and help.front()<=i-range)
        help.pop_front();

       while((!help.empty()) and dp[i]!=inf and dp[i]<=dp[help.back()])
        help.pop_back();

      if(dp[i]!=inf)
      help.push_back(i);
    }

    if(help.empty())
    ansfor[index]=inf;
    else    
    ansfor[index]=dp[help.front()];

     while(!help.empty())
      help.pop_back();

    ll mini=inf;
    if(dp[n]==inf)
    ansfor[n]=inf;
    else
    mini=ansfor[n]=dp[n];

    NFOR(i,n-1,index+1)
    {
      if(dp[i]==inf)
        ansfor[i]=mini;
      else
      {
        mini=min(mini,dp[i]);
        ansfor[i]=mini;
      }
    }    
  }
}

int main()
{
  fast;
  int t;
  cin>>t;
  while(t--)
  {
    int alternate;
    cin>>n>>m;
    
    FOR(i,1,n)
    cin>>a[i];
    FOR(i,1,m)
    cin>>b[i];
 
    sums[0]=0;
    FOR(i,1,n)
    sums[i]=sums[i-1]+a[i];
 
    if(m%2)
    {
      FOR(i,1,m-1)
      dp[i]=inf;
      
      int limit=n-m-b[m]+2;
      FOR(i,m,limit)
      dp[i]=sums[i+b[m]-1]-sums[i-1];
        
      limit++;    
      FOR(i,limit,n)
      dp[i]=inf;

      calc(1,m);
      alternate=1;
    }
 
    else
    {
      FOR(i,1,m-1)
      dp[i]=inf;
      
      int limit=n-m-b[m]+2;

      FOR(i,m,limit)
      dp[i]=-(sums[i+b[m]-1]-sums[i-1]);
      
      limit++;  
      FOR(i,limit,n)
      dp[i]=inf; 

      calc(0,m);
      alternate=0;
    }
 
    NFOR(j,m-1,1)
    {    
      
      bool check;
      if(alternate)
        check=true;
      else
        check=false;

      int limit=n-j-b[j]+2;
      FOR(i,j,limit)
      {
        if(check)
        {
          ll maxi=ansfor[i+1];
          ll val=sums[i+b[j]-1]-sums[i-1];
          if(abs(maxi)==inf)
          dp[i]=inf;
          else
          dp[i]=maxi-val;
        }
        else
        {
          ll mini=ansfor[i+1];
          ll val=sums[i+b[j]-1]-sums[i-1];
          if(abs(mini)==inf)
          dp[i]=inf;
          else
          dp[i]=mini+val; 
        }
      }
 
      FOR(i,n-j-b[j]+3,n)
      dp[i]=inf;
      
      if(check and j>1)
        calc(0,j);
      else if(!check and j>1)
        calc(1,j);

      alternate=1-alternate;
    }
 
   ll maxi=-inf;
   FOR(i,1,n)
   {
    if(dp[i]!=inf)
    maxi=max(maxi,dp[i]); 
   }
    cout<<maxi<<endl;
  }
  return 0;
}