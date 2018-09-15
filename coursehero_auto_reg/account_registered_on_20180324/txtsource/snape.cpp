#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	float b,ls,rs;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%f %f",&b,&ls);
		
		rs=sqrt((ls*ls)-(b*b));
		printf("%f ",rs);
		
        rs=sqrt((ls*ls)+(b*b));
		printf("%f\n",rs);
	}
	
	return 0;
}
