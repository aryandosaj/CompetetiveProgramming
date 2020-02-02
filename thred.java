import java.awt.*;
class thred extends Thread {
    A ob;
    String s;

    thred(A ob, String s) {
        this.ob = ob;
        this.s = s;
    }

    public void run() {
        {
            ob.display(s);
            
        }
        ob.display1(s);

    }

    // public void run(int i)
    // {
    // System.out.println("Argumented run");
    // }
    public static void main(String[] args) {
        A ob = new A();
        thred t1 = new thred(ob, "William");
        thred t2 = new thred(ob, "Shakespeare");
        

        t1.start();
        t2.start();
        // t.run(10);
    }
}

class A {
    void display(String s) {
        System.out.println(Thread.currentThread());
        {
            for (int i = 0; i < 5; i++) {

                System.out.println("hai" + s);
                // try {
                //     Thread.sleep(500);
                // } catch (Exception e) {
                // }

            }
        }

    }

    void display1(String s) {
        for (int i = 0; i < 5; i++) {
            System.out.println("hello" + s);
            // try {
            //     Thread.sleep(500);

            // } catch (Exception e) {
            // }

        }
    }
}