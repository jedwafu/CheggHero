#include<iostream>
using namespace std;

int arr[100001];

int main()
{
	int t,n,i,flag,small;
	cin>>t;
	
	while(t--)
	{
		flag=1;
		small=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			
			if(arr[i]==1)
			{
				flag=0;
			}
			if(arr[i]<arr[small])
			small=i;
		}
		
		int temp=arr[small];
		arr[small]=arr[n-1];
		arr[n-1]=temp;
		
		if(flag==0)
		{
			cout<<-1<<endl;
			continue;
		}
		int sum=0;
		for(i=0;i<n-1;i++)
		{
			 sum = sum +arr[i];
		}
		cout<<sum +2<<endl;
	}
	
	return 0;
}
