#include<bits/stdc++.h>
using namespace std;

char arr1[110],arr2[110];

int main()
{
	int t,i,mindiff,maxdiff;
	cin>>t;
	while(t--)
	{
		
		scanf("%s",arr1);
		scanf("%s",arr2);
		
		mindiff=maxdiff=0;
		
		for(i=0;i<strlen(arr1);i++)
		{
			if(arr1[i]=='?' || arr2[i]=='?')
			maxdiff++;
			
			else if(arr1[i]!=arr2[i])
			{
				maxdiff++;
				mindiff++;
			}
	
		}

	    cout<<mindiff<<" "<<maxdiff<<endl;	
	}
	return 0;
}
