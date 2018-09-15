#include<bits/stdc++.h>
using namespace std;

double fac[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
double pows[11]={1,2,4,8,16,32,64,128,256,512,1024};
char arr[11];
int sum=0,counts=0;
int newsum=0;
double ans=0;
int main()
{
	scanf("%s",arr);
	int len=strlen(arr);
	for(int i=0;i<len;i++)
	{
		if(arr[i]=='+')
		sum++;
		else
		sum--;
	}
	scanf("%s",arr);
	
	for(int i=0;i<len;i++)
	{
		if(arr[i]=='+')
		newsum++;
		else if(arr[i]=='-')
		newsum--;
		else
		counts++;
	}
	
	if(counts==0)
	{
		if(sum==newsum)
		printf("%.9f",1.0);
	     
		else
		printf("%.9f",0.0);
		return 0;
	}
	
	sum=sum-newsum;
	if((sum+counts)%2==1 || sum+counts<0 ||sum>counts)
	printf("%.9f",0.0);
	else
	{
		int n=(sum+counts)/2;
		ans=fac[counts]/(fac[n]*fac[counts-n]*pows[counts]);
		printf("%.9f",ans);
	}
	return 0;
}
