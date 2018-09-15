#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
// this is different
int main() {
	ll a,b,count=0,x,i;
	cin>>a>>b;
	if(a==b){
	    cout<<"infinity";
	}else{
	    ll x=abs(a-b);
	    for(i=1;i*i<x;i++){
	        if(x%i==0){
	            if(i>b)count++;
	            if(x/i>b)count++;
	        }
	    }
	    if(i*i==x&&i>b)count++;
	    cout<<count;
	}
	return 0;
}