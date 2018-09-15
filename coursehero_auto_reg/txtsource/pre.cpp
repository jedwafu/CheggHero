#include<bits/stdc++.h>
using namespace std;

bool prime(int i)
{
	for(int j=2;j<=sqrt(i);j++)
	{
		if(i%j==0)
		return false;
	}
	return true;
}

bool palindrome(int i)
{
	int n=0;
	int temp=1;
	int j=i;
	while(j!=0)
	{
	 temp=j%10;
	 j=j/10;
	 n=n*10+temp;
    }
    if(n==i)
    return true;
    else
    return false;
}
int main()
{
	for(int i=1000000;i<2000000;i++)
	{
		if(prime(i) and palindrome(i))
		{
		  cout<<i<<endl;
		  return 0;
	    }
	} 
}
