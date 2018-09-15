#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll arr[100010];
ll ansval;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        for(int i=0;i<n;i++)
        	cin>>arr[i];

        ll mini=min(arr[0],arr[n-1]);
        
        ll diff=arr[1]-arr[0]; 
        bool flag=true;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]-arr[i]!=diff)
            {
            	flag=false;
            	break;
            }
        }
        
        if(flag)
        {
        	cout<<mini<<endl;
        	continue;
        }


       else if(n>=5)
       {
        	flag=true;
        
         diff=arr[1]-arr[0];
         for(int i=0;i<4;i++)
         { 
        	if(arr[i+1]-arr[i]!=diff)
        	{
        		flag=false;
        		break;
        	}
         } 

        ll ans=0;
        if(flag)
        {
        	for(int i=0;i<n-1;i++)
        	{
        		if(arr[i+1]-arr[i]!=diff)
        		{
        			ans=i+1;
        			break;
        		}
        	}
        

        if(ans==n-1)
        {
        	cout<<arr[n-1]<<endl;
        	continue;
        }

        if(ans)
        {
        	for(int i=0;i<n-1;i++)
        	{
                 if(i==ans-1)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==ans)
                 continue;

                 else
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            {
            	cout<<arr[ans]<<endl;
            	continue;
            }
            else
            {
            	cout<<-1<<endl;
            	continue;
            }
        } 

        }

        flag=true;
        diff=arr[2]-arr[1];
        ans=0;
        ansval=10000000000;

        for(int i=1;i<n-1;i++)
        {
        	if(arr[i+1]-arr[i]!=diff)
        	{
        		flag=false;
        		break;
        	}
        }
        
        if(flag)
        ansval=min(arr[0],ansval);  
      
        diff=arr[2]-arr[0];
        flag=true;

        for(int i=0;i<n-1;i++)
        	{
                 if(i==0)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==1)
                 continue;

                 else
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            ansval=min(arr[1],ansval);       

            
        diff=arr[1]-arr[0];
        flag=true;
        
        for(int i=0;i<n-1;i++)
        	{
                 if(i==1)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==2)
                 continue;

                 else
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            	ansval=min(arr[2],ansval);

                 
        diff=arr[1]-arr[0];
        flag=true;
        
        for(int i=0;i<n-1;i++)
        	{
                 if(i==2)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==3)
                 continue;

                 else
                 {
                 	if((arr[i+1]-arr[i])!= diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            	{ansval=min(arr[3],ansval);
            	  }            


        diff=arr[1]-arr[0];
        flag=true;
        
        for(int i=0;i<n-1;i++)
        	{
                 if(i==3)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==4)
                 continue;

                 else
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            	ansval=min(arr[4],ansval);

            if(ansval==10000000000)
            	cout<<-1<<endl;
            else
            	cout<<ansval<<endl;
	
	}
	else
	{
        flag=true;
        diff=arr[2]-arr[1];
        ll ans=0;
        ll ansval=10000000000;

        for(int i=1;i<n-1;i++)
        {
        	if(arr[i+1]-arr[i]!=diff)
        	{
        		flag=false;
        		break;
        	}
        }
        
        if(flag)
        ansval=min(arr[0],ansval);  
      
        diff=arr[2]-arr[0];
        flag=true;
          
        for(int i=0;i<n-1;i++)
        	{
                 if(i==0 and i+2<n)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==1)
                 continue;

                 else if(i+1<n)
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            ansval=min(arr[1],ansval);       

            
        diff=arr[1]-arr[0];
        flag=true;
        
        for(int i=0;i<n-1;i++)
        	{
                 if(i==1 and i+2<n)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==2)
                 continue;

                 else if(i+1<n)
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            	ansval=min(arr[2],ansval);

                 
        diff=arr[1]-arr[0];
        flag=true;
        
        for(int i=0;i<n-1;i++)
        	{
                 if(i==2 and i+2<n)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==3)
                 continue;

                 else if(i+1<n)
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            	ansval=min(arr[3],ansval);            


        diff=arr[1]-arr[0];
        flag=true;
        
        for(int i=0;i<n-1;i++)
        	{
                 if(i==3 and i+2<n)
                 {
                 	if(arr[i+2]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
                 
                 else if(i==4)
                 continue;

                 else if(i+1<n)
                 {
                 	if(arr[i+1]-arr[i]!=diff)
                 	{
                 		flag=false;
                 		break;
                 	}
                 }
            }

            if(flag)
            	ansval=min(arr[4],ansval);

            if(ansval==10000000000)
            	cout<<-1<<endl;
            else
            	cout<<ansval<<endl;

	}
 
   }
   return 0;
}