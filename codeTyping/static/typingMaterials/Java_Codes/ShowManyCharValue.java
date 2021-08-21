//3-12
import java.io.*;
class ShowManyCharValue{
	public static void main(String[]args){
		try{
			char c;
			do{
				System.out.println("输入字符并按回车，按#结束");
				c=(char)System.in.read();
				System.in.skip(2);
				System.out.println(c+"的Ascii值为："+(int)c);
			}
			while(c!='#');
		}catch(Exception e){}
	}
}