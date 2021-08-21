import Mypackage.KY6_1; //引用 Mypackage 包中的KY6_1 类
public class KY6_2 {
private String name;
private KY6_1 birth;
public static void main(String args[]) {
KY6_2 a = new KY6_2("张驰",1990,1,11);
a.output();
}
//初始化变量与对象
public KY6_2 (String n1, int y, int m, int d)  { 
name = n1;
birth = new KY6_1(y, m, d);
}
public int age() { //计算年龄
return birth.year() - KY6_1.thisyear(); 
//返回当前年与出生年的差即年龄
}
public void output(){
System.out.println("姓名 : "+name);
System.out.println("出生日期: "+birth.toString());
System.out.println("今年年龄 : "+age());
}
}