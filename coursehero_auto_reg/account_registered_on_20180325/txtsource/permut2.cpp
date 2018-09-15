#include<iostream>

using namespace std;

int main()
{
	int n,i,k,flag;
	int array[100000];
	cin>>n;
	
	array[0]==0;
	
	while(n)
	{
		flag=1;
		
		for(i=1;i<=n;i++)
		{
			cin>>array[i];
		}
		
		for(i=1;i<=n;i++)
		{
			if(!(array[array[i]]==i))
			{
				flag=0;
				break;
			}
		}
		
		if(flag)
		cout<<"ambiguous\n";
		else
		cout<<"not ambiguous\n";
		
		cin>>n;
	}
	
	return 0;
	
}
