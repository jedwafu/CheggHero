#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a,b;
	cin>>a>>b;
	ll temp=a;
	ll count=0;
	while(temp<b){
	    temp*=a;
	    count++;
	}
	if(temp==b)
	cout<<"YES"<<endl<<count;
	else
	cout<<"NO";
	return 0;
}