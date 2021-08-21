public class outPractice
{
	public static void main(String[] args)
	{
		outPractice a=new outPractice();
		int n=5;
		int m=a.printLing(n);
		System.out.println(m);
	}
	public int printLing(int n)
	{
		int k=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
				System.out.printf("%02d",k++);
			System.out.println();
		}
		return k-1;
	}
}