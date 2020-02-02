import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        for(int i=0;i<100001;i++){
            System.out.println(random()+" "+random()+" "+random());
        }
        
    }
    static long random(){
        return (long)(Math.random()*1000000000)+1;
    }
}