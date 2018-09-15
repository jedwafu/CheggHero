#include <iostream>
#include <cstring>
using namespace std;
char L[100001];
int a,b,c;
int A[100001],B[100001],C[100001];
int s;
int r1,r2;
int p1,p2;
bool e0,ok1,ok2;
int i;
void copiere(int X[],int &dim)
{
    for(int i=1; i<=a; i++)
        X[i]=A[i];
    dim=a;
}
int cautaultim(int X[],int dim, int rest)
{
    int i=dim;
    while(i>=1 && X[i]%3!=rest)
        i--;
    return i;

}
void elimina(int A[],int &dim,int poz)
{
    for(int i=poz+1; i<=dim; i++)
        A[i-1]=A[i];
    dim--;
}
void stergezero(int A[],int &dim)
{
    int u=1;
    while(A[u]==0 && u<dim)
        u++;
    u--;
    if(u!=0)
    {
        for(int i=u+1; i<=dim; i++)
            A[i-u]=A[i];
        dim-=u;
    }
}
int main()
{
    cin>>L;
    a=strlen(L);
    for(i=1; i<=a; i++)
    {
        A[i]=L[i-1]-'0';
        if(A[i]==0)
            e0=true;
        s+=A[i];
    }
    if(s%3==0)
        for(i=1; i<=a; i++)
            cout<<A[i];
    else if(s%3==1)
    {
        copiere(B,b);
        //scoatem M3+1
        int poz=cautaultim(B,b,1);
        if(poz!=0)
        {
            elimina(B,b,poz);
            stergezero(B,b);
        }
        ok1=true;
        if(b==0 || poz==0)
            ok1=false;
        if(b==0 && e0)
        {
            ok1=true;
            b=1;
            B[1]=0;
        }
        //scoatem 2 M3+2
        copiere(C,c);
        ok2=true;
        p1=cautaultim(C,c,2);
        if(p1!=0)
        {
            elimina(C,c,p1);
            p2=cautaultim(C,c,2);
            if(p2!=0)
            {
                elimina(C,c,p2);
                stergezero(C,c);
            }
        }
        if(p2==0 || c==0)
            ok2=false;
        if(c==0 && e0)
        {
            ok2=true;
            c=1;
            C[1]=0;
        }
        if(!ok1 && !ok2)
            cout<<-1;
        else if((b>=c && ok1) || (b<c && !ok2))
            for(i=1; i<=b; i++)
                cout<<B[i];
        else
            for(i=1; i<=c; i++)
                cout<<C[i];
    }
    else
    {
        copiere(B,b);
        //scoatem M3+2
        int poz=cautaultim(B,b,2);
        if(poz!=0)
        {
            elimina(B,b,poz);
            stergezero(B,b);
        }
        ok1=true;
        if(b==0 || poz==0)
            ok1=false;
        if(b==0 && e0)
        {
            ok1=true;
            b=1;
            B[1]=0;
        }
        //scoatem 2 M3+1
        copiere(C,c);
        ok2=true;
        p1=cautaultim(C,c,1);
        if(p1!=0)
        {
            elimina(C,c,p1);
            p2=cautaultim(C,c,1);
            if(p2!=0)
            {
                elimina(C,c,p2);
                stergezero(C,c);
            }
        }
        if(p2==0 || c==0)
            ok2=false;
        if(c==0 && e0)
        {
            ok2=true;
            c=1;
            C[1]=0;
        }
        if(!ok1 && !ok2)
            cout<<-1;
        else if((b>=c && ok1) || (b<c && !ok2))
            for(i=1; i<=b; i++)
                cout<<B[i];
        else
            for(i=1; i<=c; i++)
                cout<<C[i];
    }

    return 0;
}