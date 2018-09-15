#include<bits/stdc++.h>
using namespace std;

long long arr[31];

int main()
{
	int t;
	cin>>t;
	arr[0]=1;
	
	for(int i=1;i<=30;i++)
	{
		arr[i]=2*arr[i-1];
	}
	
	while(t--)
	{
	  long long int n;
	  cin>>n;
	  int flag=0;
	  
	  for(int i=0;i<=30;i++)
	  {
	  	if(arr[i]==n+1)
	  	flag=1;
	  }
	  
	  if(flag==0)
	  cout<<-1<<endl;
	  else
	  {
	  	if(n==1)
	  	cout<<2<<endl;
	  	else
	  	cout<<(n-1)/2<<endl;
	  }
    }
    return 0;
}
