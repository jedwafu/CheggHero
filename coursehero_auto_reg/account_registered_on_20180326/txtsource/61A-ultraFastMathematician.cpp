#include <iostream>
using namespace std;
// niraj Sazzie
int main() {
    int arr1[100],arr2[100];
	string s,s1;
	int val;
	cin>>s>>s1;
	for(int i=0;i<s.size();i++){
	    arr1[i]=s[i]-'0';
	}
	for(int i=0;i<s1.size();i++){
	    arr2[i]=s1[i]-'0';
	}
	for(int i=0;i<s1.size();i++){
	    val=arr1[i]^arr2[i];
	    cout<<val;
	}
	return 0;
}
