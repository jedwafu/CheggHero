#include<bits/stdc++.h>
using namespace std;

#define inp(n) scanf("%d",&n)
#define put(n) printf("%d\n",n)

int main()
{
	int t,g,n,l,q,i;
	char c,d;
	inp(t);
	while(t--)
	{
		inp(g);
		while(g--)
		{
		
		scanf("%d %d %d",&l,&n,&q);
		
		if(l==1)
		{
			if(n%2)
			{
				if(q==1)
				put(n/2);
				else
				put(n-n/2);
			}
			else
			{
				put(n/2);
			}
		}
		
		if(l==2)
		{
			if(n%2)
			{
				if(q==1)
				put(n-n/2);
				else
				put(n/2);
			}
			else
			{
				put(n/2);
			}
        }
        }
    }
	return 0;
}
