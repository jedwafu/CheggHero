#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll y,k,n;
	// NIraj sazzie
	cin>>y>>k>>n;
	ll x=k-y%k;// kitna number chaiye div ke lia..
	ll top=n-y;
	if(x<=top){
	    cout<<x;
	    x+=k;
	    while(x<=top){
	        cout<<" "<<x;
	        x+=k;
	    }
	}else{
	    cout<<"-1";
	}
	return 0;
}
