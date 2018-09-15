#include<iostream>

using namespace std;

long long int original[2][10000];
long long int temp[2][10000];
		
void copy(int start1, int end2)
{
int k;
for(k=start1;k<=end2;k++)
{original[0][k]=temp[0][k];
 original[1][k]=temp[1][k];
}
}

void merge(int start1,int end1,int start2,int end2)
{
int i=start1,j=start2;
int k;
for(k=start1;k<=end2;k++)
{
if(i<start2 &&(j>end2 || original[0][i]<=original[0][j] ))
{
temp[0][k]=original[0][i];
temp[1][k]=original[1][i];
i++;
}

else
{
temp[0][k]=original[0][j];
temp[1][k]=original[1][j];
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
	int t,i,n,count,temp;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		count=1;
		
		for(i=0;i<n;i++)
		{
			cin>>original[1][i]>>original[0][i];
		}
	
	
	sort(0,n-1);
	temp=original[0][0];
	
	for(i=1;i<n;i++)
	{
		if(original[1][i]>temp)
		{
			count++;
			temp=original[0][i];
		}
	}
	
	cout<<count<<endl;
	
    }
    
    return 0;
}
