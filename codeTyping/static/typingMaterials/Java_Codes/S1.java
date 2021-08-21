package stop;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class S1 {
	
	int a=0;
	static MyThread t=new MyThread();
	
	public static void main(String args[]) {
		Frame f= new Frame("test");
		Button bt1= new Button("ÔÝÍ£");
		Button bt2= new Button("¼ÌÐø");
		f.add(bt1);
		f.add(bt2);
		Monitor1 hb= new Monitor1();
		Monitor2 hc= new Monitor2();
		bt1.addActionListener(hb);
		bt2.addActionListener(hc);
		f.setSize(200,200);
		f.setLayout(new FlowLayout(FlowLayout.LEFT,10,20));
		f.setVisible(true);
		t.start();
		
	}
	static class Monitor1 implements ActionListener{
		 
		 public void actionPerformed(ActionEvent e) {
			 t.pauseThread();
		}
	
}	
	static class Monitor2 implements ActionListener{
		
		public void actionPerformed(ActionEvent e) {
			t.resumeThread();
		}
	 }
}
 
 





