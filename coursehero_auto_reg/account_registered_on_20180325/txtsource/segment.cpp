#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long int rat[100010];
long long int val[100010];
long long int sums[100010]; 
long long int dp[100010][501];
queue<int>q;
struct node
{
	int low,high;
	node *p,*l,*r;
	vector<pair< pair<long long int,long long int>,long long int> > v;
};
node *root;

void sinsert(node *&par,int lo,int hi)
{
	
	node *temp=new node;
	temp->low=lo;
	temp->high=hi;
	temp->p=par;
	temp->l=NULL;
	temp->r=NULL;
	
	if(temp->low==par->low)
	par->l=temp;
	else
	par->r=temp;
	
	if(lo!=hi)
	{
	  sinsert(temp,lo,(lo+hi)/2);
	  sinsert(temp,(lo+hi)/2+1,hi);
    }
	
}

void pinsert(node *&root,long long int le,long long int ri,long long int c)
{
	if(root==NULL)
	return;
	
	
	if(le<=root->low && ri>=root->high)
	{
		root->v.push_back(make_pair(make_pair(le,ri),c));
		return;
	}
	else
	{
		if(le<=root->l->high)
		pinsert(root->l,le,ri,c);
		if(ri>=root->r->low)
		pinsert(root->r,le,ri,c);
	}
}

void qsearch(node *&root,int i)
{
	if(root->low<=i && root->high>=i)
	{
		for(int j=0;j<root->v.size();j++)
		{
				val[i]=min(val[i],root->v[j].second);
		}
	}
	
	if(root->l!=NULL && root->r!=NULL)
	{
		if(root->l->low<=i && root->l->high>=i)
		qsearch(root->l,i);
		if(root->r->low<=i && root->r->high>=i)
		qsearch(root->r,i);
	}
	
}

void sprint(node *&root)
{
	if(root==NULL)
	return;
	
	if(root->v.empty()==false)
	{
		root->v.clear();
		//for(int j=0;j<root->v.size();j++)
		//cout<<root->v[j].first.first<<" "<<root->v[j].first.second<<" "<<root->v[j].second<<endl;
	}
	sprint(root->l);
	sprint(root->r);
	
}

int main()
{
	
	root=new node;
	root->low=0;
	root->high=100000;
	root->p=NULL;
	root->l=NULL;
	root->r=NULL;
	sinsert(root,0,100000/2);
	sinsert(root,100000/2 +1,100000);
	
	long long int t,minc=600;
	cin>>t;
	while(t--)
	{
		minc=600;
		cin>>n>>k>>m;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&rat[i]);
			
			if(rat[i]<0)
			q.push(i);
			
			val[i]=600;
			if(i==0)
			sums[i]=rat[i];
			else
			sums[i]=sums[i-1]+rat[i];
		}
		
		
		for(int i=0;i<m;i++)
		{
			long long int l,r,c;
			
			scanf("%lld %lld %lld",&l,&r,&c);
			minc=min(c,minc);
			pinsert(root,l-1,r-1,c);
			
		}
		
		
		while(q.empty()==false)
		{
			int top=q.front();
			q.pop();
			qsearch(root,top);
		}
		
		
		for(int i=0;i<minc;i++)
		{
			for(int j=0;j<n;j++)
			dp[j][i]=sums[j];
		}
		
		
		for(int j=minc;j<=k;j++)
		{
			if(rat[0]<0 && val[0]<=j)
			dp[0][j]=0;
			else
			dp[0][j]=rat[0];
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=minc;j<=k;j++)
			{
				if(j-val[i]>=0)
				dp[i][j]=max((dp[i-1][j]+rat[i]),(dp[i-1][j-val[i]]));
				else
				dp[i][j]=dp[i-1][j]+rat[i];
				
			//	cout<<"dp["<<i<<"]["<<j<<"] is"<<dp[i][j]<<endl;
			}
		}
		
		cout<<dp[n-1][k]<<endl;
		sprint(root);
			
    }
    
	return 0;
}
