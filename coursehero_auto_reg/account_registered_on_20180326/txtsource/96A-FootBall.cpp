#include <iostream>
using namespace std;

int main() {
    int arr[1001];
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
	    arr[i]=s[i]-'0';
	}
	int count=1;
	for(int i=0;i<s.size();i++){
	    if(arr[i]==0 && arr[i+1]==0){
	        count++;
	        if(count==7){
	            break;
	        }
	    }else if(arr[i]==1 && arr[i+1]==1){
	        count++;if(count==7){
	            break;
	        }
	    }else if(arr[i]==1 && arr[i+1]==0){
	        count=1;
	    }
	    else if(arr[i]==0 && arr[i+1]==1){
	        count=1;
	    }
	}
	if(count>=7){
	    cout<<"YES";
	}else{
	    cout<<"NO";
	}
	return 0;
}