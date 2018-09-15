#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string s;
int main()
{
   cin>>s;
   double penalty=0;
   int len = s.length();
   int left=0,right=len-1;
   while(left<right)
   {
   	   if(s[right]=='1')
   	   	right--;
   	   
   	   else if(s[right]=='0')
   	   {
           while(s[left]=='0'&& left<right)
           	left++;

           if(left >= right)
           	break;
            
           penalty+=sqrt(right-left);
           left++;
           right--; 
   	   }
   }

    cout<<setprecision(12);
    cout<<penalty<<endl;

return 0;
}