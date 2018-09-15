#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[100001];
    int n;
    cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	sort(arr,arr+n,greater<int>());
	int i=0;
	int j=n-1;
	int ans=0;
	while(i<=j){
	    ans+=1;
	    int four=4-arr[i];
	    while(arr[j]<=four && i<=j){
	        four=four-arr[j];
	        j--;
	    }
	    i++;
	}
	cout<<ans;
	return 0;
}
