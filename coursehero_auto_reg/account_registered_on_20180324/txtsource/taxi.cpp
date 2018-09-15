#include<iostream>

using namespace std;
int arr[100000];
int count[5]={0};
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		count[arr[i]]++;
	}
	
	count[0]=count[4]+count[3];
	if(count[3]>count[1])
	{
		if(count[2]%2==0)
		count[0]+=count[2]/2;
		else
		{
			count[0]+=count[2]/2+1;
		}
	}
	
	else
	{
		count[1]-=count[3];
		count[0]+=count[2]/2;
		if(count[2]%2==1)
		{
			count[0]++;
			count[1]=count[1]-2;
	    }
	    
			if(count[1]>0)
			{
				count[0]+=count[1]/4+!(count[1]%4==0);
			}
	
	}
	
	cout<<count[0];
	return 0;
}

