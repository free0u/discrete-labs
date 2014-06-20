public class Parser {
    LexicalAnalyzer lex;

    public Parser(LexicalAnalyzer lex) {
        this.lex = lex;
    }

    public class STARTContext {
        String text;
    }

    public void STARTRule() throws ParseException {
        switch (lex.getToken()) {
            case 'v':
                lex.nextToken();
                lex.nextToken();
                GROUPSRule();
                break;
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class GROUPSContext {
        String text;
        int i;
    }

    public void GROUPSRule() throws ParseException {
        switch (lex.getToken()) {
            case 'i':
                GROUPRule();
                GROUPSPRule();
                break;
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class GROUPSPContext {
        String text;
    }

    public void GROUPSPRule() throws ParseException {
        switch (lex.getToken()) {
            case 'i':
                GROUPRule();
                GROUPSPRule();
                break;
            case null:
                break;
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class GROUPContext {
        String text;
    }

    public void GROUPRule() throws ParseException {
        switch (lex.getToken()) {
            case 'i':
                VARSRule();
                lex.nextToken();
                lex.nextToken();
                lex.nextToken();
                break;
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class VARSContext {
        String text;
    }

    public void VARSRule() throws ParseException {
        switch (lex.getToken()) {
            case 'i':
                lex.nextToken();
                VARSPRule();
                break;
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class VARSPContext {
        String text;
    }

    public void VARSPRule() throws ParseException {
        switch (lex.getToken()) {
            case ',':
                lex.nextToken();
                lex.nextToken();
                VARSPRule();
                break;
            case ':':
                break;
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }
}
