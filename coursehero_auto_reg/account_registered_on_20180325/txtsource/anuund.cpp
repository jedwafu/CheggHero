#include<bits/stdc++.h>
using namespace std;
int ori[100001];
int tem[100001];

int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		scanf("%d",&ori[i]);
	
	
	sort(ori,ori+n);
	j=0;
	for(i=1;i<n;i+=2)
	{
		
		tem[i]=ori[n-1-j];
		j++;
	}
	
	for(i=0;i<n;i+=2)
	{
		tem[i]=ori[n-1-j];
		j++;
	}
    
	for(i=0;i<n-1;i++)
	printf("%d ",tem[i]);
	printf("%d\n",tem[i]);
	 
   }
   return 0;
}
