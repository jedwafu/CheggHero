#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string s;
	cin>>s;
	string result;
	for(int i=0;i<s.size();i++){
	    char ch=tolower(s[i]);
	    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y'){
	       continue; 
	    }else{
	       cout<<"."<<ch;
	    }
	}
	cout<<result;
	return 0;
}