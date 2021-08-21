#include<stdio.h>
//mine sweeper
int calMines(char map[][101],int i,int j,int m,int n);
int SweepMine(char space);
int main()
{
    int m[20],n[20],t;
    char map[20][101][101];
    for(t=0;;t++)
    {
        scanf("%d%d",&m[t],&n[t]);
        if(!m[t]&&!n[t])
            break;
        getchar();
        for(int i=1;i<=m[t];i++)
        {
            for(int j=1;j<=n[t];j++)
                map[t][i][j]=getchar();
            getchar();
        }
    }    
    //-----------input over----------------
    for(int tt=0;tt<t;tt++)
    {
        for(int i=1;i<=m[tt];i++)
            for(int j=1;j<=n[tt];j++)
                if(map[tt][i][j]!='*')
                    map[tt][i][j]=(char)(calMines(map[tt],i,j,m[tt],n[tt])+48);
    }
    //-----------sweep mines over----------
    for(int tt=0;tt<t;tt++)
    {
        if(tt>0) printf("\n");
        printf("Field #%d:\n",tt+1 );
        for(int i=1;i<=m[tt];i++)
        {
            for(int j=1;j<=n[tt];j++)
                printf("%c",map[tt][i][j]);
            printf("\n");
        }
    }
    return 0;
}


int calMines(char map[][101],int i,int j,int m,int n)
{
    int mines=0;
    if(j>1) 
    {
        mines+=SweepMine(map[i][j-1]);
        if(i>1) mines+=SweepMine(map[i-1][j-1]);
        if(i<m) mines+=SweepMine(map[i+1][j-1]);
    }
    if(i>1) mines+=SweepMine(map[i-1][j]);
    if(i<m) mines+=SweepMine(map[i+1][j]);
    if(j<n)
    { 
        mines+=SweepMine(map[i][j+1]);
        if(i<m) mines+=SweepMine(map[i+1][j+1]);
        if(i>1) mines+=SweepMine(map[i-1][j+1]);
    }
    return mines;
}


int SweepMine(char space)
{
    if(space=='*') return 1;
    else return 0;
}
