#include <iostream>
using namespace std;

int main() {
	long long m,n,a;
	cin>>m>>n>>a;
	long long rows;
	long long colm;
	if(n%a==0){
	    rows=n/a;
	}else{
	    rows=n/a;
	    rows++;
	}
	if(m%a==0){
	    colm=m/a;
	}else{
	    colm=m/a;
	    colm++;
	}
	cout<<rows*colm;
	return 0;
}