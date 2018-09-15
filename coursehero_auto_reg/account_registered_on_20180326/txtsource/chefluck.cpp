#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,i;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		i=0;
		while(i<=n)
		{
			if((n-i)%7==0)
			break;
			else
			i=i+4;
		}
		if(i>n)
		cout<<-1<<endl;
		else
		cout<<n-i<<endl;
	}
	return 0;
}
