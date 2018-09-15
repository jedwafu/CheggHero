#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	int n;
	ll x;
	int flag=0;
	ll arr[100001];
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++){
	    while(arr[i]%2==0){
	        arr[i]/=2;
	    }
	    while(arr[i]%3==0){
	        arr[i]/=3;
	    }
	    if(i==0){
	        x=arr[i];
	    }
	   if(i>=1 && x!=arr[i]){
	       flag=1;
	       break;
	   }
	}
	if(flag){
	    cout<<"NO";
	}else{
	    cout<<"YES";
	}
	return 0;
}