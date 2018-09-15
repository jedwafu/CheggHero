#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll k,n,w;
    cin>>k>>n>>w;
    ll dollar=0;
    for(int i=1;i<=w;i++){
        dollar+=k*i;    
    }
    if((dollar-n)<0){
        cout<<"0";
    }else
    cout<<dollar-n;
	return 0;
}