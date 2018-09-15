#include<iostream>
using namespace std;

long long int arr[100001];
int main()
{
	int t,n,i;
	long long int cur=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cur=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			
			if(arr[i]>cur)
			cur=arr[i];
		}
		
		cout<<cur[i]<<endl;
	}
	
	return 0;
}
