#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int x,y,z;
	cin>>x>>y>>z;
	int a=sqrt((x*y)/z);
	int b=sqrt((x*z)/y);
	int c=sqrt((y*z)/x);
	int val=(a+b+c)*4;
	cout<<val;
	return 0;
}