//3-9
public class Sum100{
	public static void main(String[]args){
		int sum,n;
		System.out.println("\n**** for statement ****");
		sum=0;
		for(int i=1;i<=100;i++){sum+=i;}
		System.out.println("sum is "+sum);
		System.out.println("\n**** while statement ****");
		sum=0;
		n=100;
		while(n>0){
			sum+=n;
			n--;
		}
		System.out.println("sum is "+sum);
		System.out.println("\n**** do_while statement ****");
		sum=0;
		n=0;
		do{
			sum+=n;
			n++;
		}while(n<=100);
		System.out.println("sum is "+sum);
	}
}