#include <iostream>
using namespace std;
int min(int a,int b){
    return a>b?b:a;
}
int main() {
	int m,n,a,b,result;
	cin>>n>>m>>a>>b;
	if(b<=m*a){
	    if(n%m==0){
	        result=n/m;
	        result*=b;
	    }else{
	        int div1=n/m;
	        int rem=n%m;
	        int res=min(rem*a,b);
	        result=div1*b+res;
	    }
	}else{
	    result=n*a;
	}
	cout<<result;
	return 0;
}