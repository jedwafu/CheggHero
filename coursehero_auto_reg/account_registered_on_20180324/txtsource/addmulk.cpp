#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%lld", &n)
#define ll long long int
#define M 1000000007

struct ADDMUL
{
    ll add, mul, ini, sum;
    ADDMUL()
    {
        add=0;
        mul=1;
        ini=-1;
        sum=0;
    }
}A[400000];

void query1(ll ss, ll se, ll qs, ll qe, ll x, ll val)
{
    if(ss == qs && se == qe)
    {
        A[x].add = (A[x].add + val)%M;
        A[x].sum = (A[x].sum + (val*(qe-qs+1))%M)%M;
        return;
    }
    
    ll m = (ss + se)/2;
    if(A[x].ini!=-1)
    {
        A[2*x].ini=A[x].ini;
        A[2*x+1].ini=A[x].ini;
        A[x].ini=-1;
        A[2*x].mul=1;
        A[2*x+1].mul=1;
        A[2*x].add=0;
        A[2*x+1].add=0;
        A[2*x].sum=(A[2*x].ini*(m-ss+1))%M;
        A[2*x+1].sum=(A[2*x+1].ini*(se-m))%M;
    }
    
    A[2*x].mul=(A[2*x].mul*A[x].mul)%M;
    A[2*x].add=((A[2*x].add*A[x].mul)%M+A[x].add);
    
    while(A[2*x].add>M)
        A[2*x].add-=M;
    A[2*x+1].mul=(A[2*x+1].mul*A[x].mul)%M;
    A[2*x+1].add=((A[2*x+1].add*A[x].mul)%M+A[x].add);
    while(A[2*x+1].add>M)
        A[2*x+1].add-=M;
    A[2*x].sum=((A[2*x].sum*A[x].mul)%M+(A[x].add*(m-ss+1))%M);
    while(A[2*x].sum>M)
        A[2*x].sum-=M;
    A[2*x+1].sum=((A[2*x+1].sum*A[x].mul)%M+(A[x].add*(se-m))%M);
    while(A[2*x+1].sum>M)
        A[2*x+1].sum-=M;
    A[x].add=0;
    A[x].mul=1;
    if(qe <= m)
    {
        query1(ss,m,qs,qe,2*x,val);
    }
    else if(qs > m)
    {
        query1(m+1,se,qs,qe,2*x+1,val);
    }
    else
    {
        query1(ss,m,qs,m,2*x,val);
        query1(m+1,se,m+1,qe,2*x+1,val);
    }
    A[x].sum = (A[2*x].sum + A[2*x+1].sum)%M;
}

void query2(ll ss, ll se, ll qs, ll qe, ll x, ll val)
{
    if(ss == qs && se == qe)
    {
        A[x].mul = (A[x].mul*val)%M;
        A[x].add = (A[x].add*val)%M;
        A[x].sum = (A[x].sum*val)%M;
        return;
    }
    ll m = (ss + se)/2;
    if(A[x].ini!=-1)
    {
        A[2*x].ini=A[x].ini;
        A[2*x+1].ini=A[x].ini;
        A[x].ini=-1;
        A[2*x].mul=1;
        A[2*x+1].mul=1;
        A[2*x].add=0;
        A[2*x+1].add=0;
        A[2*x].sum=(A[2*x].ini*(m-ss+1))%M;
        A[2*x+1].sum=(A[2*x+1].ini*(se-m))%M;
    }
    A[2*x].mul=(A[2*x].mul*A[x].mul)%M;
    A[2*x].add=((A[2*x].add*A[x].mul)%M+A[x].add);
    while(A[2*x].add>M)
        A[2*x].add-=M;
    A[2*x+1].mul=(A[2*x+1].mul*A[x].mul)%M;
    A[2*x+1].add=((A[2*x+1].add*A[x].mul)%M+A[x].add);
    while(A[2*x+1].add>M)
        A[2*x+1].add-=M;
    A[2*x].sum=((A[2*x].sum*A[x].mul)%M+(A[x].add*(m-ss+1))%M);
    while(A[2*x].sum>M)
        A[2*x].sum-=M;
    A[2*x+1].sum=((A[2*x+1].sum*A[x].mul)%M+(A[x].add*(se-m))%M);
    while(A[2*x+1].sum>M)
        A[2*x+1].sum-=M;
    A[x].add=0;
    A[x].mul=1;
    if(qe <= m)
    {
        query2(ss,m,qs,qe,2*x,val);
    }
    else if(qs > m)
    {
        query2(m+1,se,qs,qe,2*x+1,val);
    }
    else
    {
        query2(ss,m,qs,m,2*x,val);
        query2(m+1,se,m+1,qe,2*x+1,val);
    }
    A[x].sum = (A[2*x].sum + A[2*x+1].sum)%M;
}

