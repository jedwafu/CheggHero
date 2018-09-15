#include<bits/stdc++.h>
using namespace std;
#define eps 0.0000000001
#define big 1000000;

float points[2][2000];
float slopes[2000];

int main()
{
	int k,i,j,n,count,tcount=0;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>points[0][i]>>points[1][i];
	}
	
	for(i=0;i<n;i++)
	{
		
		count=1;
		
		for(j=i+1;j<n;j++)
		{
			
			if((points[0][j]-points[0][i])!=0)
			slopes[j]=((points[1][j]-points[1][i])/(points[0][j]-points[0][i]));
			else
			slopes[j]=big;
			
		}
		
		sort(slopes,slopes+n);
		
		for(j=i+1;j<n;j++)
		cout<<slopes[j]<<endl;
		//for(k=0;k<n;k++)
		//{
		//	cout<<slopes[k]<<" "<<points[0][k]<<" "<<points[1][k]<<endl;
		//}
		 //cout<<"over"<<endl;
		 
		k=i+1;
		while(k<n)
		{
		
			count=1;
			if(abs(slopes[k]-slopes[k+1])<=eps)
			{
				
				while(abs(slopes[k]-slopes[k+1])<=eps)
				{
					//cout<<slopes[k]<<" "<<slopes[k+1];
					count++;
					k++;
					
				}
				
				tcount+=(count*(count-1))/2;
			}
			
			k++;
		}
	}
	
	n=(n*(n-1)*(n-2))/6;
	cout<<n-tcount;

    return 0;	
}
