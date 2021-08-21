import java.io.*;
class KY5_3 {
public static void main(String args[]) throws IOException {
char ch;
System.out.println("抽奖游戏，祝您好运!");
System.out.println("按 1、2、3 数字键后回车，可得大奖!");
System.out.println("按空格键后回车，可退出本游戏.");
while((ch=(char)System.in.read())!=' '){
System.in.skip(2); // 跳过回车键
switch (ch) {
case '1':
System.out.println("恭喜您得大奖，一辆汽车!");
break;
case '2':
System.out.println("不错呀，您得到一台笔记本电脑!");
break;
case '3':
System.out.println("没有白来，您得到一台冰箱!");
break;
default:
System.out.println("对不起，没有奖品给您!欢迎下次光临。");
}
}
}
}