#include<iostream>
using namespace std;

struct next{
	int vertex;
	int weight;
	next *link;
};

int main()
{
   int n,i,a,b,w,q;
   cin>>n;
   cin>>q;
   next *ver= new next[n];
   next **head= new next*[n];
   next *temp;
   
   for(i=0;i<n;i++)
   {
   	ver[i].vertex=i;
   	ver[i].weight=0;
   	ver[i].link=NULL;
   	head[i]=&ver[i];
   }
   for(i=0;i<q;i++)
   {
   	cin>>a>>b>>w;
   	temp= new next;
   	head[a]->link=temp;
   	head[a]=temp;
   	temp->vertex=b;
   	temp->weight=w;
   	temp->link=NULL;
   }


   
   
   return 0;
}
