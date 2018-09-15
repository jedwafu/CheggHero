#include<bits/stdc++.h>
using namespace std;

int arr[1000];
int sec[1000];

int count_inversion(int start,int end)
{
	if(start==end)
	return 0;
	
	int inv1=count_inversion(start,(start+end)/2);
	int inv2=count_inversion((start+end)/2+1,end);
	int mid=(start+end)/2;
	
	int p=start,q=mid+1,r=start;
	int inv=0;
	
	while(r<=end)
	{
		if(p==mid+1)
		{
			while(q<=end)
			{
			  sec[r]=arr[q];
			  r++;
			  q++;
		    }
		}
		
		else if(q==end+1)
		{
			while(p<=mid)
			{
				sec[r]=arr[p];
			    p++;
			    r++;
			}
		}
		
		else if(arr[p]<=arr[q])
		{
			sec[r]=arr[p];
			p++;
			r++;
		}
		
		else
		{
			sec[r]=arr[q];
			inv+=mid-p+1;
			r++;
			q++;
		}
	}
	
	for(int i=start;i<=end;i++)
	{
		arr[i]=sec[i];
	}
	
	return inv1 + inv2 + inv;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	int ans=count_inversion(1,n);
	cout<<ans;
}
