#include<iostream>
#include<cstdlib>

using namespace std;

int compare (const void *elem1, const void *elem2){
    return *(int*)elem1 - *(int*)elem2;
}

int main()
{
	
	int t,n,i,j,count;
	int pies[30];
	int racks[30];
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>pies[i];
		
		for(i=0;i<n;i++)
		cin>>racks[i];
		
		qsort(pies, n, sizeof(int), compare);
		qsort(racks, n, sizeof(int), compare);
		 
		 j=n-1;
		 count=0;
		 
        for(i=n-1;i>=0;i--)
        {
        	if(racks[j]>=pies[i])
        	{
        		count++;
        		j--;
			}
		}
		
		cout<<count<<endl;

	}
	
}
