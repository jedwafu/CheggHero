#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int a,b[100001];
    int result1 = 0;
    int result2 = 0;
    cin>>a;
    for ( int i = 0 ; i < 2*a ; i++){
        cin>>b[i];
    }
    sort(b,b + 2*a);
    for( int i = 0 ; i <  a ;i++ ){
        result1+=b[i];
    }
    for(int i = a  ; i < 2*a ; i++ ){
        result2+=b[i];
    }
    int intersectvalue = b[a-1];
    int intersectvalue1 = b[a ];

    if((result1 < result2) && (intersectvalue < intersectvalue1)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
   return 0;
}
