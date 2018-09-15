#include<bits/stdc++.h>
using namespace std;

#define take(n) scanf("%d",&n)
#define loop(i,a,b) for(int i=a;i<b;i++)

int len[100010];
vector<pair <int,int> >arr;
int sum[100010];
int counting[201];
int main()
{
	loop(i,1,100001)
	sum[i]=0;
	
	loop(i,1,201)
	{
		counting[i]=0;
	}
	
	int n,temp;
	cin>>n;
	loop(i,0,n)
	{
	   take(len[i]);
	}
	
	loop(i,0,n)
	{
		cin>>temp;
		sum[len[i]]+=temp;
		arr.push_back(make_pair(len[i],temp));
	}
	
	sort(arr.begin(),arr.end());
	sum[n]=0;
	sum[n-1]=arr[n-1].second;
	
	for(int i=n-2;i>=0;i--)
	{
		sum[i]=sum[i+1]+arr[i].second;
	}
	
    
    int counts=1,cur=sum[0];
    int i;
   for(i=0;i<n-1;i++)
   {
   	  int j=i;
   	 while(arr[j].first==arr[j+1].first)
   	 {
		counts++;
		j++;
		//counting[arr[i].second]++;
	 }
	 
	  i=i+counts-1;
	 
   	  if(arr[i].first!=arr[i+1].first||(arr[i].first==arr[i+1].first && i==n-2))
   	 {
   	 	if((arr[i].first==arr[i+1].first && i==n-2))
   	 	{
			i++;
   	    }
   	    
   	 	int prev=i-counts+1;
   	 	temp=sum[i+1];
   	 	int k=1;
   	 	int temp2=counting[1];
   	 	while(counts<=prev)
   	 	{
   	 		 
   	 		if(temp2>0)
   	 		{ 
   	 		    //cout<<k<<" ";
   	 			temp+=k;
   	 			temp2--;
   	 			prev--;
			}
				else
				{
					k++;
					temp2=counting[k];
				}
		}
			
			for(int k=i-counts+1;k<=i;k++)
			{
				counting[arr[k].second]++;
			}
	 
		//cout<<temp<<" for value"<<arr[i].first;
		counts=1;
		cur=min(cur,temp);
		//cout<<cur<<endl;
		//counting[arr[i].second]++;
	 }
   }
	
	cout<<cur;
	return 0; 
	
}
