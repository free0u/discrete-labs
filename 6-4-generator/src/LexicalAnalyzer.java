/**
 * Created by free0u on 6/16/14.
 */
public class LexicalAnalyzer {
    String s;
    int curPos;

    public LexicalAnalyzer(String s) {
        this.s = s;
        curPos = 0;
    }

    public char getToken() {
        if (curPos >= s.length()) return '$';
        return s.charAt(curPos);
    }

    public void nextToken() {
        curPos++;
    }

    public int getPos() {
        return curPos;
    }
}
