#include<bits/stdc++.h>
using namespace std;

#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
map<int,int> m;

int main()
{
	int n1,n2,n3,i;
	int temp,count=0;
	cin>>n1>>n2>>n3;
	for(i=0;i<n1+n2+n3;i++)
	{
		scanf("%d",&temp);
		m[temp]++;
	}
	
	tr(m,it)
	{
		if(it->second>=2)
		count++;
	}
	printf("%d\n",count);
	tr(m,it)
	{
		if(it->second>=2)
		printf("%d\n",it->first);
	}
	
	return 0;
}
