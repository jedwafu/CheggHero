#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
    
    int ans=0;
    if(a==1 and b==1)
    	ans=0,a=0,b=0;
    
	while(a>0 and b>0)
	{
		if(a<b)
		a+=1,b-=2;
	    else
	    a-=2,b+=1;

	    ans++;
	}
	cout<<ans<<endl;
	return 0;

}