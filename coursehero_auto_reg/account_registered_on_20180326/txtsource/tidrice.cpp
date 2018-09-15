#include<bits/stdc++.h>
using namespace std;
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

map<string,int> m;

int main()
{
	int t,n,i;
	char arr[25];
	char c;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s %c",arr,&c);
		
		    if(c=='+')
		    m[arr]=1;
		    else
		    m[arr]=-1;
		
	    }
	    int sum=0;
	    tr(m,it)
	    {
	    	sum+=it->second;
		}
		cout<<sum<<endl;
	}
	return 0;
}
