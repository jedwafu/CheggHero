#include <iostream>
using namespace std;
typedef long long ll;
ll value;
ll f(ll p,ll r){
	    value=1;
	    for(ll i=0;i<r;i++){
	        value*=(p-i);
	        value/=(i+1);
	    }
	    return value;
	}
	// Author Niraj Sazzie
int main() {
	ll n,m,t,result=0;
	cin>>n>>m>>t;
	
	for(ll i=4;i<t;i++){
	    result+=f(n,i)*f(m,t-i);
	}
	cout<<result;
	return 0;
}
