#include <bits/stdc++.h>
using namespace std;

long long int pes[100010];
int s[100010];
int n;
void calculateSpan()
{
   
   stack<int> st;
   st.push(0);

   s[0] = 1;

   for (int i = 1; i < n; i++)
   {
      
      while (!st.empty() && pes[st.top()] > pes[i])
         st.pop();
         
      s[i] = (st.empty())? (0) : (i - st.top());

      st.push(i);
   }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>pes[i];
    
    calculateSpan();

    sort(s,s+n);
    cout<<s[n-1];
    return 0;
}
