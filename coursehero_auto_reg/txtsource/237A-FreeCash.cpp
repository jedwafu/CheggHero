#include <iostream>
using namespace std;

int main() {
	int n;
	int cash=1;
	int max=1;
	cin>>n;
	int h0,m0;
	cin>>h0>>m0;
	int h,m;
	while(--n){
	    cin>>h>>m;
	    if(h0==h && m0==m){
	        cash++;
	        if(cash>max){
	            max=cash;
	        }
	    }else{
	        cash=1;
	    }
	    h0=h;
	    m0=m;
	}
	cout<<max;
	return 0;
}