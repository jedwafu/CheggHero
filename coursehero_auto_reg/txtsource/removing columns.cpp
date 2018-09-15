#include<bits/stdc++.h>
using namespace std;

char arr[100][100];
int deci[100]={0};
int prev=-1;
char c;


int main()
{
	int n,m,i,j,k,count=0,flag;
	cin>>n>>m;
	
	for(i=0;i<n;i++)
	{
		c=getchar();
		
		for(j=0;j<m;j++)
		cin>>arr[i][j];
		
	}

    
    
	for(i=0;i<m;i++)
	{
		flag=1;//clear
		
		
		for(j=0;j<n-1;j++)
		{
		   if(arr[j][i]>arr[j+1][i])
		   {
		   	   
		   	    if(deci[j]==0)
		   	    {
				   
		   	    	flag=2;//removed
		   	    	count++;
		   	    	break;
				}
		
			}   
	    }
	    
	    
	    if(flag==1)
	    {
	    	for(j=0;j<n-1;j++)
	    	{
	    		if(arr[j][i]<arr[j+1][i])
	    		deci[j]=1;
			}
		}
		
    }
    
    cout<<count;
    return 0;
    
}
