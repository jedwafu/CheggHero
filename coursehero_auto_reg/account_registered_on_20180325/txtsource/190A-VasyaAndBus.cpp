#include <iostream>
using namespace std;
// jugaad by Niraj Sazzie
int main() {
    int child,gUp,mV,mnV;
    cin>>gUp>>child;
    if(gUp>=1){
    if(child>1)
    mV=gUp+(child-1);
    else
    mV=gUp;
    if(child>1){
        if(gUp>child){
            mnV=gUp;
        }else{
            int mreRt=child/gUp;
            int mdlo=child%gUp;
            mnV=gUp+(mreRt-1)*gUp+mdlo;
        }
    }
    cout<<mnV<<" "<<mV;
    }else if(gUp==0 && child==0){
        cout<<gUp<<" "<<child;
    }else
    cout<<"Impossible";
	return 0;
}