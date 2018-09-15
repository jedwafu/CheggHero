#include<bits/stdc++.h>
using namespace std;

char s[20];

int main()
{
	scanf("%s",s);
	
	int len=strlen(s);
	int ans=26;
	
	ans+=(len)*25;
	
	cout<<ans;
	
}
