import java.util.*;

class applet
{
    public static void main(String[] args) throws tex
    {
        HashMap <String,Boolean> hm = new HashMap<>(); 
              
        m();
    }
    static void m() throws tex
    {
        try{
            throw new tex("Kat gaya");
        }
        catch(tex e)
        {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
    }
}

class tex extends Exception
{
    tex(String s)
    {
        super(s);
    }
}