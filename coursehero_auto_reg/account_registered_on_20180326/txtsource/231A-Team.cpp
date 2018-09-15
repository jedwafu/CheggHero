#include <iostream>
using namespace std;

int main() {
	int arr[1000][3];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    for(int j=0;j<=2;j++){
	        cin>>arr[i][j];
	    }
	}
	int count=0;
	int result=0;
	for(int i=0;i<n;i++){
	    count=0;
	    for(int j=0;j<=2;j++){
	        if(arr[i][j]==1)
	        count++;
	        if(count==2){
	        result++;
	        break;
	        }
	    }
	}
	cout<<result;
	return 0;
}
