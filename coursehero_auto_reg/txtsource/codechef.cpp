#include<iostream>

char bin1[100002];
int bin[100002];
int sum[100002];
using namespace std;
int main()
{
	int t,n,k,i,j;
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>bin1[i];
		}
		
		for(i=0;i<n;i++)
		{
			if(bin1[i]=='1')
			bin[i]=1;
			else
			bin[i]=0; 
		}
		
		int count=0;
		int count2=0;
		if(k==1)
		{
			sum[0]=1;
			if(sum[0]!=bin[0])
			count=1;
			
			for(i=0;i<n-1;i++)
			{
				sum[i+1]=!sum[i];
				
				if(sum[i+1]!=bin[i+1])
				{
					count++;
				}
				
		    }
		    
		    sum[0]=0;
			if(sum[0]!=bin[0])
			count=1;
			
			for(i=0;i<n-1;i++)
			{
				sum[i+1]=!sum[i];
				
				if(sum[i+1]!=bin[i+1])
				{
					count2++;
				}
				
				
			}
			
			if(count2<count)
			{
			  count=count2;
			  for(i=0;i<n;i++)
			  bin[i]=sum[i];
				
			}
			
			else
			{
				for(i=0;i<n;i++)
				bin[i]=!sum[i];
			}
		}
		
		else
		{
		
		for(i=0;i<(n-k);i++)
		{
			sum[i]=0;
			for(j=0;j<k+1;j++)
			sum[i]=sum[i]+bin[i+j];
			
			if(sum[i]==k+1 || sum[i]==0)
			{
				sum[i]=1;
			}
			else
			sum[i]=0;
		}
		
		i=0;
		int flag;
	    count=0;
		while(i<n-k)
		{
			if(sum[i]==1)
			{
				count++;
				flag=0;
				for(j=i+1;j<i+k+1;j++)
				{
					if(sum[j]==1)
					{flag=1;
					 break;
				    }
				}
				
				if(flag==0)
				bin[i+k/2]=!bin[i+k/2];
				
				else
				bin[i+k]=!bin[i+k];
				
				i=i+k+1;
			}
			else
			i=i+1;
		}
		
	    }
		cout<<count<<endl;
		for(i=0;i<n;i++)
		{
			if(bin[i]==1)
			bin1[i]='1';
			else
			bin1[i]='0';
			
			cout<<bin1[i];
		}
		cout<<endl;
	}
	return 0;
}
