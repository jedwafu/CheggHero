#include<iostream>

using namespace std;
int original[2][100001];
int temp[2][100001];
		
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
	int t,n,i,j,m,x,y;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>m;
			
			cin>>x>>y;
			original[0][i]=x;
			original[1][i]=i;
			
			for(j=1;j<m;j++)
			{
				cin>>x>>y;
				if(x<original[0][i])
				original[0][i]=x;
			}
			
		}
	
		
		sort(0,n-1);
		
		for(i=0;i<n;i++)
		{
			temp[0][original[1][i]]=n-i-1;
		}
		
		for(i=0;i<n;i++)
		{
			cout<<temp[0][i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
