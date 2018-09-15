#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int i,j;
    int a;
    int flag=0;
   // int arr[6][6];
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            cin>>a;
            if(a==1){
            flag=1;
             break; 
            }
        }
         if(flag==1)
              break;
    }
    int res=abs(3-i)+abs(3-j);
    cout<<res;
	return 0;
}