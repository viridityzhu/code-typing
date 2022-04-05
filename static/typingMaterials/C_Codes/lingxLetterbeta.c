#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {  
      
	int i,j,n,m,p,q;char c;
	scanf("%d %c",&n,&c);
	m=c;
	
	for(i=1;i<=n;i++){
		for(j=1;j<2*n;j++){
			if(j==n-i+1){
				printf("%c",c);
			}
			else if(j==n+i-1){
				printf("%c",(2*m+4*(n-1)-c-65)%26+65);//原式一旦超过Z，局面将无法估计，所以用了一个-65%26+65，让它在A-Z之间来回跑
			}
			else{
				printf(" ");
			}
		}
		c=='Z'?c='A':c++; //原c++的话，Z之后就变成奇奇怪怪的东西的，但题目里要求Z之后变回A，所以改成了这个，如果c是Z，就变回A，不然就c++
		printf("\n");
	}
	for(p=1;p<n;p++){
		for(q=1;q<2*n;q++){
			if(q==p+1){ //原p-n+1大部分时候都是负数啊，显然是不对的，改成了p+1
				printf("%c",c);
			}
			else if(q==2*n-p-1){ //原3*n-p-1改成了2*n-p-1
				printf("%c",(2*m+4*(n-1)-c-65)%26+65);
			}
			else{
				printf(" ");
			}
		}
		c=='Z'?c='A':c++; //同上
		printf("\n");
	}
	return 0;  
}  
