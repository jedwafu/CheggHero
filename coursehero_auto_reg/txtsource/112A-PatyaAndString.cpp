#include <iostream>
using namespace std;

int main() {
	string s,s1;
	cin>>s>>s1;
	int val=0;
	int res=0;
	for(int i=0;i<s.size();i++){
	    char ch=tolower(s[i]);
	    char ch1=tolower(s1[i]);
	    if(ch==ch1){
	        val++;
	    }else if(ch>ch1){
	        res=1;
	        break;
	    }else{
	        res=-1;
	        break;
	    }
	}
	if(res){
	   cout<<res; 
	}else{
	    cout<<"0";
	}
	return 0;
}