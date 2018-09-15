#include<bits/stdc++.h>
using namespace std;

char arr[100010];

int main()
{
	int t,n,k,i,j,count;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
        scanf("%s",arr);
        count=0;
        int flag;
        i=0;
        
        if(k==1)
        {
        	int onesonodd=0,onesoneven=0,zeroonodd=0,zerooneven=0;
        	for(i=0;i<n;i+=2)
        	{
        		if(arr[i]=='1')
        		onesoneven++;
        		else
        		zerooneven++;
			}
			
			for(i=1;i<n;i+=2)
        	{
        		if(arr[i]=='1')
        		onesonodd++;
        		else
        		zeroonodd++;
			}
			
			if(zerooneven+onesonodd>zeroonodd+onesoneven)
			 flag=1;
			 else
			 flag=0;
			 
			 if(flag)
			 cout<<zeroonodd+onesoneven<<endl;
			 else
			 cout<<zerooneven+onesonodd<<endl;
			 
			 if(flag)
			 {
			 	for(i=0;i<n;i++)
			 	{
			 		if(i%2)
			 		cout<<"1";
			 		else
			 		cout<<"0";
				 }
			 }
			 else
			 {
			 	for(i=0;i<n;i++)
			 	{
			 		if(i%2)
			 		cout<<"0";
			 		else
			 		cout<<"1";
				 }
			 }
			 cout<<endl;
		}
		
		else
		{
		
        while(i<n)
        {
        	int size=1;
        	int start=i;
        	
        	while(arr[i]==arr[i+1])
        	{
        		i++;
        		size++;
			}
			
			if(size>k)
			{
				for(j=start+k;j<=i;j=j+k+1)
				{
				    if(arr[j]=='1')
				    arr[j]='0';
				    else
				    arr[j]='1';
				    
				    count++;
				}
			
			if(size%(k+1)==0)
			{
				if(arr[i]=='1')
				arr[i]='0';
				else
				arr[i]='1';
				
				if(arr[i-1]=='1')
				arr[i-1]='0';
				else
				arr[i-1]='1';
				
			}
		    }
		    
			i++;
		}
	    
	    cout<<count<<endl;
	    
	    for(i=0;i<n;i++)
	    cout<<arr[i];
	    cout<<endl;
	    
		}
	}
}
