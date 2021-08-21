package pinball.listener;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.Timer;

import pinball.commons.*;

public class MoveListener extends KeyAdapter {
	public MoveListener(Racket racket, GameConfiguration config,Timer timer) {
		super();
		this.racket = racket;
		this.config = config;
		this.timer=timer;
	}
	private Racket racket;
	private GameConfiguration config;
	private Timer timer;
	public void keyPressed(KeyEvent ke){
		if(config.isStart()) 
		{
			// 按下向左、向右键时，球拍水平坐标分别减少、增加
			if (ke.getKeyCode() == KeyEvent.VK_LEFT){
				if (racket.getRacketX() > 0)
				racket.setRacketX(racket.getRacketX()-50);
			}
			if (ke.getKeyCode() == KeyEvent.VK_RIGHT){
				if (racket.getRacketX() < config.getTABLE_WIDTH() - racket.getRACKET_WIDTH())
					racket.setRacketX(racket.getRacketX()+50);
			}
			if (ke.getKeyCode() == KeyEvent.VK_SPACE){
				if(!config.isStop()) {
					config.setStop(true);
					timer.stop();
				}
				else {
					config.setStop(false);
					timer.restart();
				}
				
			}
		}
	}
}
