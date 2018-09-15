#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s,t;
	string l;
	cin>>s>>t;
	reverse(t.begin(),t.begin()+t.size());
	if(s==t)
	cout<<"YES";
	else
	cout<<"NO";
	
	return 0;
}