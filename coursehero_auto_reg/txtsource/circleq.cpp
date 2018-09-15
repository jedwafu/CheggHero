include<bits/stdc++.h>
using namespace std;
#define ll long long int
double epsilon =.000001;

double triangle_area(double x1,double y1,double x2,double y2,double x3, double y3)
{
	double temp=(x1-x3)*(y2-y1);
	temp-= (x1-x2)*(y3-y1);
	temp=abs(temp);
	return temp/2;
}

double segment_area(double x1,double y1,double x2,double y2,double x3, double y3)
{
	double dx21 = x2-x1;
    double dx31 = x3-x1;
    double dy21 = y2-y1;
    double dy31 = y3-y1;
    double m12 = sqrt( dx21*dx21 + dy21*dy21 );
    double m13 = sqrt( dx31*dx31 + dy31*dy31 );
    double theta = acos( (dx21*dx31 + dy21*dy31) / (m12 * m13) );

    double radius= m12;
    double area=(.5)*radius*radius*theta;
    double area2=triangle_area(x1,y1,x2,y2,x3,y3); 
    return area-area2;
}

double arr[3][50010];
int main()
{
	double n,q,area=0;
	cin>>n>>q;

	for(int i=0;i<n;i++)
	cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
    
    for(int i=0;i<q;i++)
    {
    	double x1,y1,x2,y2,x3,y3,x4,y4;
    	cin>>x1>>y1>>x2>>y2;
        x3=x2;y3=y1;x4=x1;y4=y2;
        
        bool flag1=false,flag2=false,flag3=false,flag4=false;
        for(int j=0;j<n;j++)
        {
             int count=0;
             if(abs((x1-arr[0][i])*(x1-arr[0][i]) + (y1-arr[1][i])*(y1-arr[1][i]) - arr[2][i]*arr[2][i])<epsilon)
             	count++,flag1=true;
             if(abs((x2-arr[0][i])*(x2-arr[0][i]) + (y2-arr[1][i])*(y2-arr[1][i]) - arr[2][i]*arr[2][i])<epsilon)
             	count++,flag2=true;
             if(abs((x3-arr[0][i])*(x3-arr[0][i]) + (y3-arr[1][i])*(y3-arr[1][i]) - arr[2][i]*arr[2][i])<epsilon)
             	count++,flag3=true;
             if(abs((x4-arr[0][i])*(x4-arr[0][i]) + (y4-arr[1][i])*(y4-arr[1][i]) - arr[2][i]*arr[2][i])<epsilon)
             	count++,flag4=true;

             if(count==4)
             	area+=(x2-x1)*(y2-y1);
             if(count==3)
             {
                double p1,p2;
                if(!flag1)
             	p1=x1,p2=y1;
                else if(!flag2)
             	p1=x2,p2=y2;
                else if(!flag3)
             	p1=x3,p2=y3;
                else if(!flag4)
             	p1=x4,p2=y4;

                double temp = (arr[2][i]*arr[2][i]-(p1-arr[0][i])*(p1-arr[0][i]));
                temp= sqrt(temp);
                double q1=arr[1][0]+temp;
                double q2=arr[1][0]-temp;
                if(abs(q1-p2)>abs(q2-p2))
                	q1=q2;
                
                temp=(arr[2][i]*arr[2][i]-(p2-arr[1][i])*(p2-arr[1][i]));
                temp=sqrt(temp);
                double w1=arr[0][1]+temp;
                double w2=arr[0][1]-temp;
                if(abs(w1-p1)>abs(w2-p1))
                	w1=w2;

                area+= (x2-x1)*(y2-y1)+ segment_area(arr[0][i],arr[1][i],p1,q1,w1,p2)-triangle_area(p1,p2,p1,q1,w1,p2);
             }

             if(count ==2)
             {
                 if(flag1 and flag4)
                 {
                 	double p1=y1;
                 	double p2=y4;

                double temp=(arr[2][i]*arr[2][i]-(p1-arr[1][i])*(p1-arr[1][i]));
                temp=sqrt(temp);
                double w1=arr[0][1]+temp;
                double w2=arr[0][1]-temp;
                if(abs(w1-x1)>abs(w2-x1))
                	w1=w2;

                temp=(arr[2][i]*arr[2][i]-(p2-arr[1][i])*(p2-arr[1][i]));
                temp=sqrt(temp);
                double q1=arr[0][1]+temp;
                double q2=arr[0][1]-temp;
                if(abs(q1-x4)>abs(q2-x4))
                	q1=q2;

                

                 }

             }

        }


    }
	
}