#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int countr=0;
	int countg=0;
	int countb=0;
	for(int i=0;i<s.size();i++){
	    if(s[i]=='R' && s[i+1]=='R' && (i+1)<s.size()){
	        countr++;
	    }
	    else if(s[i]=='G' && s[i+1]=='G' && (i+1)<s.size()){
	        countg++;
	    }
	    else if(s[i]=='B' && s[i+1]=='B' && (i+1)<s.size()){
	        countb++;
	    }
	}
	cout<<countr+countb+countg;
	return 0;
}