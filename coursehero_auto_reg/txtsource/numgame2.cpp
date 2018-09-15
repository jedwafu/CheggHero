#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	long long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n%4==1)
		printf("ALICE\n");
		else
		printf("BOB\n");
	}
	return 0;
}
