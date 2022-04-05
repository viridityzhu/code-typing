class IntSort {
public String sort (int a, int b) {
if (a>b)
return a+" "+b;
else
return b+" "+a;
}
public String sort (int a, int b, int c) {
int swap;
if (a<b) {
swap=a;
a=b;
b=swap;
}
if (a<c) {
swap=a;
a=c;
c=swap;
}
if (b<c) {
swap=b;
b=c;
c=swap;
}
return a+" "+b+" "+c;
}
}

public class KY5_1 {
public static void main(String args[]) {
int a=30, b=12, c=40;
IntSort s = new IntSort();
System.out.println("两个数的排序结果："+s.sort(a,b));
System.out.println("三个数的排序结果："+s.sort(a,b,c));
}
}