
#include<stdio.h>
#include<string.h> 

int main(void)

{
    char one[11]="0123456789",
        two[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        three[27]="abcdefghijklmnopqrstuvwxyz";

int n,i,j,x,m,b[4];

char a[100];

scanf("%d",&n);

for (i=1;i<=n;i++)

{

gets(a);

if (i==1) gets(a);

x=strlen(a);

if (x<6) {printf("Not Safe\n");continue;}

b[0]=0;b[1]=0;b[2]=0;b[3]=0;

for (j=0;j<=x-1;j++)

{

if (48<=a[j]&&a[j]<=57) b[0]=1;

else

if (65<=a[j]&&a[j]<=91) {b[1]=1;printf("daxie:%d\n",a[j] );}

else

if (97<=a[j]&&a[j]<=123) b[2]=1;

else b[3]=1;

if (a[0]+a[1]+a[2]+a[3]==4) break;

}

m=b[0]+b[1]+b[2]+b[3];

switch (m)

{

case 1:printf("Not Safe\n");break;



case 2:printf("Medium Safe\n");break;

case 3:printf("Safe\n");break;

case 4:printf("Safe\n");

}
int flag,types[4]={0},type=0;
            for(int k=0;a[k];k++)
            {
                flag=4;int ifnew=1;
                for(int j=0;j<10&&flag==4;j++)
                    if(one[j]==a[k]) 
                        flag=1;
                for(int j=0;j<26&&flag==4;j++)
                    if(two[j]==a[k]) 
                        flag=2;
                for(int j=0;j<26&&flag==4;j++)
                    if(three[j]==a[k]) 
                        flag=3;
                for(int j=0;j<type;j++)
                    if(flag==types[j]) ifnew=0;
                if(ifnew==1)
                    types[type++]=flag;
            }
            switch(type)
            {
                case 1: printf("Not Safe\n"); break;
                case 2:printf("Medium Safe\n"); break;
                case 3: 
                case 4:printf("Safe\n");break;
            }

}

return 0;

}


/*


#include<stdio.h>
#include<string.h>
int main()
{
    char passwords[100][100];int pwNum;
    
    char one[11]="0123456789",
        two[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ[",
        three[27]="abcdefghijklmnopqrstuvwxyz{";
    scanf("%d",&pwNum);
    for(int i=0;i<pwNum;i++)
    {
        scanf("%s",passwords[i]);
        if(strlen(passwords[i])<6)
        {
            printf("Not Safe\n" );
        }
        else
        {
            int flag,types[4]={0},type=0;
            for(int k=0;passwords[i][k];k++)
            {
                flag=4;int ifnew=1;
                for(int j=0;j<10&&flag==4;j++)
                    if(one[j]==passwords[i][k]) 
                        flag=1;
                for(int j=0;j<26&&flag==4;j++)
                    if(two[j]==passwords[i][k]) 
                        flag=2;
                for(int j=0;j<26&&flag==4;j++)
                    if(three[j]==passwords[i][k]) 
                        flag=3;
                for(int j=0;j<type;j++)
                    if(flag==types[j]) ifnew=0;
                if(ifnew==1)
                    types[type++]=flag;
            }
            switch(type)
            {
                case 1: printf("Not Safe\n"); break;
                case 2:printf("Medium Safe\n"); break;
                case 3: 
                case 4:printf("Safe\n");break;
            }
        }
    }
    return 0;
}




//*/