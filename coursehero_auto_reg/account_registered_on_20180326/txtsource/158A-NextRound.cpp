#include <iostream>
using namespace std;

int main() {
	int arr[51];
	int n,k,result=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	k-=1;
	int val=arr[k];
	for(int i=0;i<n;i++){
	    if(arr[i]>=val && arr[i]!=0)
	    result++;
	}
    cout<<result;
	return 0;
}
