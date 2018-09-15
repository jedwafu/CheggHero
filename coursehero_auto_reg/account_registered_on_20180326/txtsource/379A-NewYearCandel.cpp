#include <iostream>
using namespace std;
//code Belong to Niraj Sazzie
int main() {
	int a,b;
	cin>>a>>b;
	int sum=a;
	int mod;
	int div1;
	while(a>=b){
	    div1=a/b;
	    sum+=div1;
	    mod=(a%b);
	    a=div1+mod;
	}
	cout<<sum<<endl;
	return 0;
}