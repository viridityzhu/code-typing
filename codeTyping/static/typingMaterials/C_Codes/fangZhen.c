#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float x=0,y=0;
    int i=0,m=0,n=0;
    srand(time(NULL));
    for(i=0;i<100;i++){
        x=(rand()%100000)*0.00001*3.14;
        y=(rand()%100000)*0.00001;
        if(y<=sin(x)) m=m+1;
        //printf("%f %f %d\n",x,y,m);
    }
  printf("%lf\n",(float)m/100*3.14);
  
  return 0;
}

/*#include<stdio.h>
#include<math.h>
#include<time.h>
#define PI 3.14159
int main()
{
    int total=30,count=0;
    double x,y,z;
    srand((unsigned)time(NULL));
    for(int i=0;i<total;i++){
        x=(rand()%100000)*0.00001*PI;
        y=(rand()%100000)*0.00001;
        z=rand()%100000*0.00001;
        if(sin(x)>=y) count++;
        printf("%lf\n",z);
    }
    printf("%lf\n",(double)count/(double)total*PI);

    return 0;
}*/