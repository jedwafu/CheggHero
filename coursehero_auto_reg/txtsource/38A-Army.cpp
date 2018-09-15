#include <iostream>
using namespace std;

int main() {
    int arr[101];
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
	   cin>>arr[i]; 
	}
	int a,b;
	cin>>a>>b;
	int result=0;
	for(int i=a-1;i<b-1;i++){
	    result+=arr[i];
	}
	cout<<result;
	return 0;
}
