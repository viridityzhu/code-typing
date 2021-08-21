class StaticDemo {
static int x;
int y;
public static int getX(){
return x;
}
public static void setX(int newX) {
x = newX;
}
public int getY() {
return y;
}
public void setY(int newY) {
y = newY;
}
}

public class KY4_1 {
public static void main(String[] args) {
System.out.println("类变量x="+StaticDemo.getX());
// System.out.println("对象变量y="+StaticDemo.getY());

StaticDemo a= new StaticDemo();
StaticDemo b= new StaticDemo();
a.setX(1);
a.setY(2);
b.setX(3);
b.setY(4);

System.out.println("类变量a.x="+a.getX());
System.out.println("对象变量a.y="+a.getY());
System.out.println("类变量b.x="+b.getX());
System.out.println("对象变量b.y="+b.getY());
}
}