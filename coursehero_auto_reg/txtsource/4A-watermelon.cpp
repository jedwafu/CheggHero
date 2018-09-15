#include <iostream>
using namespace std;

int main() {
	int w;
	int flag=0;
	cin>>w;
	for(int i=1;i<=100;i++){
	    for(int j=1;j<=100;j++){
	        if((i+j)==w){
	            if(i%2==0 && j%2==0){
	                flag=1;
	            }
	        }
	       else if((i+j)>w){
	           break;
	       } 
	    }
	}
	if(flag)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}