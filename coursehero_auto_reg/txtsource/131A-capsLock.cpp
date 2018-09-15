#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string s;
	char ch;
	int flag=0;
	cin>>s;
	int count=0;
	for(int i=0;i<s.size();i++){
	    if(isupper(s[i])){
	        if(i==0){
	            flag=1;
	        }count++;
	    }
	}

	if(flag==0 && count==s.size()-1){
	    for(int i=0;i<s.size();i++){
	        if(i==0){
	            ch=toupper(s[i]);
	            cout<<ch;
	        }else{
	            ch=tolower(s[i]);
	            cout<<ch;
	        }
	    }
	}else if(count==s.size()){
	    for(int i=0;i<s.size();i++){
	        ch=tolower(s[i]);
	        cout<<ch;
	    }
	}
	else{
	    cout<<s;
	}
	return 0;
}