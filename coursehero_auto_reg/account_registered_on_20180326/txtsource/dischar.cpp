#include<bits/stdc++.h>
using namespace std;

char arr[100001];
set<int> s;

int main()
{
	int t,i,n;
	
	scanf("%d",&t);
	
	while(t--)
	{
	    scanf("%s",arr);
	    s.clear();
	    
		int len =strlen(arr);
		for(i=0;i<len;i++)
		{
			n=arr[i]-'a'+1;
			s.insert(n);
		}
		
		cout<<s.size()<<endl;
	}
	return 0;
}
