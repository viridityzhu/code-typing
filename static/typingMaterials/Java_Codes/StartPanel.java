package pinball.view;

import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.ImageObserver;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;


//创建初始界面
	public class StartPanel extends JPanel  implements ImageObserver{	
	private static final long serialVersionUID = 1L;
	public StartPanel(JFrame f,ChooseLevelPanel chooseLevelPanel,JPanel gamePanel) {
		JButton j1 = new JButton("选择关卡");
		j1.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入选关Panel
				setVisible(false);	
				chooseLevelPanel.setVisible(true);;
				f.add(chooseLevelPanel);
				f.pack();
				}
			}
		);	
		JButton j2 = new JButton("开始游戏");
		j2.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				setVisible(false);
				
				f.add(gamePanel);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}
			}
		);	
		JButton j3 = new JButton("退出游戏");
		j3.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
					System.exit(0);
				}
			}
		);	
		JButton j4 = new JButton("关于我们");
		j4.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				JOptionPane.showMessageDialog(new JFrame().getContentPane(),
						"小组成员朱珈印、吴奕萱、褚星原、李佳弥、朱睿琦、熊德惠为您倾力奉献此游戏！！！\n项目地址：https://github.com/viridityzhu/cxy-drinking-tea/", "关于我们", JOptionPane.INFORMATION_MESSAGE); 
				}
			}
		);	
		JButton j5 = new JButton("游戏说明");
		j5.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				JOptionPane.showMessageDialog(new JFrame().getContentPane(),
						"游戏开始时，移动鼠标以确定出射位置，按下鼠标左键，小球出射。\n游戏中，按下键盘←→方向键，移动球拍。\n游戏共分为6个关卡，主题各异，快来体验吧！\n(a little secret: 过不了关？游戏中按下“q”键生命值+100！嘘…)", "游戏说明", JOptionPane.INFORMATION_MESSAGE); 
				}
			}
		);	
		this.setLayout(null);
		j2.setBounds(340, 300, 120, 60);
		j1.setBounds(340, 370, 120, 60);
		j4.setBounds(340, 440, 120, 60);
		j3.setBounds(340, 510, 120, 60);
		j5.setBounds(660, 20, 120, 60);
		this.add(j1);
		this.add(j2);
		this.add(j3);
		this.add(j4);
		this.add(j5);
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		ImageIcon imageIcon = new ImageIcon(getClass().getResource("../../pinball_images/start.jpeg"));
		g.drawImage(imageIcon.getImage(),0,0, 800,600, this);	
	}
}