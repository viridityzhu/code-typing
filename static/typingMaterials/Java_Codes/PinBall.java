package pinball;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;

import pinball.commons.ImageUtil;

import java.awt.event.*;

import pinball.commons.*;
import pinball.listener.*;
import pinball.view.ChooseLevelPanel;
import pinball.view.StartPanel;
import pinball.view.TableArea;
public class PinBall
{
	public static void main(String[] args){
		//---------------创建游戏关键对象-----------------
		//创建一个游戏配置对象
		final GameConfiguration config = new GameConfiguration(800,600);
		//创建一个图片工具对象
		ImageUtil imageUtil = new ImageUtil();
		//创建一个球ball对象
		final Ball ball= new Ball(50,100,550);
		//创建一个砖块map对象
		final MapGenerator map=new MapGenerator(ball,imageUtil);
		//创建一个球拍racket对象
		final Racket racket = new Racket(30,200,550,ball.getBallX()+ball.getBALL_SIZE()/2-100);
		//创建一个frame对象
		JFrame f = new JFrame("褚星原喝茶");
		//创建一个画布tableArea对象
		TableArea tableArea = new TableArea(config,ball,racket,map,imageUtil);
		//创建一个计时器timer对象
		Timer timer;
		
		
		//----------------琐碎的设置---------------------
		//按下关闭按钮，退出程序
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		// 设置桌面区域的最佳大小
		tableArea.setPreferredSize(
			new Dimension(config.getTABLE_WIDTH() , config.getTABLE_HEIGHT()));
		
		
		
		JPanel gamePanel= new JPanel(); 
		ChooseLevelPanel chooseLevelPanel=new ChooseLevelPanel(config,f,gamePanel,map,imageUtil,ball);
		StartPanel startPanel = new StartPanel(f,chooseLevelPanel,gamePanel);
		chooseLevelPanel.setStartPanel(startPanel);
		// 去掉白色边框
		gamePanel.setBorder(new EmptyBorder(-5,-5,-5,-5));
		
		
		startPanel.setPreferredSize(new Dimension(config.getTABLE_WIDTH() , config.getTABLE_HEIGHT()));
		
		f.add(startPanel,BorderLayout.CENTER);
		f.pack();
		gamePanel.add(tableArea);
		
		
		//-------------------创建并添加一系列监听器对象-------------------------
		
		
		// 创建并添加小球碰撞的监听器对象
		CrashListener crashListener = new CrashListener(ball,config,racket,tableArea,map,imageUtil);
		timer = new Timer(50, crashListener);
		crashListener.setTimer(timer);
		timer.start();
		// 创建移动球拍的监听器对象
		MoveListener moveListener = new MoveListener(racket,config,timer);
		// 为窗口和tableArea分别添加移动球拍监听器
		gamePanel.addKeyListener(moveListener);
		tableArea.addKeyListener(moveListener);
		// 创建游戏开始时的监听器对象
		BeginListener beginListener = new BeginListener(config,ball,racket);
		// 添加鼠标事件监听器，按下左键，游戏开始
		tableArea.addMouseListener(beginListener);
		// 添加鼠标移动事件监听器，使杆与小球的位置跟随鼠标
		tableArea.addMouseMotionListener(beginListener);
		KeyListener k=new KeyAdapter() {
			// 一个作弊热键……
			public void keyPressed(KeyEvent ke){
				if (ke.getKeyCode() == KeyEvent.VK_Q){
					config.setLives(config.getLives()+100);
					tableArea.repaint();
				}
			}
		};
		tableArea.addKeyListener(k);
		gamePanel.addKeyListener(k);
		
		f.setVisible(true);
		}
	}
	
