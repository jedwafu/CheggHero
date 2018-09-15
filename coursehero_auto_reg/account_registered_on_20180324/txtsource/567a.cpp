#include<bits/stdc++.h>
using namespace std;


long long int arr[100010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<arr[1]-arr[0]<<" "<<arr[n-1]-arr[0]<<endl;
	
	for(int i=1;i<n-1;i++)
	{
		cout<<min(arr[i]-arr[i-1],arr[i+1]-arr[i])<<" "<<max(arr[i]-arr[0],arr[n-1]-arr[i])<<endl;
	}
	
	cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0];
	
	return 0;
}
