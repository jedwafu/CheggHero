#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.size();i++){
	    if(s[i]=='1' && s[i+1]=='4' && s[i+2]=='4'){
	        i+=2;
	        continue;
	    }else if(s[i]=='1' && s[i+1]=='4'){
	        i+=1;
	        continue;
	    }
	    else if(s[i]=='1'){
	        continue;
	    }
	    else{
	        cout<<"NO";
	        break;
	    }
	}
	if(i==s.size()){
	    cout<<"YES";
	}
	return 0;
}
