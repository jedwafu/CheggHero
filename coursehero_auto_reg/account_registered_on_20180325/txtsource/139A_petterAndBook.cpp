#include <iostream>
using namespace std;

int main() {
    int arr[8];
    int n,result,sum=0,i;
    cin>>n;
    for(i=1;i<=7;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    i=1;
    if(n%sum>0){
      n%=sum;  
    while(n>0){
        if(i==8)
        i=1;
        n-=arr[i];
        result=i;
        i++;
    }
    }else{
        while(n>0){
        if(i==8)
        i=1;
        n-=arr[i];
        result=i;
        i++;
    }
    }
    cout<<result;
	return 0;
}
