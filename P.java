import java.util.*;
import java.io.*;
interface College {
    String coll = "BIT";
}

class Department implements College {
    int Dept_no;
    String Dept_name;

    Department(int dep_no, String dep_name) {
        this.Dept_name = dep_name;
        this.Dept_no = dep_no;
    }
}

class Teacher extends Department {
    // String coll;
    String name;
    String qual;

    Teacher(String name, String qual, String dep, int dep_no) {
        super(dep_no, dep);
        this.name = name;
        this.qual = qual;
    }
}

class P {
    public static void main(String[] args)throws IOException
     {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();
        String qual = br.readLine();
        String dep = br.readLine();
        int dep_no = Integer.parseInt(br.readLine());
        Teacher obj = new Teacher(name,qual,dep,dep_no);
        System.out.println(obj.coll);
        
    }
}