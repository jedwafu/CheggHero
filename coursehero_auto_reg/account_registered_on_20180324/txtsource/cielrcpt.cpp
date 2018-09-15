#include<iostream>
using namespace std;

int main()
{
	int t,p,i,num;
	cin>>t;
	int pow[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
	while(t--)
	{
		num=0;
		cin>>p;
		for(i=11;i>=0;i--)
		{
			num+=p/pow[i];
			p=p%pow[i];
		}
		
		cout<<num<<endl;
	}
	
	return 0;
	
}
