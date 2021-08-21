import java.awt.*;
import java.awt.event.*;

public class GPACalc{
	public static void main(String[]args){
		new AppFrame();
	}
}

class AppFrame extends Frame{
	TextField in=new TextField(10);
	Button btn=new Button("确认");
	Label out=new Label("你有多少门课程？");
	Label pr=new Label("...");
	int status=0;
	int courses;
	public AppFrame(){
		setLayout(new FlowLayout());
		add(out);
		add(in);
		add(btn);
		add(pr);
		btn.addActionListener(new BtnActionAdapter());
		setSize(400,100);
		show();
	}
	class BtnActionAdapter implements ActionListener{
		public void actionPerformed(ActionEvent e){
			switch(status){
				case 0:
					String s=in.getText();
					courses=Integer.parseInt(s);
					out.setText("请输入课程"+(status+1)+"的得分：");
					status++;
					break;
				case 1:
			}

			
		}
	}


}