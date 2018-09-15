#include<bits/stdc++.h>
using namespace std;

int arr[51][51];
int main()
{
	int n,a,b,c,d,gs=0,fs=0;
	cin>>n;
	
	int temp=n*(n-1);
	
	for(int i=0;i<=n;i++)
	{
		arr[i][0]=arr[0][i]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		cin>>arr[i][j];
		
		if(arr[i][j]==temp)
		{
			a=i,b=j;
		}
		
	    }
	}
	
	std::cout<<a<<" "<<b<<"\n";
	fs+=arr[a][b];
	arr[a][b]=0;
	fflush(stdout);
	
	int flag=1;
	while(flag==1)
	{
		std::cin>>c>>d;
		gs+=arr[c][d];
		arr[c][d]=0;
		b=-1,a=-1;
		int max1=-1,max2=-1;
		int min1=100000,help=1;
		
		for(int i=1;i<=n;i++)
		{
			if(arr[d][i]>0)
			{
				if(arr[d][i]>max2)
				{
					max2=arr[d][i];
					b=i;
				}
				
				for(int j=1;j<=n;j++)
				{
					max1=max(max1,arr[i][j]);
				}
				
				if(max1<arr[d][i])
				{
					b=i;
					help=0;
					break;
				}
			}
			
			if(help==0)
			break;
		
		}
		
		max1=-1;
		for(int i=1;i<=n;i++)
		{
			max1=max(arr[b][i],max1);
		}
		
		if(b==-1)
		{
		  flag=0;
	    }
		 
		
		else
		{
			cout<<d<<" "<<b<<endl;
			fs+=arr[d][b];
			arr[d][b]=0;
			fflush(stdout);
			if(max1==0)
			{
			flag=0;
		    }
		}
	}
	
	return 0;
}
