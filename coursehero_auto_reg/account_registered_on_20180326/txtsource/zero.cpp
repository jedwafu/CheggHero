#include<bits/stdc++.h>
using namespace std;
char arr[200010];

int main()
{
	int n,i,count1=0,count2=0;
	cin>>n;
	scanf("%s",arr);
	
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='1')
		count1++;
		else
		count2++;
	}
	cout<<abs(count1-count2)<<endl;
	
	return 0;
}
