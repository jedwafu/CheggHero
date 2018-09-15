#include <iostream>
using namespace std;

int main() {
	int n;
	int r1,r2,l1,l2;
	cin>>n;
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.size();i++){
	    if(s[i]=='R'){r1=i; break;}
	    if(i==s.size()){r1=-1; r2=-1;}
	    else{
	        for(int j=s.size()-1;j>=0;j--){
	            if(s[j]=='R'){r2=j; break;}
	        }
	    }
	}
	for(i=0;i<s.size();i++){
	    if(s[i]=='L'){l1=i; break;}
	    if(s[i]==s.size()){ l1=-1; l2=-1;}
	    else{
	        for(int j=s.size()-1;j>=0;j--){
	            if(s[j]=='L'){l2=j; break;}
	        }
	    }
	}
	if(r1==-1){
	    cout<<l2+1<<" "<<l1;
	}else if(l1==-1){
	    cout<<r1+1<<" "<<r2+2;
	}else{
	    cout<<r1+1<<" "<<r2+1;
	}
	return 0;
}