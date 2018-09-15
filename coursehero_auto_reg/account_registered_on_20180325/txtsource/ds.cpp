#include<bits/stdc++.h>
using namespace std;


stack<int>s;

int input[1000];
int small_r[1000];
int small_l[1000];

int maxarea(int n)
{
	for(int i=1;i<=n;i++)
    {
	    if(s.empty())
	    s.push(i);
	    
	    else
	    {
	    	while(input[s.top()]>input[i])
	    	{
	    		small_r[s.top()]=i-1;
	    		s.pop();
	 		}
	 		s.push(i);
	 	}
	}
	
	while(s.empty()==false)
	{
		small_r[s.top()]=n;
		s.pop();
	}
	
	for(int i=n;i>=1;i--)
	{
		if(s.empty())
		s.push(i);
		
		else
		{
			while(input[s.top()]>input[i])
			{
				small_l[s.top()]=i+1;
				s.pop();
			}
			s.push(i);
		}
	}
	
	while(s.empty()==false)
	{
		small_l[s.top()]=1;
		s.pop();
	}
	
	int area=0,maxi=0;
	for(int i=1;i<=n;i++)
	{
		area=(small_r[i]-small_l[i]+1)*input[i];
		maxi=max(area,maxi);
	}
	
	return maxi;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	  cin>>input[i];
	  small_l[i]=small_r[i]=1;
    }
	
	int ans=maxarea(n);
	cout<<ans<<endl;
	
	return 0;
}
