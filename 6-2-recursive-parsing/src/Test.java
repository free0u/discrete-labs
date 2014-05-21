import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by free0u on 4/16/14.
 */
public class Test {


    public static void main(String[] args) throws ParseException {
        List<String> tests = new ArrayList<String>();

        tests.add("var a:Integer;");
        tests.add("var a,b:Integer; c,d:Real;");
        tests.add(" var  a_int , b  :  Integer  ;   c  ,  d_real  :  Real  ;  ");
        tests.add("var cnt,sum:Integer; avg:Real;");
        tests.add("    var    cnt    ,     sum    :    Integer    ;    avg   :   Real   ;    ");
        tests.add("    var    a,b,c    ,d,e:Integer;   a:Real;   f,r     ,t,y,   y : Boolean  ;  ");

        tests.add("a,b:Integer");
        tests.add("var");
        tests.add("var a,:Integer;");
        tests.add("var a:Integer");
        tests.add("var a:Integer; b");
        tests.add("var a:Integer; b;Real;");

        Parser parser = new Parser();
        System.out.println(parser.parse(tests.get(5)));
    }
}
