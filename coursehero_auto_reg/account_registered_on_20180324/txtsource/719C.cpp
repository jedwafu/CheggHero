#include<bits/stdc++.h>
using namespace std;

#define ll long long int

char arr[200010];
char dig[10]={'0','1','2','3','4','5','6','7','8','9'};
int main()
{
	int n;
	ll t;
    
    cin>>n>>t;
	for(int i=1;i<=n;i++)
     cin>>arr[i];

    if(t>n)
    	t=n;

    int k=0;
    while(k<=n)
    {
       if(arr[k]=='.')
       	break;
       else
       	k++;
    }

    k++;
    int temp=arr[k]-'0';
    int carry;
    if(temp>=5)
    {
    	carry=1;
         for(int i=k-2;i>0;i--)
         {
         	if(carry)
         	{
               if(arr[i]=='9')
               	arr[i]='0';

               else
               	{
               		arr[i]=dig[arr[i]-'0'+1];
               		carry=0;
                    break;
                }
         	}
         }

         if(carry)
    	{arr[0]='1';
          cout<<arr[0];
        }
        
        for(int i=1;i<=k-2;i++)
        	cout<<arr[i];

        return 0;
    }
    int end=n;
    while(k<n)
    {
    	temp=arr[k+1]-'0';
      
        if(temp>=5)
       	{
       	   arr[k]=dig[arr[k]-'0'+1];
           t--;
           end=k;

           while(k>0 and t>0)
           {
           	   
               temp=arr[k]-'0';
               if(temp>=5 and arr[k-1]!='.')
               {
                  arr[k-1]=dig[arr[k-1]-'0'+1];
                  t--;
                  k--;
                  end=k;
               }
               else if(temp>=5 and arr[k-1]=='.')
               {
               	   carry=1;
          for(int i=k-2;i>0;i--)
         {
         	if(carry)
         	{
               if(arr[i]=='9')
               	arr[i]='0';

               else 
               	{
               		arr[i]=dig[arr[i]-'0'+1];
               		carry=0;
                    break;
                }
         	}
         }

         if(carry)
    	{arr[0]='1';
          cout<<arr[0];
        }
        
        for(int i=1;i<=k-2;i++)
        	cout<<arr[i];

        return 0;   
               }

               else if(temp<5) 
               {
               	for(int i=1;i<=end;i++)
               		cout<<arr[i];
               	return 0;
               }
           }

           if(t==0)
           {
             for(int i=1;i<=end;i++)
               		cout<<arr[i];
               	return 0;
           }
       	}
       	else
       		k++;

    }


    for(int i=1;i<=end;i++)
        cout<<arr[i];
               	
               	return 0;
   

}