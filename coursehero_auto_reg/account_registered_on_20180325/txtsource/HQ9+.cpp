#include <iostream>
using namespace std;

int main() {
	string str;
	cin>>str;
	int flag=0;
	for(int i=0;i<str.size();i++){
	    if(str[i]>=33&&str[i]<=126){
	    if(str[i]=='H'||str[i]=='Q'||str[i]=='9')
	    flag=1;
	}
	}
	if(flag){
	    cout<<"YES";
	}else{
	    cout<<"NO";
	}
	return 0;
}
