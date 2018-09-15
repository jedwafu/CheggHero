#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll s=n/3;
	if(n%3==0){
	    cout<<n-s;
	}else{
	    if(n>3){
	        if((n-1)%3==0)
	            cout<<n-s;
	        else
	            cout<<n-1-s;
	    }else{
	        cout<<"1";
	    }
	}
	return 0;
}