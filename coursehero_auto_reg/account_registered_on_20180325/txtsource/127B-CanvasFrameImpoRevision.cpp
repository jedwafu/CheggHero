#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int arr[101];
    int count[102];
    memset(count,0,sizeof(count));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++){
	    count[arr[i]]++;
	}
	int temp=0;
	for(int i=1;i<=100;i++){
	  //  cout<<count[i]<<" ";
	 if(count[i]%2 && count[i]>0){
	     count[i]=count[i]-1;
	}
	    temp+=count[i];
	}
    cout<<temp/4;
	return 0;
}