#include<bits/stdc++.h>
using namespace std;

bool done[1000010];

int main()
{
	int n,temp;
	int cur=0,ans=0;
	char c;
	cin>>n;
	
	for(int i=0;i<1000010;i++)
	done[i]=false;
	
	for(int i=0;i<n;i++)
	{
		cin>>c;
		cin>>temp;
		if(c=='+')
		{
			cur++;
			done[temp]=true;
			ans=max(cur,ans);
		}
		
		if(c=='-')
		{
			if(done[temp]==true)
		     {
		     	cur--;
		     	done[temp]=false;
			 }
			 else
			 {
			 	ans++;
			 }
		}
	}
	
	cout<<ans;
	return 0;
}
