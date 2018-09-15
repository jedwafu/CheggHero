#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int arr[1010][1010];
bool taken[1010];
int main()
{
	int n,c1,c2;
	cin>>n>>c1>>c2;
    for(int i=1;i<=n;i++)
    	taken[i]=false;

	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
        cin>>arr[i][j];

    //cout<<c1<<endl;
    int count=0,ans;

    for(int i=1;i<=n;i++)
    {
    	int mini=1000000;
         for(int j=1;j<=n;j++)
         {
             if(arr[i][j]<mini and i!=j)
              { 
                  mini=arr[i][j];
                  ans=j;
              }
 
         }

         if(!taken[i])
         {
                  	taken[i]=true;
                  	count++;
                  	if(count==c1)
                  		break;
         }

         if(!taken[ans])
         {	
                    taken[ans]=true;
                    count++;
                    if(count==c1)
                    	break;
         }
    }

    count=0;
    for(int i=1;i<=n;i++)
    {
    	if(taken[i])
    		count++;
    }
	count=min(count,c1);
    cout<<count<<endl;
    int count2=0;
	for(int i=1;i<=n;i++)
	{     
		if(count2==count)
			break;

		else if(taken[i])
		{
			cout<<i<<" ";
			count2++;
		}
	}


	return 0;

}