//p24 2-7
import java.awt.*;
import java.awt.event.*;
public class AppGraphInOut{
	public static void main(String[]args){
		new AppFrame();
	}
}
class AppFrame extends Frame{
	TextField in=new TextField(10);
	Button btn=new Button("求平方");
	Label out=new Label("用于显示结果的标签");
	public AppFrame(){
		setLayout(new FlowLayout());
		add(in);
		add(btn);
		add(out);
		btn.addActionListener(new BtnActionAdapter());
		setSize(400,100);
		show();
	}
	class BtnActionAdapter implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String s=in.getText();
			double d=Double.parseDouble(s);
			double sq=d*d;
			out.setText(d+"的平方是："+sq);
		}
	}
}