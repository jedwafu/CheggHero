#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[12];
	int n;
	cin>>n;
	for(int i=0;i<12;i++){
	    cin>>arr[i];
	}
	sort(arr,arr+12);
	int i=11;
	int count=0;
	int val=0;
	while(val<n){
	    count++;
	    if(i<0){
	        break;
	    }
	    val+=arr[i--];
	}
	if(i<0){
	    if(count==12){
	        cout<<count;
	    }else{
	    cout<<"-1";
	    }
	}else{
	    cout<<count;
	}
	return 0;
}