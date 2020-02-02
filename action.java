import java.awt.*;
import java.awt.event.*;
class action implements ActionListener
{
    action()
    {
        Frame f = new Frame();

        Button b = new Button("hey");
        b.addActionListener(this);
        f.setSize(300,300);
        f.add(b);
        f.setVisible(true);
    }
    public static void main(String[] args) {
        
        action a = new action();
    }
    public void actionPerformed(ActionEvent e)
    {
        System.out.println("wwo");
    }
}