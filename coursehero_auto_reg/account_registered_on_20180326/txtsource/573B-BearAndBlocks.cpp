#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int arr[100001];
	int n;
	cin>>n;
	arr[0]=arr[n+1]=0;
	for(int i=1;i<=n;i++){
	    cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
	    arr[i]=min(arr[i],arr[i-1]+1);
    }
	for(int i=n;i>=0;i--){
	    arr[i]=min(arr[i],arr[i+1]+1);
	}
	sort(arr,arr+n+1);
	cout<<arr[n];
	return 0;
}