#include<bits/stdc++.h>
using namespace std;

struct node
{
	node *manager;
};

node ver[2001];
int main()
{
	int n,i,temp,count,max=0;
	node *help;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>temp;
		if(temp==-1)
		{
			ver[i].manager=NULL;
		}
		else
		ver[i].manager=&ver[temp];
	}
	
	for(i=1;i<=n;i++)
	{
		count=0;
		help=&ver[i];
		while(help!=NULL)
		{
			count++;
			help=help->manager;
			
		}
		
		if(count>max)
		max=count;
	}
	cout<<max;
	return 0;
}
