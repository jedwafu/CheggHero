#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	int arr[101][101];
	int n;
	cin>>n;
	ll a=0,b=0,c=0;
	ll a1,a2,a3;
	for(int i=0;i<n;i++){
	    cin>>a1>>a2>>a3;
	    a+=a1;
	    b+=a2;
	    c+=a3;
	}
	if(a==0 && b==0 && c==0){
	    cout<<"YES";
	}else{
	    cout<<"NO";
	}
	return 0;
}