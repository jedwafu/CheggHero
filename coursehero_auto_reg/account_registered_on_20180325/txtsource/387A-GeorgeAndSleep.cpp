#include <iostream>
using namespace std;

int main() {
	string s,t;
	cin>>s>>t;
	int hh1=0,mm1=0,hh2=0,mm2=0,hour1=0,res1=0,res2=0;
	for(int i=0;i<s.size();i++){
	    if(s[i]==':'){
	        hour1=hh1;
	        hh1=0;
	        continue;
	    }
	    hh1=hh1*10+s[i]-'0';
	}
	mm1=hh1;
	hh1=hour1;
	hour1=0;
   // cout<<hh1<<" "<<mm1;
   for(int i=0;i<t.size();i++){
	    if(t[i]==':'){
	        hour1=hh2;
	        hh2=0;
	        continue;
	    }
	    hh2=hh2*10+t[i]-'0';
	}
	mm2=hh2;
	hh2=hour1;
//	cout<<hh1<<" "<<mm1<<" "<<hh2<<" "<<mm2;
if(hh1==0 && hh2==0 && mm1>=mm2){
    hh1=0;
}else if(hh1==0){
    hh1=24;
}
    if(mm1<mm2){
        hh1-=1;
        mm1+=60;
        res2=mm1-mm2;
    }else{
        res2=mm1-mm2;
    }
    res1=hh1-hh2;
    if(res1<0){
        res1=24+res1;
    }
    if(res1<=9 && res2<=9)
    cout<<"0"<<res1<<":"<<"0"<<res2;
    else if(res1<=9)
    cout<<"0"<<res1<<":"<<res2;
    else if(res2<=9)
    cout<<res1<<":"<<"0"<<res2;
    else
    cout<<res1<<":"<<res2;
	return 0;
}