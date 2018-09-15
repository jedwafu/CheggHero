#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef uint64_t ll;
int main() {
    ll n,x;
    cin>>n>>x;
    int arr[100001];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll res=0;
    for(int i=0;i<n;i++){
        res+=arr[i]*x;
        if(x>1)
            x--;
    }
    cout<<res<<endl;
	return 0;
}