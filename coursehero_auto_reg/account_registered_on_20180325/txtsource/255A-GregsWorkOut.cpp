#include <iostream>
using namespace std;

int main() {
    int arr[1001];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int chest=0,bices=0,back=0;
	for(int i=0;i<n;i++){
	    if(i%3==0){
	        chest+=arr[i];
	    }else if(i%3==1){
	        bices+=arr[i];
	    }else{
	        back+=arr[i];
	    }
	}
	if(chest>bices && chest>back){
	    cout<<"chest";
	}else if(bices>chest && bices>back){
	    cout<<"biceps";
	}else{
	    cout<<"back";
	}
	return 0;
}