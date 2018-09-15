#include<iostream>
using namespace std;

int main()
{
	int w,m,i;
	int base[101]={0};
	cin>>w>>m;
	
	for(i=0;i<101;i++)
	{
		if(m==0)
		break;
		
		base[i]=m%w;
		m=m/w;
	}
	
	i=0;
	int flag=1;
	while(i<101)
	{
		if(base[i]==1|| base[i]==0)
		i++;
		
		else if(base[i]==w-1 || base[i]==w && i<100)
		{
			base[i+1]++;
			i++;
		}
		
		else
		{
			flag=0;
			break;
		}
	}
	
	if(flag==1)
	cout<<"YES";
	else cout<<"NO";
	
	return 0;
	
}
