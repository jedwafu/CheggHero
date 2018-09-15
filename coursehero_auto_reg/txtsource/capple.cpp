#include<iostream>
#include<stdio.h>


using namespace std;

int original[100000];
int temp[100000];
		
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
	int t,n,count,i;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		count=1;
		
		for( i=0;i<n;i++)
		cin>>original[i];
		
		sort(0,n-1);
		
		
		for(i=0;i<n-1;i++)
		{
			if(original[i]!=original[i+1])
			count++;
		}
		cout<<count<<"\n";
		
	}
	
	return 0;
}
