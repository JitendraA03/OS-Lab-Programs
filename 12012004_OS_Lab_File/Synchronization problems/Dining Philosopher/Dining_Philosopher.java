import java.lang.*;
import java.util.*;
import java.util.concurrent.Semaphore;

class chopStick {
    public Semaphore mutex = new Semaphore(1);

    boolean isAvailable() {
        if (mutex.availablePermits() == 1) {
            return true;
        }
        return false;
    }

    void grab() {
        try {
            mutex.acquire();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void release() {
        mutex.release();
    }
}

class philospher extends Thread {
    int number;
    int status; // 1->think,2->Hungry 3->Eat
    chopStick lefStick;
    chopStick righStick;

    public philospher(chopStick left, chopStick right,int number,int status) {
        this.lefStick = left;
        this.righStick = right;
        this.number=number;
        this.status = status;
    }

    @Override
    public void run() {
        while (true) {
            if (status == 2) {
                System.out.printf("Philospher Number %d Is Hungry \n", number);
                System.out.printf("Philospher Number %d has Acquired The Left Stick\n", number);
                lefStick.grab();
                System.out.printf("Philospher Number %d Has Acquired The Right Stick\n", number);
                righStick.grab();

                System.out.printf("Philospher Number %d is Eating\n", number);
                status=3;

                eat();
                System.out.printf("Philospher Number %d has released Left Stick\n", number);
                lefStick.release();
                System.out.printf("Philospher Number %d has released Right Stick\n", number);
                righStick.release();

                status=1;
            } else if (status == 1) {
                System.out.printf("Philospher Number %d is Thinking\n", number);
            } else {
                System.out.printf("Philospher Number %d is Eating\n", number);
            }
        }
    }

    void eat(){
        try{
            Thread.sleep(100);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}

public class DinningPhilospher {
    public static void main(String[] args) {
        philospher[] ph = new philospher[5];

        chopStick[] st = new chopStick[5];
        for (int i = 0; i < st.length; i++) {
            // ph[i]=new philospher();
            st[i]=new chopStick();
        }

        for (int i = 0; i < st.length; i++) {
            ph[i]=new philospher(st[i], st[(i+1)%5],i,1);
            ph[i].start();
        }

        while (true) {
            int i;
            for (i= 0; i < st.length; i++) {
                Random rd=new Random();
                int num=rd.nextInt(3);
                ph[i].status=num+1;
            }
            for (i = 0; i < st.length; i++) {
                if(st[i].isAvailable()){
                    break;
                }
            }

            if(i==st.length){
                System.out.println("Deadlock Occured!!!");
                break;
            }
        }

        System.exit(0);
    }
}