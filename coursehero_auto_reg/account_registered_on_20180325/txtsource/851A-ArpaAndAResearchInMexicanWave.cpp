#include <iostream>
//http://codeforces.com/problemset/problem/851/A
using namespace std;
typedef long long ll;
int main() {
    ll n,k,t;
    cin>>n>>k>>t;
    if(t < k)
        cout<<t<<endl;
    else if((k <= t) && (t <= n))
        cout<<k<<endl;
    else
        cout<<n-t+k<<endl;
	return 0;
}
