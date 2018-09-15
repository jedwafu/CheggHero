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

string s1,s2,virus;
int dp[110][110][110];
set<string> suff;
//bool picked[110][110][110];

int LCS(int i,int j,int state,string s)
{
	if(dp[i][j][state]+1)
		return dp[i][j][state];
    
    if(i==0 and j==0)
    {
    	if(s1[i]==s2[j])
     	{
     		if(state==1 and s1[i]==virus[0])
     			return 0;

     		dp[i][j][state]=1;
     		return 1;
     	}
    }

    if(i==0)
    {
     	if(s1[i]==s2[j])
     	{
     		if(state==1 and s1[i]==virus[0])
     			return 0;

     		dp[i][j][state]=1;
     		return 1;
     	}
        

        dp[i][j][state]= LCS(i,j-1,state,s);
     	return dp[i][j][state];
    }

    if(j==0)
    {
     	if(s1[i]==s2[j])
     	{
     		if(state==1 and s2[j]==virus[0])
     			return 0;

     		dp[i][j][state]=1;
     		return 1;
     	}
        
        dp[i][j][state]= LCS(i-1,j,state,s);
     	return dp[i][j][state];
    }

    if(s1[i]==s2[j])
    {
    	if(state==1 and s1[i]==virus[0])
    	{
    		dp[i][j][state]=LCS(i-1,j-1,state,s);
    		return dp[i][j][state];
    	}

    	if(s1[i]==virus[state-1])
    	{
    		dp[i][j][state]=1+LCS(i-1,j-1,state-1,s1[i]+s);
    		return dp[i][j][state];
    	}
        
        s=s1[i]+s;
        int newstate=sz(virus);
        NFOR(x,sz(s),1)
        {
        	string temp=s.substr(0,x);
        	if(suff.count(temp))
        	{
               newstate=sz(virus)-x;
               break;
        	}
        }
    	dp[i][j][state]=1+LCS(i-1,j-1,newstate,s);
    	return dp[i][j][state];
    }

    dp[i][j][state]=max(LCS(i-1,j,state,s),LCS(i,j-1,state,s));
    return dp[i][j][state];
}

void print(int i,int j,int state,string s)
{
	//cout<<"called for "<<i<<" "<<j<<" "<<state<<endl;
	if(i==0 and j==0)
    {
    	if(dp[i][j][state]==1)
    		cout<<s1[i];

    	return;
    }
    
    if(i==0)
    {
     		if(dp[i][j][state]==1)
     			cout<<s1[i];
     		return;
     	
    }

    if(j==0)
    {
     		if(dp[i][j][state]==1)
     			cout<<s2[j];
     		
     		return;
    }     

    if(s1[i]==s2[j])
    {
    	if(state==1 and s1[i]==virus[0])
    	{
    		print(i-1,j-1,state,s);
    		return;
    	}

    	if(s1[i]==virus[state-1])
    	{
    		
    		print(i-1,j-1,state-1,s1[i]+s);
    		cout<<s1[i];
    		return;
    	}
         
     //   cout<<"here"<<endl;
    	s=s1[i]+s;
        int newstate=sz(virus);
        NFOR(x,sz(s),1)
        {
        	string temp=s.substr(0,x);
        	if(suff.count(temp))
        	{
               newstate=sz(virus)-x;
               break;
        	}
        }

    	print(i-1,j-1,newstate,s);
    	cout<<s1[i]; 
    	return;
    }

   // cout<<dp[i-1][j][state]<<" "<<dp[i-1][j][state]<<endl;
    if(dp[i-1][j][state]>dp[i][j-1][state])
    	print(i-1,j,state,s);
    else
    	print(i,j-1,state,s);

    return;
}
int main(){
  fast;
  
  fill(dp,-1);
 // fill(picked,0);
  cin>>s1>>s2>>virus;
  
  int l1=sz(s1);
  int l2=sz(s2);
  int lv=sz(virus);
  
  string haha="";
  FOR(i,0,lv-1)
  suff.insert(virus.substr(i,lv-i));

  int temp=LCS(l1-1,l2-1,lv,haha);
  cout<<temp<<endl;
  if(!temp)
  {
  	cout<<0;
  	return 0;
  }

  print(l1-1,l2-1,lv,haha);
  return 0;
}