#include<bits/stdc++.h>
using namespace std;

int arr[1001];
int done[1001];
int start[1001];

int find(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(done[i]==0)
		return i;
	}
}

int main()
{
	int n,i,k=0,flag=1,count=0,tcount=0;
	int next;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	
	for(i=1;i<=n;i++)
	done[i]=0;
	
	while(count<n)
	{
		k++;
		start[k]=find(n);
		
		done[start[k]]=1;
		count++;
		
		//printf("%d ",start[k]);
		next=arr[start[k]];
		
		while(next!=start[k])
		{
			count++;
			done[next]=1;
			//printf("%d ",next);
			next=arr[next];
		}
		
		//printf("%d\n",start[k]);
	}
	
	printf("%d",k);
	
	for(i=1;i<=k;i++)
	{
		printf("\n%d ",start[i]);
		next=arr[start[i]];
		
		while(next!=start[i])
		{
			printf("%d ",next);
			next=arr[next];
		}
	   printf("%d",start[i]);
	}
	
	return 0;
}
