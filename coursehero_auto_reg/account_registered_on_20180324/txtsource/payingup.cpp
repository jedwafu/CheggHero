#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int arr[21];
	int t,flag;
	int sum,n,m,i,j,dummy;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		flag=0;
		dummy=1;
		dummy=(dummy<<n);
		
		for(i=1;i<dummy;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				if(i & (1<<j))
				{
					sum+=arr[j];
				}
				
			}
			if(sum==m)
			{
			cout<<"Yes"<<endl;
			flag=1;
			break;
		    }
		    
		}
		
		if(flag==0)
		cout<<"No"<<endl;
		 
		}
		return 0;
	}

