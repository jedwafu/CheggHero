#include<iostream>
#include<stdio.h>

using namespace std;

int calc(int num)
{
	if(num==0||num==2||num==6||num==9)
	return 2;
	
	if(num==8||num==5)
	return 9-num;
	
	if(num==3||num==4)
	return 3;
	
	if(num==7)
	return 5;
	
	if(num==1)
	return 7;
}

int main()
{
	int num;
	cin>>num;
	
	int prod=calc(num/10);
	prod=prod*calc(num%10);
	
	cout<<prod;
	
	return 0;
}
