public class KY4_3 {
protected String xm; //姓名
protected int xh; //学号

//该方法为姓名和学号赋初始值
void setData(String m,int h) { 
xm = m;
xh = h;
}
//输出学生的姓名和学号
public void print(){
System.out.println(xm+","+xh);
}
}