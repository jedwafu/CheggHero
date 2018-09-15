#include<bits/stdc++.h>
using namespace std;

int arr[100010];

int main()
{
	int i,n,k,m,j;
	cin>>n>>k;
	
	int l=k;
	for(i=0;i<k;i++)
	{
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>arr[j];
		}
		
		if(arr[0]==1)
		{
			j=1;
			while(arr[j]==j+1 &&j<m)
			{
				j++;
			}
			j--;
			l+=(m-1-j);
		}
		else
		{
			l+=m-1;
		}
    }
		
		l+=l-1;
		l-=k;
	
	   cout<<l;
	   return 0;
	
}
