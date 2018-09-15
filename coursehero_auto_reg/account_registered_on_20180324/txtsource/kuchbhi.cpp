#include <bits/stdc++.h>
using namespace std;


int arr[100];
int binarys(int left,int right,int key)
{
	if(left>right)
		return -1;
	if(left==right and arr[left]==key)
		return left;

	if(arr[left]>key or arr[right]<key)
		return -1;

	if(arr[left]==key)
		return left;

	int mid=(left+right)/2;

	if(arr[mid]<key)
		left=mid+1;
    if(arr[mid]>=key)
        right=mid;

    return binarys(left,right,key);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
    
    int key;
    cin>>key;
    int ans= binarys(0,n-1,key);
    cout<<ans;
    return 0;

}