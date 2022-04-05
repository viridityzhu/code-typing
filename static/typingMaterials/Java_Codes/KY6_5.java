public class KY6_5{
	public static void main(String[]args){
		String s=new String("This is andemo of the String method.");
		System.out.println("Length:"+s.length());
		System.out.println("SubString:"+s.substring(11,15)); 
		StringBuffer sf=new StringBuffer("Hello World!");
		sf.append(" Hello Java!");
		sf.insert(12," And");
		System.out.println(sf);
		System.out.println(sf.charAt(0));
		sf.setCharAt(0,'h');
		System.out.println(sf.charAt(0));
		System.out.println(sf);
	}
}