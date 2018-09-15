#include<bits/stdc++.h>
using namespace std;

int arr[110];
int score[110];
int counts[7];
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n,c;
	cin>>t;
	int max=0;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{

			for(int j=1;j<=6;j++)
				counts[j]=0;

			cin>>c;
			for(int j=0;j<c;j++)
			{
				cin>>arr[j];
				counts[arr[j]]++;
			}

            int subs;
            score[i]=c;
            
            sort(counts+1,counts+7);
            if(counts[1]>0)
            {	
            	score[i]+=4*counts[1];
            	
            	 subs=counts[1];
            	for(int j=1;j<=6;j++)
            		counts[j]-=subs;

            	if(counts[2]>0)
            	{
                    score[i]+=2*counts[2];
                    
                    subs=counts[2];
                    for(int j=2;j<=6;j++)
                    counts[j]-=subs;

                    if(counts[3]>0)
                    	score[i]+=counts[3];
                    
            	}
            	else 
            	{
                     if(counts[3]>0)
                     	score[i]+=counts[3];
                     
            	}
            }
            else 
            {
            	if(counts[2]>0)
            	{
            		score[i]+=2*counts[2];
            		
                    subs=counts[2];
                    for(int j=2;j<=6;j++)
                    counts[j]-=subs;

                    if(counts[3]>0)
                    	score[i]+=counts[3];
                    
            	}

            	else 
            	{
                     if(counts[3]>0)
                     	score[i]+=counts[3];
                     
            	}
            }

            
		}

        max=score[1];
        int winner=1;
        bool tie=false;
		for(int i=2;i<=n;i++)
		{
              if(score[i]>max)
              {
              	max=score[i];
              	winner=i;
              	tie=false;
              }
              else if(score[i]==max)
              {
              	tie=true;
              }
		}

		if(tie)
		cout<<"tie"<<endl;
		else if(winner==1)
			cout<<"chef"<<endl;
		else
			cout<<winner<<endl;
	}
	return 0;
}