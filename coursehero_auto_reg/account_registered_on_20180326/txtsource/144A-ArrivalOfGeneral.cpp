#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[10001];
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int max=arr[0],min=arr[0];
	int maxindex=0,minindex=0;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
            minindex=i;
        }
        if(arr[i]>max){
            max=arr[i];
            maxindex=i;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]==max && i<maxindex)
        maxindex=i;
        else if(arr[i]==min && i>minindex)
        minindex=i;
    }
	if(maxindex<minindex){
	    cout<<maxindex+(n-1-minindex);
	}else{
	    cout<<maxindex+(n-1-minindex)-1;
	}
	return 0;
}
