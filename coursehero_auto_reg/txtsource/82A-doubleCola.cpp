#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	char ch[][30]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	while(n>5)
	n=(n/2)-2;
	cout<<ch[n-1];
	return 0;
}