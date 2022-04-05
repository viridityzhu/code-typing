#include<stdio.h>
#include<math.h>
double Sqrt(double x,double p,double e);
int main(){
    double x;double e;int em;
    scanf("%lf",&x);
    while(getchar()!='e') ;
    scanf("%d",&em);
    e=pow(10,em);
    //printf("%.15lf\n",e );
    printf("%.8lf\n",Sqrt(x,x,e) );
 return 0;
}
double Sqrt(double x,double p,double e)
{
    if(fabs(p*p-x)<e) return p;
    else return Sqrt(x,0.5*(p+x/p),e);
}