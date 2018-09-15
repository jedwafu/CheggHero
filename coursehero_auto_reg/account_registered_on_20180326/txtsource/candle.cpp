#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,small,ind;
	int arr[10];
	
	cin>>t;
	
	while(t--)
	{
		cin>>arr[0];
		arr[0]++;
		small=arr[0];
		ind=0;
		
		for(i=1;i<10;i++)
		{
			cin>>arr[i];
			if(arr[i]<small)
			{
			  small=arr[i];
			  ind=i;
		    }
		}
		
		
		if(ind==0)
		{
			ind=1;
			for(i=0;i<small;i++)
			{
				ind*=10;
			}
			cout<<ind<<endl;
		}
		
		else
		{
			for(i=0;i<=small;i++)
			{
				cout<<ind;
			}
			cout<<endl;
		}
	}
	
	return 0;
}
