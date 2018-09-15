#include <iostream>
using namespace std;

int main() {
    int arr[100001];
	int n;
	cin>>n;
	int l;
	for(int i=0;i<n;i++){
	    cin>>l;
	    arr[i]=l/25;
	}
	int flag1=0,flag2=0,flag4=0;
	int b=0;
	for(int i=0;i<n;i++){
	    if(arr[i]==1){
	        flag1++;
	    }else if(arr[i]==2){
	        flag1--;
	        flag2++;
	    }else{
	        if(flag2>0){
	            flag4++;
	            flag2--;
	            flag1--;
	        }else{
	            flag1-=3;
	        }
	    }
	    if(flag1<0){
	        b=1;
	        break;
	    }
	}
	if(b==1){
	    cout<<"NO";
	}else{
	    cout<<"YES";
	}
	return 0;
}