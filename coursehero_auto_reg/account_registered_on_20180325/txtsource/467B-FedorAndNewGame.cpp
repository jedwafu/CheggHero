#include <iostream>
typedef long long ll;
using namespace std;
int mycount(int a){
    int count=0;
    while(a){// here we are counting the number of 1's
        a=a&(a-1);
        count++;
    }
    return count;// returning the count
}
int main() {
    int arr[100001];
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
	    cin>>arr[i];
	}
	ll result=0;
	for(int i=0;i<m;i++){//binary representations of the corresponding numbers differ in at most k bits
	//in that sense we need the take the zor and count the number of ones in that 
	    if(mycount(arr[i]^arr[m])<=k){// checking the count is at most k then incrememnt the result;
	        result++;
	    }
	}
	cout<<result;
	return 0;
}