#include<bits/stdc++.h>
using namespace std;

#define inp(n) scanf("%d",&n)

int speed[10000];
int main()
{
	int t,n,i,cur,ans;
	inp(t);
	while(t--)
	{
		inp(n);
		inp(speed[0]);
		cur=speed[0];
		ans=1;
		
		for(i=1;i<n;i++)
		{
			inp(speed[i]);
			if(speed[i]<=cur)
			{
				ans++;
				cur=speed[i];
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
