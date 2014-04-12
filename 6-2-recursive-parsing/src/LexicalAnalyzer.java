import java.text.ParseException;

/**
 * Created by free0u on 4/4/14.
 */

public class LexicalAnalyzer {
    String s;
    int curPos;
    int curChar;
    Token curToken;
    boolean var_block_found;


    public LexicalAnalyzer(String s) {
        this.s = s;
        curPos = -1;
        System.out.println(s);
        var_block_found = false;
        nextChar();
    }

    private boolean isBlank(int c) {
        return c == ' ' || c == '\r' || c == '\n' || c == '\t';
    }

    private boolean isSeparator(int c) {
        return c == ';' || c == ':' || c == ',';
    }

    private void nextChar() {
        curPos++;
        if (curPos < s.length()) {
            curChar = s.charAt(curPos);
        } else {
            curChar = -1;
        }
    }

    public Token nextToken() throws ParseException {
        if (!var_block_found) {
            while (isBlank(curChar)) {
                nextChar();
            }
            String cur = "";
            while (!isBlank(curChar)) {
                cur += (char) (curChar);
                nextChar();
            }
            if (cur.equals("var")) {
                var_block_found = true;
                return Token.VAR_BLOCK;
            } else {
                throw new ParseException("Not found 'var' at the beginning", curPos);
            }
        } else {
            while (isBlank(curChar)) {
                nextChar();
            }
            if (curChar == ',') {
                nextChar();
                return Token.COMMA;
            } else if (curChar == ':') {
                nextChar();
                return Token.COLON;
            } else if (curChar == ';') {
                nextChar();
                return Token.SEMICOLON;
            } else if (curChar == -1) {
                return Token.END;
            } else {
                String cur = "";
                while (!isSeparator(curChar) && curChar != -1) {
                    cur += (char) (curChar);
                    nextChar();
                    while (isBlank(curChar)) nextChar();
                }
                if (curChar == -1 || curChar == ';') {
                    return Token.TYPE_NAME;
                } else {
                    return Token.VAR_NAME;
                }
            }
        }
    }

    public static void main(String[] args) throws ParseException {
        String test1 = " var  a_int , b  :  Integer  ;   c  ,  d_real  :  Real  ;  ";
        String test2 = "var cnt,sum:Integer; avg:Real;";
        String test3 = "    var    cnt    ,     sum    :    Integer    ;    avg   :   Real   ;    ";
        LexicalAnalyzer lex = new LexicalAnalyzer(test3);
        Token t;
        do {
            t = lex.nextToken();
            System.out.print(t + " ");
        } while (t != Token.END);
    }
}
