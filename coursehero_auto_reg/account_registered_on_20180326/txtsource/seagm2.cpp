#include<bits/stdc++.h>
using namespace std;

long double inp,temp,sum1,sum2;

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		
		sum2=0;
		temp=(long double)1.0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%Lf",&inp);
				inp*=25;
				temp*=inp;
		    }
		    
		   
		    
		    if(i==0)
		    sum1=temp;
		    
		    sum2+=temp;
	
		    temp=(long double)1;
		}
		
		if(abs(sum1-0.0)<.000001)
		printf("%Lf\n",(long double)0);
		
		else
		{
		printf("%Lf\n",(long double)abs(sum1/sum2));
		}
	}
	return 0;
}
