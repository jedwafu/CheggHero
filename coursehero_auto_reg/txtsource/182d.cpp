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

vi div1,div2;
int main(){
  fast;
  string s1,s2;
  cin>>s1>>s2;
  int len1=s1.length();
  int len2=s2.length();
  int t1=sqrt(len1);
  int t2=sqrt(len2);

  FOR(i,1,t1)
  if(!(len1%i))
  {
      div1.pb(i);
      div1.pb(len1/i);
  }
  
  FOR(i,1,t2)
  if(!(len2%i))
  {
      div2.pb(i);
      div2.pb(len2/i);
  }
  
  sort(div1.begin(),div1.end());
  sort(div2.begin(),div2.end());
  string ans1,ans2;

  FOR(i,0,sz(div1)-1)
  {
  	string temp = s1.substr(0,div1[i]);
  	bool flag=true;
  	for(int j=0;j<len1;j+=div1[i])
  	{
      if(temp.compare(s1.substr(j,div1[i])))
      {
      	flag=false;
      	break;
      }
  	}
  	if(flag)
  	{
  		ans1=temp;
  		break;

  	}
  }
   
   FOR(i,0,sz(div2)-1)
  {
  	string temp = s2.substr(0,div2[i]);
  	bool flag=true;
  	for(int j=0;j<len2;j+=div2[i])
  	{
      if(temp.compare(s2.substr(j,div2[i])))
      {
      	flag=false;
      	break;
      }
  	}
  	if(flag)
  	{
  		ans2=temp;
  		break;

  	}
  }
  //cout<<ans1<<" "<<ans2<<endl;
  ll ans=0;
  if(ans1.length()<ans2.length())
  {
  	string temp=ans1;
  	for(int j=0;j<ans2.length();j+=ans1.length())
  	{
      if(temp.compare(ans2.substr(j,ans1.length())))
      {
      	cout<<0;
      	return 0;
      }
  	}
    

  	int num=len2/ans2.length();
  	FOR(i,1,num)
  	{
  		if(num%i==0)
  		{
  			int d=ans2.length()*i;
            if(len1%d==0)
            	ans++;
  		}
  	}

  	cout<<ans;
  }
  else
  {
     string temp=ans2;
  	for(int j=0;j<ans1.length();j+=ans2.length())
  	{
      if(temp.compare(ans1.substr(j,ans2.length())))
      {
      	cout<<0;
      	return 0;
      }
  	}

  	int num=len1/ans1.length();
  	FOR(i,1,num)
  	{
  		if(num%i==0)
  		{
  			int d=ans1.length()*i;
            if(len2%d==0)
            	ans++;
  		}
  	}
  	
  	cout<<ans;
  }
  

  return 0;
}