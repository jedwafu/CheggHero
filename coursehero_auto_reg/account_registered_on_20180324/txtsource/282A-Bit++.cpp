#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int x=0;
	string s;
	while(n--){
	    cin>>s;
	    if(s[0]=='+' && s[1]=='+' && s[2]=='X'){
	        x+=1;
	    }else if(s[0]=='X' && s[1]=='+' && s[2]=='+'){
	        x+=1;
	    }else if(s[0]=='X' && s[1]=='-' && s[2]=='-'){
	        x-=1;
	    }
	    else if(s[0]=='-' && s[1]=='-' && s[2]=='X'){
	        x-=1;
	    }
	}
	cout<<x;
	return 0;
}