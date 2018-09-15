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

int main()
{
  fast;
  char ch;
  int s1=0;
  int s2=0;
  int tot=0;
  bool flag=false;
  while(scanf("%c",&ch)!=EOF)
  {
  	if(ch=='\n')
  	{
  		s1=0;
  		s2=0;
  		tot=0;
  		flag=false;
  		continue;
  	}

  	if(flag)
  		continue;

  	if(tot%2==0)
  	{
  		if(ch=='1')
  			s1++;
  	}
  	if(tot%2==1)
  	{
  		if(ch=='1')
  			s2++;
  	}
  	tot++;

  	if(tot<=10)
  	{
  		if(tot%2==0)
  		{
  			if(s1>s2+(10-tot)/2)
  			{
  				flag=true;
  				cout<<"TEAM-A"<<" "<<tot<<endl;
  			}
  			else if(s2>s1+(10-tot)/2)
  			{
  				flag=true;
  				cout<<"TEAM-B"<<" "<<tot<<endl;
  			}
  		}
  		else
  		{
  			if(s1>s2+((10-tot)/2)+1)
  			{
  				flag=true;
  				cout<<"TEAM-A"<<" "<<tot<<endl;
  			}
  			else if(s2>s1+(10-tot)/2)
  			{
  				flag=true;
  				cout<<"TEAM-B"<<" "<<tot<<endl;
  			}
  		}
  	}

  	if(tot>10 and tot%2==0)
  	{
  		if(s1>s2)
  		{
  			flag=true;
  			cout<<"TEAM-A"<<" "<<tot<<endl;
  		}
  		if(s2>s1)
  		{
  			flag=true;
  			cout<<"TEAM-B"<<" "<<tot<<endl;
  		}
  	}

  	if(tot==20 and s1==s2)
  	{
  		flag=true;
  		cout<<"TIE"<<endl;
  	}
  	
  }

  return 0;
}