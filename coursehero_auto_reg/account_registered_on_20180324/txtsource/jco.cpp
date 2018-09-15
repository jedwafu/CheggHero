#include<iostream>
using namespace std;

int main()
{
	int t,n,k,i;
	long long int sum;
	long long int arr[1000];
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		
		if(sum%2==0 && k==1)
		{
			cout<<"odd"<<endl;
		}
		
		else
		{
			cout<<"even"<<endl;
		}
	}
	
	return 0;
}
