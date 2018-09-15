#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int arr[100];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	if(n==1)
	{
		if(arr[0]==0)
			cout<<"UP"<<endl;
		else if(arr[0]==15)
			cout<<"DOWN"<<endl;
		else
			cout<<-1<<endl;
	}
	else
	{
		if(arr[n-1]==15)
		{
			cout<<"DOWN"<<endl;
		}
		else if(arr[n-1]==0)
			cout<<"UP"<<endl;
		else if(arr[n-2]<arr[n-1])
			cout<<"UP"<<endl;
		else
			cout<<"DOWN"<<endl;
	}
	return 0;
}