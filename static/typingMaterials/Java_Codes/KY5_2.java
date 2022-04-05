class RunDemo {
private String userName, password;
RunDemo(String userName) {
this.userName = userName;
}
RunDemo(String userName, String password) {
this(userName);
this.password = password;
}
void check() { //检验用户名和密码
String s=null;
if (userName!=null)
s="用户名："+userName;
else
s="用户名不能为空！";
if (password!="123456")
s=s+" 口令无效！";
else
s=s+" 口令：******";
System.out.println(s);
}
}

public class KY5_2 {
public static void main(String[] args) {
RunDemo r1=new RunDemo("刘新宇");
r1.check();
RunDemo r2=new RunDemo(null, "654321");
r2.check();
RunDemo r3=new RunDemo("张驰","123456");
r3.check();
}
}