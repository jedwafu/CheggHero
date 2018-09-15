#include <iostream>
using namespace std;
int maxee(int a,int b){
    return a>b?a:b;
}
int main() {
	int arr[101],arr1[101];
	int n,m;
	cin>>n>>m;
	int flag=0;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<m;i++){
	    cin>>arr1[i];
	}
	int max=arr[0];
	int min1=arr[0];
	for(int i=0;i<n;i++){
	    if(max<arr[i]){
	        max=arr[i];
	    }
	    if(min1>arr[i]){
	        min1=arr[i];
	    }
	}
	int val=maxee(2*min1,max);
    int min=arr1[0];
    for(int i=0;i<m;i++){
        if(min>arr1[i]){
            min=arr1[i];
        }
    }
    if(val<min){
        cout<<val;
    }
    else{
        cout<<"-1";
    }
	return 0;
}