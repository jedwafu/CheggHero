#include<bits/stdc++.h>
using namespace std;

char arr[110];

int main()
{
	int t,k,i,dig;
	
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k%25==0)
		dig=k/25+k;
		else
		dig=k/25 +1+k;
	
	
	for(i=dig-1;i>=0;i--)
	{
		arr[i]='a'+(dig-1-i)%26;
	}
	for(i=0;i<dig;i++)
	{
		cout<<arr[i];
	}
	cout<<endl;
    }
    
    return 0;
}
