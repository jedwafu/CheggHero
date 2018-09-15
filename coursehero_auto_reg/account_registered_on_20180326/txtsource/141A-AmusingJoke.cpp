#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int flag=0;
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	str1.append(str2);
	sort(str1.begin(),str1.end());
	sort(str3.begin(),str3.end());
	int n=str1.size();
	int k=str3.size();
	//cout<<n<<" "<<k;
	if(n!=k){
	cout<<"NO";
	}else{
	    for(int i=0;i<str3.size();i++){
	    if(str1[i]!=str3[i]){
	        flag=1;
	        break;
	    }
	}
	if(flag){
	    cout<<"NO";
	}else{
	    cout<<"YES";
	}
	}
	return 0;
}