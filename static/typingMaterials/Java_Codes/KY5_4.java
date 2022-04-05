public class KY5_4 {
public static void main(String args[]) {
int i, j, n=9;
System.out.print("*|");
for (i=1; i<=n; i++) {
System.out.print(" "+i);
} //第一个for循环
System.out.print("\n----------|");
for (i=1; i<=n; i++) {
System.out.print("-----");
}//第二个for循环
System.out.println();
for (i=1; i<=n; i++) { //第三个for循环
System.out.print(" "+i+" |");
for (j=1; j<=i; j++) {
System.out.print(" "+i*j);
} //第四个for循环
System.out.println();
}
}
}