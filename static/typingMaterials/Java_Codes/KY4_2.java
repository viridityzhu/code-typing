class KY4_2{
	int square(int x, int y){
		return x*x+y*y;
	}
	public static void main(String[]args){
		int a=2,b=3;
		KY4_2 k=new KY4_2();
		int s=k.square(2,3);
		System.out.println(s);
	}
}