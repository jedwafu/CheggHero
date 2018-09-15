#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ll n;
	cin>>n;
	ll maxdiv,maxrem,mindiv,minrev;
	mindiv=n/7;
	minrev=n%7;
	if(minrev==6){
	    cout<<mindiv*2+1<<" ";
	}else if(minrev==0){
	    cout<<mindiv*2<<" ";
	}else{
	    cout<<mindiv*2<<" ";
	}
	maxdiv=n/7;
	maxrem=n%7;
	if(maxrem<=2){
	    cout<<maxdiv*2+maxrem;
	}else{
	    cout<<maxdiv*2+2;
	}
	return 0;
}