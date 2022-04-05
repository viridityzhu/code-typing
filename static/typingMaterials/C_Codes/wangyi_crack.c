#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp1,*fp2;
	if((fp1=fopen( "/Users/jiayinzhu/Downloads/w.uc!","rb+"))==NULL)
	{
		printf("Can\'t open file!\n");
		exit(0);
	}
	if((fp2=fopen( "/Users/jiayinzhu/Downloads/w.mp3","wb+"))==NULL)
	{
		printf("Can\'t write file!\n");
		exit(0);
	}
	int i=0;
	char ch;
	char buf[1024];
	int rc;
    while((rc = fread(buf,sizeof(unsigned char), 1024,fp1)) != 0 )
    {
        int k=0;
        for(k=0;k<rc;k++)
                   buf[k] ^= 0xa3 ;       
		printf("%d\n",i++);
        
        fwrite( buf, sizeof( unsigned char ), rc, fp2 );

    }  
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
