#include <iostream>
using namespace std;

int main() {
   // int arr[100],arr1[100];
    string s,s1;
	cin>>s>>s1;
	long long val1=0,res=0,val2=0,res1=0;
	for(int i=0;i<s.size();i++){
	    val1=val1*10+(s[i]-'0');
	    if(s[i]=='0'){
	        continue;
	    }else{
	    val2=val2*10+(s[i]-'0');
	    }
	}
    for(int i=0;i<s1.size();i++){
	    res=res*10+(s1[i]-'0');
	    if(s1[i]=='0'){
	        continue;
	    }else{
	    res1=res1*10+(s1[i]-'0');
	    }
	}
	val1+=res;
	long long val3=0;
	string s2=to_string(val1);
	for(int i=0;i<s2.size();i++){
	    if(s2[i]=='0'){
	        continue;
	    }else{
	        val3=val3*10+(s2[i]-'0');
	    }
	}
	val2+=res1;//23
	if(val3==val2){
	    cout<<"YES";
	}else{
	    cout<<"NO";
	}
	return 0;
}