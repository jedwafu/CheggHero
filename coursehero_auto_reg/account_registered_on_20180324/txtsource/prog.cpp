#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int t;
	float o,r,s;
	
	cin>>t;
	while(t--)
	{
		cin>>o>>r>>s;
		
		s=(o*r+s)/(o+1);
		printf("%.2f\n,s");
	}
	
	return 0;
}
