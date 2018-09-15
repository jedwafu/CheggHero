#include<iostream>

using namespace std;

int arr[100][100];

void revhadamart(int n,int st1,int st2,int ed1,int ed2)
{
	int i,j;
	for(i=st1;i<=st2;i++)
	{
		for(j=ed1;j<=ed2;j++)
		arr[i][j]=!arr[i][j];
	}
}

void hadamart(int n,int st1,int st2,int ed1,int ed2)
{
   if(n==2)
   {
   	arr[st1][ed1]=1;
   	arr[st1][ed2]=1;
   	arr[st2][ed1]=1;
   	arr[st2][ed2]=0;
	   }	
	
	else
	{
		hadamart(n/2,st1,st1+(n-1)/2,ed1,ed1+(n-1)/2);
		hadamart(n/2,st1+n/2,st1+n-1,ed1,ed1+(n-1)/2);
		hadamart(n/2,st1,st1+(n-1)/2,ed1+n/2,ed1+n-1);
		hadamart(n/2,st1+n/2,st1+n-1,ed1+n/2,ed1+n-1);
		
		revhadamart(n/2,st1+n/2,st1+n-1,ed1+n/2,ed1+n-1);
	}
	
}


int main()
{
	int n,i,j;
	cin>>n;
	
		
	hadamart(n,0,n-1,0,n-1);
	
	for(i=0;i<n;i++)
	{
	 for(j=0;j<n;j++)
	 cout<<arr[i][j]<<" ";
	 
	 cout<<endl;
    }
	return 0;
	
}
