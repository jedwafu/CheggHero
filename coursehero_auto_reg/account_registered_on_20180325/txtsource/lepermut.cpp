#include<bits/stdc++.h>
using namespace std;

#define s(n) scanf("%d",&n)
int main()
{
	int t,n,i;
	int arr[110];
	
	s(t);
	while(t--)
	{
		int flag=1;
		s(n);
		for(i=0;i<n;i++)
		{
			s(arr[i]);
		}
		for(i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
		      int temp=arr[i];
		      arr[i]=arr[i+1];
		      arr[i+1]=temp;
		      i++;
			}
		}
		for(i=0;i<n;i++)
		{
			if(arr[i]!=i+1)
			{
			printf("NO\n");
			i=n;
			flag=0;} 
		}
		if(flag)
		printf("YES\n");
	}
	return 0;
}
