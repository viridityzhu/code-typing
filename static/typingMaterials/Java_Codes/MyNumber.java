class MyNumber {

   private int num = 5;

   public MyNumber(int num) {

        this.num = num;

   }

   public int getNum() {

       return num;

   }

   public void setNum(int num) {

       this.num = num;

   }


public static void main(String[]arguments){

   MyNumber obj1 = new MyNumber();

   MyNumber obj2 = new MyNumber(10);

   obj2 = obj1;

   obj2.setNum(20);

   System.out.println(obj1.getNum() + "," + obj2.getNum());}

   }