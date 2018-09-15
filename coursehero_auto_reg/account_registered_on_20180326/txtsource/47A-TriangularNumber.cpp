#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    //https://en.wikipedia.org/wiki/Triangular_number
    //Niraj Sazzie
	//first take out 8x+1 take root and -1 and divide by 2 then again calculate the number
	// if that number is same as the given input it means bingo
	ll n;
	ll set=0;
	cin>>n;
	ll val=8*n+1;
	ll fix=sqrt(val)-1;
	fix/=2;
	fix*=(fix+1);
	fix/=2;
	if(fix==n)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
