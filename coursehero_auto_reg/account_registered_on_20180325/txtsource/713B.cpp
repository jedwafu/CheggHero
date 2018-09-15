#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
ll ans[3][3][3];
bool found=false;
bool both=false;
void findrx(int i,ll a,ll b)
{
	int ansn;
	if(a>b)
		return;
    
    cout<<"? "<<1<<" "<<1<<" "<<b<<" "<<n<<endl;
    fflush(stdout);
    cin>>ansn;
    

    if(ansn==2)
    {

      if(a==b)
      {
      	 found=true;
         both=true;
         ans[i][1][2]=a;
         ans[2][1][2]=a;
         return;
      }

      ll mid=(a+b)/2;
      findrx(i,a,mid);
      if(!found)
      findrx(i,mid+1,b);
    }

    else if(ansn==1)
    {
    	if(i==1)
       { 
       	if(a==b)
        {
       	found=true;
       	ans[i][1][2]=a;
       	return;
        }  
       
       ll mid=(a+b)/2;
      findrx(i,a,mid);
      if(!found)
      findrx(i,mid+1,b);
       
       }
    }

    return;

}

void findlx(int i,ll a,ll b)
{
      int ansn;
	    if(a>b)
		return;
    
    cout<<"? "<<a<<" "<<1<<" "<<n<<" "<<n<<endl;
    fflush(stdout);
    cin>>ansn;
    

    if(ansn==2)
    {
      if(a==b)
      {
      	 found=true;
         both=true;
         ans[i][1][1]=a;
         ans[1][1][1]=a;
         return;
      }

      ll mid=(a+b)/2;
      findlx(i,mid+1,b);
      if(!found)
      findlx(i,a,mid);
    }

    else if(ansn==1)
    {
    	if(i==2)
     {  if(a==b)
       {
       	found=true;
       	ans[i][1][1]=a;
       	return;
       }  
       
       ll mid=(a+b)/2;
      findlx(i,mid+1,b);
      if(!found)
      findlx(i,a,mid);
     }
    }

    return;	
}

void findry(int i,ll a,ll b)
{
	int ansn;
	if(a>b)
		return;
    
    cout<<"? "<<1<<" "<<1<<" "<<n<<" "<<b<<endl;
    fflush(stdout);
    cin>>ansn;
    

    if(ansn==2)
    {
      if(a==b)
      {
      	 found=true;
         both=true;
         ans[i][2][2]=a;
         ans[2][2][2]=a;
         return;
      }

      ll mid=(a+b)/2;
      findry(i,a,mid);
      if(!found)
      findry(i,mid+1,b);
    }

    else if(ansn==1)
    {
    	if(i==1)
     { 
      if(a==b)
       {
       	found=true;
       	ans[i][2][2]=a;
       	return;
       }  
       
       ll mid=(a+b)/2;
      findry(i,a,mid);
      if(!found)
      findry(i,mid+1,b);
      }
    }

    return;

}

void findly(int i,ll a,ll b)
{
      int ansn;
	    
	    if(a>b)
		return;
    
    cout<<"? "<<1<<" "<<a<<" "<<n<<" "<<n<<endl;
    fflush(stdout);
    cin>>ansn;
    

    if(ansn==2)
    {
      if(a==b)
      {
      	 found=true;
         both=true;
         ans[i][2][1]=a;
         ans[1][2][1]=a;
         return;
      }

      ll mid=(a+b)/2;
      findly(i,mid+1,b);
      if(!found)
      findly(i,a,mid);
    }

    else if(ansn==1)
    {
    	if(i==2)
     {  if(a==b)
       {
       	found=true;
       	ans[i][2][1]=a;
       	return;
       }  
       
       ll mid=(a+b)/2;
      findly(i,mid+1,b);
      if(!found)
      findly(i,a,mid);
      }
    }

    return;	
}

int main()
{
	
	cin>>n;
    
    ans[1][1][1]=ans[2][1][1]=1;
    ans[1][1][2]=ans[2][1][2]=n;
    ans[1][2][1]=ans[2][2][1]=1;
    ans[1][2][2]=ans[2][2][2]=n;

   found=both=false;
   findrx(1,1,n);
   found=false;
   
   cout<<"1yahan aa gya apun with "<<ans[1][1][2]<<endl;
   if(!both)
   findrx(2,ans[1][1][2]+1,n);
   
   cout<<"2yahan aa gya apun with "<<ans[2][1][2]<<endl;

   found=both=false;
   findlx(2,1,n);
   found=false;

   cout<<"3yahan aa gya apun with "<<ans[2][1][1]<<endl;
   if(!both)
   findlx(1,1,ans[2][1][1]-1); 
   
   cout<<"4yahan aa gya apun with "<<ans[1][1][1]<<endl;
   found=both=false;

   findry(1,1,n);
   found=false;
   cout<<"5yahan aa gya apun with "<<ans[1][2][2]<<endl;
   
   if(!both)
   findry(2,ans[1][2][2]+1,n);
   cout<<"6yahan aa gya apun with "<<ans[2][2][2]<<endl;

   found=both=false;
   findly(2,1,n);
   found=false;
   cout<<"7yahan aa gya apun with "<<ans[2][2][1]<<endl;

   if(!both)
   findly(1,1,ans[2][2][1]-1); 
   cout<<"8yahan aa gya apun with "<<ans[1][2][1]<<endl;

    cout<<"! "<<ans[1][1][1]<<" "<<ans[1][2][1]<<" "<<ans[1][1][2]<<" "<<ans[1][2][2]<<" "<<ans[2][1][1]<<" "<<ans[2][2][1]<<" "<<ans[2][1][2]<<" "<<ans[2][2][2]<<endl;
    fflush(stdout);

    return 0;
}