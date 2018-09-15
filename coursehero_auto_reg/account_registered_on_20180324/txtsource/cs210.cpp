#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct element
{
	int identity;
	int size;
	element *belongs_to;
	element *next;
    
};
element **numbers,**sets;


void build(int n)
{
	for(int i=0;i<n;i++)
	{
		sets[i]=new element;
		sets[i]->belongs_to=NULL;
		sets[i]->identity=i+1;
		sets[i]->size=1;
		
		numbers[i]=new element;
		sets[i]->next=numbers[i];
		numbers[i]->belongs_to=sets[i];
		numbers[i]->next=NULL;
	}
}

void _size(int a)
{
	cout<<numbers[a-1]->belongs_to->size<<endl;
}

void _set(int a)
{
	cout<<numbers[a-1]->belongs_to->identity<<endl;
}

void _union(int a,int b)
{
	element *temp1=numbers[a-1]->belongs_to;
	element *temp2=numbers[b-1]->belongs_to;
	element *temp3=NULL;
	
	if(temp1->size >= temp2->size)
	{
		temp3=temp1;
		
		while(temp3->next!=NULL)
		temp3=temp3->next;
		
		temp3->next=temp2->next;
		while(temp3!=NULL)
		{
			temp3->belongs_to=temp1;
			temp3=temp3->next;
		}
		temp1->size+=temp2->size;
	}
	else
	{
		temp3=temp2;
		
		while(temp3->next!=NULL)
		temp3=temp3->next;
		
		temp3->next=temp1->next;
		while(temp3!=NULL)
		{
			temp3->belongs_to=temp2;
			temp3=temp3->next;
		}
		
		temp2->size+=temp1->size;
	}

}

int main()
{
	int n;
	cin>>n;
	numbers= (element **)malloc(n*sizeof(element*));
	sets= (element **)malloc(n*sizeof(element*));	
	
	for(int i=0;i<n;i++)
	{
	  numbers[i]=NULL;
	  sets[i]=NULL;
    }
    
	build(10);
	_union(1,2);
	_size(1);
	_union(1,2);
	_set(3);
	_union(3,5);
	_set(5);
	
	//parse(take) your input here and call respective functions. 
	//check correctness by testing.
	return 0;
}
