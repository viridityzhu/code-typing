package pinball.view;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import pinball.commons.Ball;
import pinball.commons.GameConfiguration;
import pinball.commons.ImageUtil;
import pinball.commons.MapGenerator;

public class ChooseLevelPanel extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private StartPanel startPanel;
	public ChooseLevelPanel(GameConfiguration config,JFrame f,JPanel gamePanel,MapGenerator map,ImageUtil imageUtil,Ball ball) {
		initComponents(config,f,gamePanel,map,imageUtil,ball);
		setPreferredSize(new Dimension(config.getTABLE_WIDTH() , config.getTABLE_HEIGHT()));   
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		ImageIcon imageIcon = new ImageIcon(getClass().getResource("../../pinball_images/choose.jpeg"));
		g.drawImage(imageIcon.getImage(),0,0, 800,600, this);	
	}

	private void initComponents(GameConfiguration config,JFrame f,JPanel gamePanel,MapGenerator map,ImageUtil imageUtil,Ball ball) {
		JButton j1 = new JButton("第一关");
		JButton j2 = new JButton("第二关");
		JButton j3 = new JButton("第三关");
		JButton j4 = new JButton("第四关");
		JButton j5 = new JButton("第五关");
		JButton j6 = new JButton("第六关");
		JButton j7 = new JButton("返回");
		
		this.add(j1);
		this.add(j2);
		this.add(j3);
		this.add(j4);
		this.add(j5);
		this.add(j6);
		this.add(j7);

		
		j1.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面
				setVisible(false);	
				gamePanel.setVisible(true);
				f.add(gamePanel);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}
			
			}
		);		
		j2.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面,将本界面画板和按钮隐藏，进入新面板							
				setVisible(false);			
				f.add(gamePanel);
				gamePanel.setVisible(true);
				config.setLevel(1);	
				map.nextLevel(config, imageUtil, ball);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}

			
			}
		);	
		j3.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面,将本界面画板和按钮隐藏，进入新面板							
				setVisible(false);			
				f.add(gamePanel);
				gamePanel.setVisible(true);
				config.setLevel(2);	
				map.nextLevel(config, imageUtil, ball);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}

			
			}
		);
		j4.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面,将本界面画板和按钮隐藏，进入新面板								
				setVisible(false);			
				f.add(gamePanel);
				gamePanel.setVisible(true);
				config.setLevel(3);	
				map.nextLevel(config, imageUtil, ball);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}

			
			}
		);	
		j5.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面,将本界面画板和按钮隐藏，进入新面板							
				setVisible(false);
				gamePanel.setVisible(true);
				f.add(gamePanel);
				config.setLevel(4);	
				map.nextLevel(config, imageUtil, ball);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}

			
			}
		);	
		j6.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面,将本界面画板和按钮隐藏，进入新面板								
				setVisible(false);			
				f.add(gamePanel);
				gamePanel.setVisible(true);
				config.setLevel(5);	
				map.nextLevel(config, imageUtil, ball);
				f.pack();
				gamePanel.setFocusable(true);
				gamePanel.requestFocus();
				}
			}
		);	
		j7.addActionListener(new ActionListener() {			
			public void actionPerformed(ActionEvent e) {			
				//进入关卡界面,将本界面画板和按钮隐藏，进入新面板								
				setVisible(false);			
				startPanel.setVisible(true);
				f.add(startPanel);
				f.pack();
				}
			}
		);			
		this.setLayout(null);
		j7.setBounds(350, 540, 100, 40);
		j1.setBounds(80, 350, 160, 80);	
		j2.setBounds(320,350, 160, 80);
		j3.setBounds(560, 350, 160, 80);
		j4.setBounds(80, 450, 160, 80);
		j5.setBounds(320, 450, 160, 80);
		j6.setBounds(560, 450, 160, 80);
				
		//界面设置			
		this.setSize(800, 600);		
		this.setVisible(true);	

	}
	public StartPanel getStartPanel() {
		return startPanel;
	}
	public void setStartPanel(StartPanel startPanel) {
		this.startPanel = startPanel;
	}
	
}
