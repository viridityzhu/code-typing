#include<stdio.h>
#include<string.h>
char calLastNum(char*a);
int main()
{
    char id[10][20];int idNum;
    scanf("%d",&idNum);getchar();
    for(int i=0;i<idNum;i++)
        gets(id[i]);
    for(int i=0;i<idNum;i++)
    {
        if(strlen(id[i])==15)
        {
            //15 -> 18
            //110105 49 1231 00 2
            char newId[20];
            for(int j=0;j<6;j++)
                newId[j]=id[i][j];
            newId[6]='1';
            if(id[i][12]=='9'&&id[i][13]=='9'&&(id[i][14]=='6'||id[i][14]=='7'||id[i][14]=='8'||id[i][14]=='9'))
                newId[7]='8';
            else newId[7]='9';
            for(int j=8;j<17;j++)
                newId[j]=id[i][j-2];
            newId[17]=calLastNum(newId);
            newId[18]='\0';
            printf("%s\n",newId );
        }
        else if(strlen(id[i])==18)
        {
            //judge if valid
            if(id[i][17]==calLastNum(id[i])) printf("Valid\n");
            else printf("Invalid\n");
        }
        else printf("Invalid\n");
    }
    return 0;
}
char calLastNum(char*a)
{
    char x;
    int sum=0;//len=17
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char right[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    for(int i=0;i<17;i++)
        sum+=(int)(a[i]-48)*weight[i];
    sum%=11;
    x=right[sum];
    return x;
}
