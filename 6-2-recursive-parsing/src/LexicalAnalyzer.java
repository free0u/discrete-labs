import java.text.ParseException;

/**
 * Created by free0u on 4/4/14.
 */

public class LexicalAnalyzer {
    private String s;
    private int curPos;
    private int curChar;
    private Token curToken;
    private boolean var_block_found;


    public LexicalAnalyzer(String s) {
        this.s = s;
        curPos = -1;
        var_block_found = false;
        //nextChar();
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

    public void nextToken() throws ParseException {
        nextChar();
        if (!var_block_found) {
            while (isBlank(curChar)) {
                nextChar();
            }
            String cur = "";
            while (!isBlank(curChar) && curChar != -1) {
                cur += (char) (curChar);
                nextChar();
            }
            if (cur.equals("var")) {
                var_block_found = true;
                curToken = Token.VAR_KEYWORD;
                return;
            } else {
                throw new ParseException("Not found 'var' at the beginning", curPos);
            }
        } else {
            while (isBlank(curChar)) {
                nextChar();
            }
            if (curChar == ',') {
                //nextChar();
                curToken = Token.COMMA;
                return;
            } else if (curChar == ':') {
                //nextChar();
                curToken = Token.COLON;
                return;
            } else if (curChar == ';') {
                //nextChar();
                curToken = Token.SEMICOLON;
                return;
            } else if (curChar == -1) {
                curToken = Token.END;
                return;
            } else {
                String cur = "";
                while (!isSeparator(curChar) && curChar != -1) {
                    cur += (char) (curChar);
                    nextChar();
                    while (isBlank(curChar)) nextChar();
                }
                curPos--;
                curToken = Token.ID;
                return;
            }
        }
    }

    public Token getToken() {
        return curToken;
    }

    public int getPos() {
        return curPos;
    }
}
