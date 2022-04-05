#include<stdio.h>


int main()
{
	//2018 9 26 is Wednesday.
	int monthDate[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,date,days=0;
	printf("give me the date (like 2019 5 18):\n");
	scanf("%d%d%d",&year,&month,&date);
	for(int i=2018;i<year;i++)
	{
		if ((i%4==0 && i%100!=0 )|| i%400==0)
		{
			days+=366;
		}
		else
			days+=365;
	}
	if((year%4==0 && year%10!= 0 )|| year%400==0)
		monthDate[1]=29;

	for(int i=0;i<month-1;i++)
		days+=monthDate[i];
	days+=date;
	for(int i=0;i<9;i++)
		days-=monthDate[i];
	days-=26;
	printf("%d\n",days%7+3 );


	return 0;
}