#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	double p,s;
	double y1,y2,x1,x2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf",&p,&s);
		
		p=p/4;
		s=s/2;
		
		y1=(p+sqrt(p*p-3*s))/3;
		y2=(2*p-3*y1)/3;
		
		x1=s-y1*(p-y1);
		x2=s-y2*(p-y2);
		
		printf("%.2lf\n",max(x1*y1,x2*y2));
	}
	
	return 0;
}
