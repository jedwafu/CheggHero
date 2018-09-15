#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n);

int arr[1000010];
int main()
{
	int t,k,i;
	long long int sum;
	s(t);
	while(t--)
	{
		int flag=1;
		sum=0;
		s(k);
		for(i=0;i<k;i++)
		{
			s(arr[i]);
		}
		
		sum=arr[k-1];
		for(i=k-2;i>=0;i--)
		{
			if(sum%2==0)
			{
				sum=arr[i]+sum/2;
			}
			else
			{
				flag=0;
				i=-1;
			}
		}
		
		if(flag)
		{
			if(sum==1)
			cout<<"Yes\n";
			else
			cout<<"No\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return 0;
}
