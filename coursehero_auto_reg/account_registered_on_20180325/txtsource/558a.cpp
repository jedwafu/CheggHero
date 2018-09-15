#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=int(a) ;i<int(b);i++)

vector< pair<int,int> > lefts,rights;
int sizel=0,sizer=0;
int main()
{
	int n,x,a,ans=0;
	cin>>n;
	rep(i,0,n)
	{
		cin>>x>>a;
		if(x<0)
		{
		lefts.push_back(make_pair(-x,a));
		sizel++;
	    }
	    
		else
		{
		 rights.push_back(make_pair(x,a));
		 sizer++;
	    } 
	} 
	
	sort(lefts.begin(),lefts.end());
	sort(rights.begin(),rights.end());
	
	rep(i,0,min(sizel,sizer))
	{
		ans+=rights[i].second;
		ans+=lefts[i].second;
	}
	if(sizel>sizer)
	ans+=lefts[sizer].second;
	else if(sizer>sizel)
	ans+=rights[sizel].second;   
	
	cout<<ans;
}
