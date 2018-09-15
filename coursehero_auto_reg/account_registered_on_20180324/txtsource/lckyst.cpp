#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int arr[100010];
int answ[50];
long long int pow4[6]={1,4,16,64,256,1024};
long long int ans;
long long int pows(int divisor, int index)
{
	ans=0;
	while(arr[index]%divisor==0)
	{
		ans++;
		arr[index]=arr[index]/divisor;
	}
	return ans;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
	 cin>>arr[i];
    }
    
	for(int i=0;i<n;i++)
	{
		long long int dummy=arr[i];
		long long int p2=pows(2,i);
		long long int p5=pows(5,i);
		//cout<<p2<<p5<<arr[i]<<endl;
		if(p5-p2<=0)
		{
			printf("%lld\n",dummy);
		}
		
		
		else
		{
			
			if((p5-p2)%2==1)
			arr[i]=arr[i]*2;

			
			dummy=arr[i];
			int val=0;
			while(dummy>0)
			{
				val++;
				dummy=dummy/10;
			}
			
			for(int j=p5+val-1;j>val-1;j--)
			{
				answ[j]=0;
			}
			
			for(int j=val-1;j>=0;j--)
			{
			  answ[j]=arr[i]%10;
			  arr[i]=arr[i]/10;
			}
		    
		    for(int j=0;j<=p5+val-1;j++)
		    cout<<answ[j];
		    cout<<endl;
		}
		
	}
	
	return 0;
}
