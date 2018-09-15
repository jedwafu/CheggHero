
 #include <iostream>
using namespace std;
int min(int a,int b,int c){
    if(a<=b&&a<=c)
    return a;
    else if(b<=c&&b<=a)
    return b;
    else
    return c;
}
int main() {
	int n,k,l,c,d,p,nl,np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	k*=l;
	int toast1=k/nl;
	c*=d;
	int toast2=c;
	int toast3=p/np;
	int val=min(toast1,toast3,toast2);
	val/=n;
	cout<<val;
	return 0;
}