#include <stdio.h>
int main(){
	int i,k,j,flag=1;
	int ch,m;
	double  money1=0,money2=0;
	do
	{
		printf("----- 营业时间 -----\n");
		printf("  1. 早餐\n");
		printf("  2. 中餐\n");
		printf("  3. 晚餐\n");
		printf("  4. 夜宵\n");
		printf("  0. 退出\n");
		printf("请输入选项：");	
		if(scanf("%d",&i)!=1|| i<0 || i>4) continue;
		//do
		//{
		switch (i)
		{
			case 1:
			{
				flag=1;//flag这个变量会被重复使用，可能之前被用过了，所以在这初始化一下
				//while ((scanf("%d",&j)==1) && j>=0 && j<5)
				//这里会先输入数字，再输出早餐菜单，所以scanf要写在早餐菜单之后才行
				//因此改用do-while结构
				do
				{
					printf("----- 早餐菜单 -----\n");
			        printf(" 1. 油条，0.32\n");
			        printf(" 2. 豆浆，0.70\n");
			        printf(" 3. 鸡蛋，0.50\n");
			        printf(" 4. 豆腐脑，1.50\n");
			        printf(" 5. 小包子，0.50\n");
			        printf(" 0. 选择结束\n");
			        printf("请输入选项：");    
			        scanf("%d",&j);
		        	switch (j)
			        {
		        		case 1:
		        		{
		        			printf("输入油条数量:"); 
		        			//说起来很狗，因为在scanf那儿输入j的时候，咱们不是会输入一个回车来让程序继续执行嘛；
		        			//那个回车是没有被用到的，还存在那儿；
		        			//所以这儿的ch=getchar就直接把那个回车，也就是'\n'，赋值给ch了
		        			//其实这里我不明白为什么要用getchar啊……scanf不好吗……
		        			//如果继续用getchar的话，解决办法就是，在ch=getchar（）之前再加一个getchar（），把那个回车吞掉
		        			getchar();
		        			ch=getchar();
		        			money1+=0.32*(ch-48);
							break;
						}	
						case 2:
						{
							printf("输入豆浆数量:");getchar();ch=getchar();money1+=0.70*(ch-48);
							break;
						} 
						case 3:
						{
							printf("输入鸡蛋数量：");getchar();ch=getchar();money1+=0.50*(ch-48);
							break;
						} 
						case 4:
						{
							printf("输入豆腐脑数量：");getchar();ch=getchar();money1+=1.50*(ch-48);
							break;
						}
						case 5:
						{
							printf("输入小包子数量：");getchar();ch=getchar();money1+=0.50*(ch-48);
							break;
						}
						//如果输入0则显示早餐合计并退出循环
						case 0:
						{
							printf("早餐合计：%.2f\n",money1);
							flag=0;
						}
					}
				}while(flag);
				//这里缺少break哦
				break;
			}
			case  4://夜宵应该是case 4嘛
			{
				//这里所做的更改跟case 1一样
				flag=1;
				do
				{
					printf("----- 夜宵菜单 -----\n");
				    printf(" 1. 馄饨，2.50\n");
				    printf(" 2. 馅饼，1.00\n");
				    printf(" 3. 茶鸡蛋，0.60\n");
				    printf(" 4. 鸡蛋饼，3.50\n");
				    printf(" 0. 选择结束\n");
				    printf("请输入选项：");
				    scanf("%d",&m);
				    switch (m)
				    {
		        		case 1:
		        		{
		        			printf("输入馄饨数量:");getchar();ch=getchar();money2+=2.50*(ch-48);
		        			//馄饨两个字打错了啊喂
							break;
						}
						case 2:
						{
							printf("输入馅饼数量:");getchar();ch=getchar();money2+=1.00*(ch-48);
							break;
						} 
						case 3:
						{
							printf("输入茶鸡蛋数量：");getchar();ch=getchar();money2+=0.06*(ch-48);
							break;
						} 
						case 4:
						{
							printf("输入鸡蛋饼数量：");getchar();ch=getchar();money2+=3.50*(ch-48);
							break;
						}
						case 0:
						{
							printf("晚餐合计：%.2f\n",money2);
							flag=0;
							break;
						}
					}
				}while(flag);
				break;
			}
			case 0: 
			{
				printf("买了这么多美食才花了%.2f。",money1+money2);
				return 0;
			}//如果输入的是0，就退出程序
		}
		//}while((k=getchar())!=48 ); 
		//我不懂这里do-while是什么意思……
		//它会不停不停地进行switch啊……
	}while(true);//这里用了个while true，看起来是个死循环，实际上退出程序的关键“return 0”被放在了循环里面的一个条件分支中，所以没问题
}