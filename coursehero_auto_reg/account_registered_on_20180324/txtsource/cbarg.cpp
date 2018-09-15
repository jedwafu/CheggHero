#include<iostream>
using namespace std;

long long int arr[100001];
int main()
{
	int t,n,i;
	long long int cur=0;
	long long int add=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cur=0;
		add=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			
			if(arr[i]>cur)
			add+=arr[i]-cur;
			
			cur=arr[i];
		}
		
		cout<<add<<endl;
	}
	
	return 0;
}
