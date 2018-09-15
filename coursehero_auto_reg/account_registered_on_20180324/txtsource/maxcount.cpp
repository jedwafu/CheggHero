#include<iostream>
using namespace std;

int freq[10010];
int main()
{
	int t,n,maxv,maxc,i,num;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		maxc=maxv=0;
		
		for(i=0;i<=10010;i++)
		{
			freq[i]=0;
		}
		
		for(i=0;i<n;i++)
		{
			cin>>num;
			freq[num]++;
			if(freq[num]>maxc)
			{
				maxv=num;
				maxc=freq[num];
			}
			
			else if(freq[num]==maxc && num<maxv)
			{
				maxv=num;
			}
		}
		
		cout<<maxv<<" "<<maxc<<endl;
		
	}
	return 0;
}
