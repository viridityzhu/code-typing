#include<stdio.h>  
int main()  
{  
    int y,d,day,w,flag=0;  
    int calDays(int y,int m,int d);  
    int calWeekday(int d);  
    scanf("%d",&y);  
    for(d=1;d<32;d++)  
    {  
        day=calDays(y,5,d);  
        w=calWeekday(day);  
        if(w==0) flag+=1;  
        if(2==flag)  
        {  
            printf("%d\n",d);  
            break;  
        }  
    }        
    return 0;  
}  
int calDays(int y,int m,int d)  
{  
    int days=0;  
    for(int i=1900;i<y;i++)  
        days+=((!(i%4)&&i%100)||!(i%400))?366:365;  
    for(int i=1;i<m;i++)  
        switch(i)  
        {  
            case 1:  
            case 3:  
            case 5:  
            case 7:  
            case 8:  
            case 10:  
            case 12: days+=31;break;  
            case 4:case 6:case 9:case 11:days+=30;break;  
            case 2:  
                days+=((!(y%4)&&y%100)||!(y%400))?29:28;break;  
        }  
    days+=d;  
    return days;  
}  
int calWeekday(int d)  
{  
    int weekday;  
    weekday=d%7;  
    return weekday;  
}  