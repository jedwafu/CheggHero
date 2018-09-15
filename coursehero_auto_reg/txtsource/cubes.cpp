#include<iostream>
using namespace std;

int main()
{
	int n,sum=1,cur=1;
	cin>>n;
	
	while(n>=0)
	{
		n=n-sum;
		cur++;
		sum+=cur;
	}
	cout<<cur-2;
	return 0;
}
