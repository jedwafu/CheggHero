#include<iostream>
using namespace std;

int arr[501][501];
int m,n;

int countmax(int i)
{
	int j;
	int count=0,temp=0;
	
		j=0;
		
		while(j<m)
		
		{
		
		if(arr[i][j]==1)
		{
			while(arr[i][j]==1)
			{
				j++;
				temp++;
			}
			
			if(temp>count)
			count=temp;
			
			temp=0;		
		}
		j++;
	    }
	
	
	return count;
}

int checkmax(int *max)
{
	int i;
	int temp=0;
	for(i=0;i<n;i++)
	{
		if(max[i]>temp)
		temp=max[i];
	}
	return temp;
}

int main()
{
	int q,i,j,maximum;
	int max[501];
	cin>>n>>m>>q;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		cin>>arr[i][j];
	}
	
	for(i=0;i<n;i++)
	{
		max[i]=countmax(i);
	}
	
	while(q--)
	{
		cin>>i>>j;
		arr[i-1][j-1]=!arr[i-1][j-1];
		max[i-1]=countmax(i-1);
		maximum=checkmax(max);
		cout<<maximum<<endl;
	}
	return 0;
}
