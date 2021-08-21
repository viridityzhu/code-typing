class StaticTest{

  static{

    System.out.print("a ");

  }

  {

    System.out.print("b ");

  }

  

  public static void main(String[] args) {

    StaticTest st2 = new ChildTest();  //main1

    System.out.print(" # ");         //main2

    StaticTest st = new StaticTest();  //main3

  }

}

 

class ChildTest extends StaticTest{

  static{

    System.out.print("c ");

  }

}