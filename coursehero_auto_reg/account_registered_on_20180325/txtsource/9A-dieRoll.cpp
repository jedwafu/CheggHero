#include <iostream>
using namespace std;
int gcd(int n,int m){
    return m==0?n:gcd(m,n%m);
}
int main() {
	int y,z;
	cin>>y>>z;
	int max=(y<z)?z:y;
	int p=6-max+1;
	int dc=gcd(p,6);
	cout<<p/dc<<"/"<<6/dc;
	return 0;
}