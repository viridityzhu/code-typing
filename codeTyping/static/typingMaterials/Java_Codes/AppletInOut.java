import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class AppletInOut extends Applet{
	TextField in =new TextField(10);
	Button btn=new Button("求平方");
	Label out=new Label("用于显示结果的标签");
	public void init(){
		setLayout(new FlowLayout());
		add(in);
		add(btn);
		add(out);
		btn.addActionListener(new BtnActionAdapter());
	}
	class BtnActionAdapter implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String s=in.getText();
			double d =Double.parseDouble(s);
			double sq=d*d;
			out.setText(d+"的平方是："+sq);
		}
	}
}