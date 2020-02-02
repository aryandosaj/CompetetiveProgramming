abstract class BreakFast
{
    abstract void checkCarb();
    
}
class Indian extends BreakFast
{
    int c;
    Indian(int c)
    {
        this.c=c;
    }
    void checkCarb() {
        if(this.c<=200)
        System.out.println("Healthy");
    }
}
class Chinese extends BreakFast
{
    int c;
    Chinese(int c)
    {
        this.c=c;
    }
    void checkCarb() {
        if(this.c<=200)
        System.out.println("Healthy");
    }
}
class Italian extends BreakFast
{
    int c;
    Italian(int c)
    {
        this.c=c;
    }
    void checkCarb() {
        if(this.c<=200)
        System.out.println("Healthy");
    }
}
class B
{
    public static void main(String[] args) {
        Indian a = new Indian(250);
        Chinese b = new Chinese(150);
        Italian c =new Italian(150);
        a.checkCarb();
        b.checkCarb();
        c.checkCarb();
    }
}