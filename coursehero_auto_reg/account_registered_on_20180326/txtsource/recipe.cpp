#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	
	else
	return gcd(b,a%b);
}

int arr[50];
int main()
{
	int t,n,i,d;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		d=gcd(arr[0],arr[1]);
		for(i=2;i<n;i++)
		{
			d=gcd(d,arr[i]);
		}
		
		for(i=0;i<n;i++)
		{
			arr[i]/=d;
			cout<<arr[i]<<" ";
		}
		
		cout<<endl;
	}
	return 0;
}
