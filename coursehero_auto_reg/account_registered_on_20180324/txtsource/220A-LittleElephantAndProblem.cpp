#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n;
	ll arr[100001];
	ll arr1[100001];
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    arr1[i]=arr[i];
	}
	int count=0;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
	    if(arr[i]!=arr1[i]){
	        count++;
	    }
	    if(count>4){
	        break;
	    }
	}
	if(count<=2){
	    cout<<"YES";
	}else{
	    cout<<"NO";
	}
	return 0;
}
