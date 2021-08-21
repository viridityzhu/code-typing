package stop;

public class MyThread extends Thread {

    private final Object lock = new Object();

    private boolean pause = false;

    // ���ø÷���ʵ���̵߳���ͣ
    void pauseThread(){
        pause = true;
    }


    //    ���ø÷���ʵ�ָֻ��̵߳�����
    void resumeThread(){
        pause =false;
        synchronized (lock){
            lock.notify();
        }
    }

    /* �������ֻ����run ������ʵ�֣���Ȼ���������̣߳�����ҳ������Ӧ*/
    void onPause() {
        synchronized (lock) {
            try {
                lock.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    @Override
    public void run() {
        int index = 0;
        int flag=1;
        while(flag==1){
            while (pause){             //���ƽ�����ͣ�Ŀ���
                onPause();
            }
            try {                       //try���ǵ�������
                
            	
            	System.out.println(index);
                ++index;
                
                if(index>300000) {      //�˳�ѭ�������̽���������
                	flag=0;
                }
                
            }catch (Exception e){
                e.printStackTrace();
                break;
            }
        }
    }
}
