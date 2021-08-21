//3-17
class Rnd_36_7{
	public static void main(String[]args){
		int a[]=new int[7];
		for(int i=0;i<a.length;i++){
			one_num:
			while(true){
				a[i]=(int)(Math.random()*36)+1;
				for(int j=0;j<i;j++){
					if(a[i]==a[j]) continue one_num;
				}
				break;
			}
		}
		for(int i=0;i<a.length;i++) System.out.print(" "+a[i]);
		System.out.println();
	}
}