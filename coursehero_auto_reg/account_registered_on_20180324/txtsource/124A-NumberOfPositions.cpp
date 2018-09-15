#include<iostream>
using namespace std;
int main(){
    int n,a,b,c,r;
    cin>>n>>a>>b;
    c=n-a-1;
    if(c>b){
        r=b+1;
    }else{
        r=c+1;
    }
    cout<<r;
    return 0;
}