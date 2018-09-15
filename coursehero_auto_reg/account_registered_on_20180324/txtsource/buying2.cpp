#include<bits/stdc++.h>
using namespace std;

#define take(n) scanf("%d", &n)
int main()
{
	int t,n,x,i,small,sum;
	int arr[100];
	
	take(t);
	while(t--)
	{
		small=100;
		sum=0;
		take(n);
		take(x);
	
	
	for(i=0;i<n;i++)
	{
		take(arr[i]);
		if(arr[i]<small)
		{
			small=arr[i];
		}
		sum+=arr[i];
	}
	
	if(small<=sum%x)
	printf("%d\n",-1);
	
	else 
	printf("%d\n",sum/x);
    }
    
    return 0;
}
