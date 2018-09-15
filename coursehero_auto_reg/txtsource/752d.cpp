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

map<string, vector<int> > beauty;
map<string, int> odd;
map<string, int> even;
map<string, bool> done;
bool ispalindrome(string s)
{
   int len=s.length();
   FOR(i,0,len-1)
   {
   	if(s[i]!=s[len-1-i])
   		return false;
   }
   return true;
}

int main(){
  fast;
  int n,k;
  cin>>k>>n;
  odd.clear();
  even.clear();
  beauty.clear();
  done.clear();
  FOR(i,1,k)
  {
  	string s;
  	int b;
  	cin>>s>>b;
    beauty[s].pb(b);
    done[s]=false;
  }
  
  map<string, vector<int> >::iterator it;
  for(it = beauty.begin(); it != beauty.end(); it++) 
  {
  	sort(it->S.begin(),it->S.end());
  	reverse(it->S.begin(),it->S.end());
  }
  
  int ans=0;
  int maxi=0;
  int sum=0;
  string s1,s2;
  
  for(it = beauty.begin(); it != beauty.end(); it++)
  {
  	if(ispalindrome(it->F))
  	{
       int k=1;
       int sizes=sz(it->S);
       int temp=it->S[0];
       while(k+1<sizes and it->S[k]+it->S[k+1] > 0)
       {
         temp+=it->S[k]+it->S[k+1];
         k+=2;
       }
       odd[it->F]=temp;

       k=0;
       temp=0;
       while(k+1<sizes and it->S[k]+it->S[k+1] > 0)
       {
         temp+=it->S[k]+it->S[k+1];
         k+=2;
       }
       even[it->F]=temp;
       sum+=even[it->F];
  	}
  	else if(!done[it->F])
   	{

  	    s1=it->F;
  	    s2=s1;
  	    reverse(s2.begin(),s2.end());
  	    if(beauty.count(s2))
  	    {
  	    	int sizes=min(sz(beauty[s1]),sz(beauty[s2]));
  	    	for(int i=0;i<sizes;i++)
  	    	{
               if(beauty[s1][i]+beauty[s2][i]>0)
               ans+= beauty[s1][i]+beauty[s2][i];
               else
               break;
  	    	}
  	    	done[it->F]=true;
  	    	done[s2]=true;
  	    }
  	}
  }
  
  maxi=sum;
  
  for(it = beauty.begin(); it != beauty.end(); it++)
  {
  	int temp=0;
  	if(ispalindrome(it->F))
  	{
       temp=sum-even[it->F]+odd[it->F];
       maxi=max(maxi,temp);
  	}
  }
  
  cout<<ans+maxi;
  return 0;
}