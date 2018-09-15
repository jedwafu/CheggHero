#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int rat[100010];
int val[100010];
int sums[100010];

struct node
{
	int low,high;
	int cost;
	node* left;
	node* right;
	node* parent;
	int color;
};

node *root=NULL;

void leftrotate(node *x)
{
	node* y=x->right;
	x->right=y->left;
	if(y->left!=NULL)
	y->left->parent=x;
	
	y->parent=x->parent;
	if(x->parent==NULL)
	root=y;
	else if(x==x->parent->left)
	x->parent->left=y;
	else
	x->parent->right=y;
	
	y->left=x;
	x->parent=y;
	
	//delete y;
}

void rightrotate(node *x)
{
	node* y=x->left;
	x->left=y->right;
	if(y->right!=NULL)
	y->right->parent=x;
	
	y->parent=x->parent;
	if(x->parent==NULL)
	root=y;
	else if(x==x->parent->right)
	x->parent->right=y;
	else
	x->parent->left=y;
	y->right=x;
	x->parent=y;
	
	//delete y;
}

void rbfixup(node* z)
{
	while(z->parent->color==1)
	{
		if(z->parent==z->parent->parent->left)
		{
			node* y=z->parent->parent->right;
			if(y->color==1)
			{
				z->parent->color=2;
				y->color=2;
				z->parent->parent->color=1;
				z=z->parent->parent;
			}
			else if(z==z->parent->right)
			{
				z=z->parent;
				leftrotate(z);
			}
			
			z->parent->color=2;
			z->parent->parent->color=1;
			rightrotate(z->parent->parent);
		}
			
			//delete y;
		
		else
		{
			node* y=z->parent->parent->left;
			if(y->color==1)
			{
				z->parent->color=2;
				y->color=2;
				z->parent->parent->color=1;
				z=z->parent->parent;
			}
			else if(z==z->parent->left)
			{
				z=z->parent;
				rightrotate(z);
			}
				z->parent->color=2;
				z->parent->parent->color=1;
				//leftrotate(z->parent->parent);
			
			//delete y;
		}
		
	}
	root->color=2;
}

void rbinsert(node* z)
{
	if(root==NULL)
	{
		root=z;
		root->parent=NULL;
		root->left=NULL;
		root->right=NULL;
		root->color=1;
		return;
	}
	
	node *x=NULL;
	node *y=root;
	while(x!=NULL)
	{
		y=x;
		if(z->low<x->low)
		x=x->left;
		else
		x=x->right;	
	}
	z->parent=y;
	if(y==NULL)
	root=z;
	else if(z->low<y->low)
	y->left=z;
	else
	y->right=z;
	
	z->left=NULL;
	z->right=NULL;
	z->color=1;
	
	//delete x;
	//delete y;
	
	rbfixup(z);
	//leftrotate(z);
	//rightrotate(z);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>m;
		for(int i=0;i<n;i++)
		{
			cin>>rat[i];
			val[i]=600;
			if(i==0)
			sums[i]=rat[i];
			else
			sums[i]=sums[i-1]+rat[i];
		}
		
		
		
		for(int i=0;i<m;i++)
		{
			long long int l,r,c;
			cin>>l>>r>>c;
			node *temp=new node;
			{
				temp->cost=c;
				temp->low=l;
				temp->high=r;
				temp->left=NULL;
				temp->right=NULL;
				temp->parent=NULL;
			}
			rbinsert(temp);
		}
		
		
		
	}
	return 0;
}
