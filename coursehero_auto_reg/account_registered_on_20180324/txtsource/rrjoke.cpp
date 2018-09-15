#include<iostream>

using namespace std;

int main()
{
	int t,i,n,m;
	cin>>t;
	
	while(t--)
	{
	   cin>>n;
	   
	   for(i=0;i<n;i++)
	   {
	     cin>>m>>m;	 
		   }
		   	
		   m=1;
		   for(i=2;i<=n;i++)
		   m=m^i;
		   
		   cout<<m<<endl;
	}
	
	return 0;
	
}
