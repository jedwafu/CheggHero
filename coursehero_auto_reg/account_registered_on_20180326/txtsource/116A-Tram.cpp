#include <iostream>
using namespace std;

int main() {
    int arr[1001][2];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++)
        cin>>arr[i][j];
    }
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if(j==0){
                max-=arr[i][j];
            }else{
                max+=arr[i][j];
            }
          //  cout<<max<<" ";
            arr[i][j]=max;
        }
    }
    int maxval=arr[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if(maxval<arr[i][j]){
                maxval=arr[i][j];
            }
        }
    }
    cout<<maxval;
	return 0;
}