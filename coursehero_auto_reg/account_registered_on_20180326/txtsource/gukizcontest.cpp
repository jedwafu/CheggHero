#include<iostream>
#include<algorithm>
using namespace std;

int original[2][2000];
int temp[2][2000];
		
void copy(int start1, int end2)
{
int k;
for(k=start1;k<=end2;k++)
{
original[0][k]=temp[0][k];
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
	int n,carry=1,i;
	
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>original[0][i];
		original[1][i]=i;
	}
	
	sort(0,n-1);
	
	temp[0][original[1][n-1]]=1;
	for(i=n-2;i>=0;i--)
	{
		if(original[0][i]==original[0][i+1])
		{
			temp[0][original[1][i]]=temp[0][original[1][i+1]];
			carry++;
		}
		else
		{
		
		temp[0][original[1][i]]=temp[0][original[1][i+1]]+carry;
		carry=1;
	    }
	}
	
	for(i=0;i<n;i++)
	{
		cout<<temp[0][i]<<" ";
	}

return 0;	
}
