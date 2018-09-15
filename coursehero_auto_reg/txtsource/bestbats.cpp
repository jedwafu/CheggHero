#include<bits/stdc++.h>
using namespace std;

long long int c[100][11];
int score[11];
void bq()
{
	int i,j;
	c[0][0]=1;
	for(i=1;i<=100;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i &&j<=11;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
}
int main()
{
	bq();
	int t,k,i,temp,count1,count2;
	cin>>t;
	while(t--)
	{
		 count1=0;
		 count2=0;
		for(i=0;i<11;i++)
		cin>>score[i];
		cin>>k;
		
		sort(score,score+11);
	   
	    temp=score[11-k];
	    for(i=0;i<11-k;i++)
	    {
	    	if(score[i]==temp)
	    	count1++;
		}
		for(i=11-k;i<11;i++)
		{
			if(score[i]==temp)
	    	count2++;
		}
		
		cout<<c[count1+count2][count2]<<endl;
	}
	
	return 0;
}
