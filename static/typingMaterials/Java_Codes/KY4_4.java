class KY4_4 extends KY4_3{
	String xy;
	String xi;
	public void print(){
		System.out.println(xm+","+xh+","+xy+","+xi);
	}
	void setData(String m,int h,String y,String x) { 
		xm = m;
		xh = h;
		xy=y;
		xi=x;
	}
	public static void main(String[]args){
		KY4_3 f=new KY4_3();
		f.setData("帅零",12321);
		f.print();
		KY4_4 s=new KY4_4();
		s.setData("郭娜",12345,"经济管理学院","信息管理系");
		s.print();
	}
}