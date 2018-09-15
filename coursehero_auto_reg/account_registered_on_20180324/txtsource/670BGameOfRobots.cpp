#include <iostream>
typedef unsigned long long ll;
using namespace std;

int main() {
	ll n,k;
	cin>>n>>k;
	ll arr[100001];
	for(int i=1;i<=n;i++){
	    cin>>arr[i];
	}
	ll i=1;
	ll temp=0;
	while(temp+i<k){
	    temp+=i;
	    i++;
	}
    if(k==1)
        cout<<arr[1];
    else
        cout<<arr[k-temp];
	return 0;
}