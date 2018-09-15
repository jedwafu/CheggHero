#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int arr[100010];
char c;
int  main()
{
	int n,countodd0=0,countodd1=0,counteven0=0,counteven1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='r')
			arr[i]=0;
		else
			arr[i]=1;

		if(i%2)
		{
			if(c=='r')
				countodd0++;
			else
				countodd1++;
		}
		else
		{
			if(c=='r')
				counteven0++;
			else
				counteven1++;
		}
	}

	int temp=0;
	temp=min(counteven1,countodd0);
	int ans = temp+ (counteven1-temp) + (countodd0-temp);

	int temp2=0;
	temp2=min(countodd1,counteven0);
	int ans2= temp2+(countodd1-temp2)+(counteven0-temp2);

	cout<<min(ans,ans2)<<endl;
	

     


    
	return 0;

}