void query3(ll ss, ll se, ll qs, ll qe, ll x, ll val)
{
    if(ss == qs && se == qe)
    {
        A[x].ini = val;
        A[x].sum = ((qe - qs + 1)*val)%M;
        A[x].add = 0;
        A[x].mul = 1;
        return;
    }
    ll m = (ss + se)/2;
    if(A[x].ini!=-1)
    {
        A[2*x].ini=A[x].ini;
        A[2*x+1].ini=A[x].ini;
        A[x].ini=-1;
        A[2*x].mul=1;
        A[2*x+1].mul=1;
        A[2*x].add=0;
        A[2*x+1].add=0;
        A[2*x].sum=(A[2*x].ini*(m-ss+1))%M;
        A[2*x+1].sum=(A[2*x+1].ini*(se-m))%M;
    }
    A[2*x].mul=(A[2*x].mul*A[x].mul)%M;
    A[2*x].add=((A[2*x].add*A[x].mul)%M+A[x].add);
    while(A[2*x].add>M)
        A[2*x].add-=M;
    A[2*x+1].mul=(A[2*x+1].mul*A[x].mul)%M;
    A[2*x+1].add=((A[2*x+1].add*A[x].mul)%M+A[x].add);
    while(A[2*x+1].add>M)
        A[2*x+1].add-=M;
    A[2*x].sum=((A[2*x].sum*A[x].mul)%M+(A[x].add*(m-ss+1))%M);
    while(A[2*x].sum>M)
        A[2*x].sum-=M;
    A[2*x+1].sum=((A[2*x+1].sum*A[x].mul)%M+(A[x].add*(se-m))%M);
    while(A[2*x+1].sum>M)
        A[2*x+1].sum-=M;
    A[x].add=0;
    A[x].mul=1;
    if(qe <= m)
    {
        query3(ss,m,qs,qe,2*x,val);
    }
    else if(qs > m)
    {
        query3(m+1,se,qs,qe,2*x+1,val);
    }
    else
    {
        query3(ss,m,qs,m,2*x,val);
        query3(m+1,se,m+1,qe,2*x+1,val);
    }
    A[x].sum = (A[2*x].sum + A[2*x+1].sum)%M;
}

ll query4(ll ss, ll se, ll qs, ll qe, ll x)
{
    if(ss == qs && se == qe)
    {
        return A[x].sum%M;
    }
    ll m = (ss + se)/2;
    if(A[x].ini!=-1)
    {
        A[2*x].ini=A[x].ini;
        A[2*x+1].ini=A[x].ini;
        A[x].ini=-1;
        A[2*x].mul=1;
        A[2*x+1].mul=1;
        A[2*x].add=0;
        A[2*x+1].add=0;
        A[2*x].sum=(A[2*x].ini*(m-ss+1))%M;
        A[2*x+1].sum=(A[2*x+1].ini*(se-m))%M;
    }
    A[2*x].mul=(A[2*x].mul*A[x].mul)%M;
    A[2*x].add=((A[2*x].add*A[x].mul)%M+A[x].add);
    while(A[2*x].add>M)
        A[2*x].add-=M;
    A[2*x+1].mul=(A[2*x+1].mul*A[x].mul)%M;
    A[2*x+1].add=((A[2*x+1].add*A[x].mul)%M+A[x].add);
    while(A[2*x+1].add>M)
        A[2*x+1].add-=M;
    A[2*x].sum=((A[2*x].sum*A[x].mul)%M+(A[x].add*(m-ss+1))%M);
    while(A[2*x].sum>M)
        A[2*x].sum-=M;
    A[2*x+1].sum=((A[2*x+1].sum*A[x].mul)%M+(A[x].add*(se-m))%M);
    while(A[2*x+1].sum>M)
        A[2*x+1].sum-=M;
    A[x].add=0;
    A[x].mul=1;
    A[x].sum = (A[2*x].sum + A[2*x+1].sum)%M;
    if(qe <= m)
    {
        return query4(ss,m,qs,qe,2*x);
    }
    else if(qs > m)
    {
        return query4(m+1,se,qs,qe,2*x+1);
    }
    else
    {
        return (query4(ss,m,qs,m,2*x) + query4(m+1,se,m+1,qe,2*x+1))%M;
    }
}

int main()
{
    ll N, Q, a, q, x, y, v;
    s(N);
    s(Q);
    for(ll i=0;i<N;i++)
    {
        s(a);
        query1(1,N,i+1,i+1,1,a);
    }
    for(ll i=1;i<=Q;i++)
    {
        s(q);
        s(x);
        s(y);
        if(q==1)
        {
            s(v);
            query1(1,N,x,y,1,v);
        }
        else if(q==2)
        {
            s(v);
            query2(1,N,x,y,1,v);
        }
        else if(q==3)
        {
            s(v);
            query3(1,N,x,y,1,v);
        }
        else
            printf("%lld\n", query4(1,N,x,y,1));
        //for(ll ij=1;ij<8;ij++)
            //cout<<ij<<"-> add: "<<A[ij].add<<" mul: "<<A[ij].mul<<" ini: "<<A[ij].ini<<" sum: "<<A[ij].sum<<endl;
    }
    return 0;    
}
