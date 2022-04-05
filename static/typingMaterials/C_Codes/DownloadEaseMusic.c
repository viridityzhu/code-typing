//为什么必须绝对路径？怎样获取整个文件夹的文件名目录？
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp,*out;char a[100000]={0};
	if((fp=fopen("//Users//jiayinzhu//Documents//C_codes_of_mine//mmm.uc!","rb+"))==NULL)
	{
		printf("Open file error.\n");
		exit(0);
	}
	if((out=fopen("//Users//jiayinzhu//Documents//C_codes_of_mine//mmm.mp3","wb"))==NULL)
	{
		printf("Create file error.\n");
		exit(0);
	}
	char ch;int l,i=0;char buffer[1024];
	while((l=fread(buffer,sizeof(unsigned char),1024,fp))!=0)
	{
		int k;
		for(k=0;k<l;k++)
			buffer[k]^=0xa3;
		//printf("l:%d %d\n",l,i++ );
		fwrite(buffer,sizeof(unsigned char),l,out);
	}
	printf("All is ok.\n");
	fclose(fp);
	fclose(out);
}