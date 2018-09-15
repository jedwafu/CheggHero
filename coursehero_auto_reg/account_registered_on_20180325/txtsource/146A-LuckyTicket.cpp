#include <iostream>
using namespace std;

int main() {
	int arr[51];
	int n,flag=0,sum1=0,sum2=0;
	cin>>n;
	int z=n;
	string s;
	cin>>s;
for(int i=0;i<s.size();i++){
        arr[i]=s[i]-'0';
	}
	int half=n/2;
	for(int i=0;i<n;i++){
	    if(arr[i]==4)
	    flag++;
	    else if(arr[i]==7)
	    flag++;
	}
	if(flag!=n)
	cout<<"NO";
	else{
	    for(int i=0;i<half;i++)
	    sum1+=arr[i];
	    for(int i=half;i<n;i++)
	    sum2+=arr[i];
	    if(sum1==sum2)
	    cout<<"YES";
	    else
	    cout<<"NO";
	}
	return 0;
}
