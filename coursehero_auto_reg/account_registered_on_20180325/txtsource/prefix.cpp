#include<iostream>
using namespace std;

char arr[1000];
int top=0;

float calc()
{
	if(arr[top]=='+' or arr[top]=='-' or arr[top]=='*' or arr[top]=='/')
    {
    	char oper=arr[top];
		top++;
    	
    	float val1 = calc();
    	float val2=calc();
        
        
		if(oper=='+')
		{
		cout<<"adding "<<val1<<" and "<<val2<<endl;
        return val1+val2;
        }
        
		else if(oper=='-')
        {
        cout<<"subtracting "<<val1<<" and "<<val2<<endl;
		return val1-val2;
        }
        
		else if(oper=='*')
        {
         cout<<"multiplying "<<val1<<" and "<<val2<<endl;
		 return val1*val2;
        }
        
        cout<<"dividing "<<val1<<" and "<<val2<<endl;
        return val1/val2;
	}
	
	else
	{
		float temp=arr[top]-'0';
		top++;
		return temp;
	}
}

int main()
{
	int n;
	char c;
	
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>c;
		arr[i]=c;
	}
	
	float val=calc();
	
	cout<<val<<endl;
	return 0;
}
