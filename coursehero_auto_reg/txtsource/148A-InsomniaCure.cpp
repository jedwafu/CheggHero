#include <iostream>
using namespace std;
//code belong to Niraj Sazzie
int main() {
	int arr[100001]={0};
	int k,l,m,n,d;
	int count=0;
	cin>>k>>l>>m>>n>>d;
	for(int i=0+k-1;i<d;){
	    arr[i]=1;
	    i+=k;
	}
	for(int i=0+l-1;i<d;){
	    arr[i]=1;
	    i+=l;
	}
	for(int i=0+m-1;i<d;){
	    arr[i]=1;
	    i+=m;
	}
	for(int i=0+n-1;i<d;){
	    arr[i]=1;
	    i+=n;
	}
	for(int i=0;i<d;i++){
	    if(arr[i])
	    count++;
	}
	cout<<count<<endl;
	return 0;
}