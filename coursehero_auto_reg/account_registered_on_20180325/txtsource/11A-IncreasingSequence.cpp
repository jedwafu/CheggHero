#include <iostream>
using namespace std;

int main() {
	int n,d;
	cin>>n>>d;
	int ans=0;
	int arr[2001];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    if(i){
	        if(arr[i-1]>=arr[i]){
	           ans=ans+(arr[i-1]-arr[i])/d+1;
	           arr[i]=arr[i]+((arr[i-1]-arr[i])/d+1)*d;
	        }
	    }
	}
	cout<<ans<<endl;
	return 0;
}