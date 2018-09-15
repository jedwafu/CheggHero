#include<iostream>
using namespace std;

int main()
{
	int n,i;
	long long int dec,ans=0;
	cin>>n;
	long long int arr[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	long long int dig[10]={9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000};
	
	for(i=9;i>=0;i--)
	{
		dec=n-arr[i];
		if(dec>=0)
		{
			dec=i+1;
			break;
		}
	}
	
	
	for(i=0;i<dec-1;i++)
	{
		ans+=dig[i]*(i+1);
	}
	
	i=dec;
	dec=n-arr[i-1]+1;
	ans+=(i)*dec;
	
	cout<<ans;
	
	return 0;
}
