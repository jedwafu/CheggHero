#include <iostream>
using namespace std;

int main() {
	string s;
	int arr[21];
	cin>>s;
	
	for(int i=0;i<s.size();i++){
	    arr[i]=s[i]-'0';
	}
	
	int count=0;
	
	for(int i=0;i<s.size();i++){
	    if(arr[i]==7 || arr[i]==4)
	        count++;
	}
	
	int digitCount=0;
	int countNext=0;
	while(count!=0){
	    int rem=count%10;
	    if(count==4 ||count==7)
	    countNext++;
	    count/=10;
	    digitCount++;
	}
	if(digitCount==countNext && digitCount!=0 && countNext!=0){
	    cout<<"YES";
	}else if(count==7 || count==5){
	    cout<<"YES";
	}else{
	    cout<<"NO";
	}
	return 0;
}
