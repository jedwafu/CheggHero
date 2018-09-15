#include<iostream>
using namespace std;

int main()
{
	int n,i;
	cin>>n;
	
	if(n==1||n==2)
	{
	  cout<<1<<endl;
	  cout<<1;
	  return 0; 
    }
	
	if(n==3)
	{
		cout<<2<<endl;
		cout<<1<<" "<<3;
		return 0;
	 } 
	 
	 if(n==4)
	 {
	 	cout<<4<<endl;
	 	cout<<2<<" "<<4<<" "<<1<<" "<<3;
	 	return 0;
	 }
	 
	else
	{
		cout<<n<<endl;
		if(n%2)
		{
			for(i=1;i<=n/2;i++)
			{
				cout<<i<<" "<<i+(n+1)/2<<" ";
			}
			
			cout<<i;
		}
		
		else
		{
			for(i=1;i<=n/2;i++)
			{
				cout<<i<<" "<<i+n/2<<" ";
			}
		}
	}
	
	return 0;
}

