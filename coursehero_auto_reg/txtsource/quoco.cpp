#include<iostream>

using namespace std;

int original[100];
int temp[100];
		
void copy(int start1, int end2)
{
int k;
for(k=start1;k<=end2;k++)
original[k]=temp[k];
}

void merge(int start1,int end1,int start2,int end2)
{
int i=start1,j=start2;
int k;
for(k=start1;k<=end2;k++)
{
if(i<start2 &&(j>end2 || original[i]<=original[j] ))
{
temp[k]=original[i];
i++;
}

else
{
temp[k]=original[j];
j++;
}

}

}
void sort(int start,int end)
{
if(start==end)
return;

else
{
int n=end-start;

sort(start,start+n/2);
sort(start+n/2+1,end);
merge(start,start+n/2,start+n/2+1,end);
copy(start,end);
}

}




int main()
{
	int t,n,c,i,sum,temp,prev;
	int dummy[100];
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		sum=0;
		temp=0;
		
		for(i=0;i<100;i++)
		dummy[i]=0;
		
		for(i=0;i<n;i++)
		{
			cin>>original[i];
			sum=sum+original[i];
	    }
	     
	     if(2*c<sum)
	     {
		 cout<<"NO"<<endl;
	     continue;
	     }
	     
	     else cout<<"YES"<<endl;
	     
	     if(sum<=c)
	     {
	     	cout<<endl;
	     	for(i=0;i<n-1;i++)
	     	cout<<original[i]<<" ";
	     	cout<<original[i];
	     	return 0;
		 }
		 
	     sort(0,n-1);
	     
		 temp=original[0];
	     prev=0;
	     
	     for(i=1;i<n;i++)
	     {
	     	temp=temp+original[i];
	     	
	     	if(sum-temp<=c && temp<=c)
	     	{
	     		  dummy[prev]=-1;
	      		  dummy[i]=-1;
				  break;
			 }
			 
			 else  
			 {
			 	if(sum-temp>c)
			 	{
			 		dummy[prev]=-1;
			 		prev=i;
				 }
				 
				 if(temp>c)
				 {
				 	temp=temp-original[prev];
				 	dummy[prev]=0;
				 	if(sum-temp<=c)
				 	{
				 		dummy[i]=-1;
				 		break;
					 }
				 }
			 	
			 }
			 
			 
		 }
		 
		 for(i=0;i<n;i++)
		 {
		 	if(dummy[i]==-1)
		 	cout<<original[i]<<" ";
		 }
		 
		 cout<<endl;
		 
		 for(i=0;i<n;i++)
		 if(dummy[i]==0)
		 cout<<original[i]<<" ";
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
	
}
