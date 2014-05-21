import java.text.ParseException;

/**
 * Created by free0u on 4/16/14.
 */

public class Parser {
    LexicalAnalyzer lex;

    private Tree START() throws ParseException {
        switch (lex.getToken()) {
            case VAR_KEYWORD:
                // 'var'
                lex.nextToken();
                // GROUPS
                Tree sub = GROUPS();

                return new Tree("START", new Tree("var"), sub);
            default:
                throw new ParseException("'var' expected at position " + lex.getPos(), lex.getPos());
        }
    }

    private Tree GROUP() throws ParseException {
        switch (lex.getToken()) {
            case ID:
                // VARS
                Tree sub = VARS();
                // ':'
                if (lex.getToken() != Token.COLON) {
                    throw new ParseException(": expected at position " + lex.getPos(), lex.getPos());
                }
                lex.nextToken();
                // 'id'
                if (lex.getToken() != Token.ID) {
                    throw new ParseException("'id' expected at position " + lex.getPos(), lex.getPos());
                }
                lex.nextToken();
                // ';'
                if (lex.getToken() != Token.SEMICOLON) {
                    throw new ParseException("; expected at position " + lex.getPos(), lex.getPos());
                }
                lex.nextToken();

                return new Tree("GROUP", sub, new Tree(":"), new Tree("id"), new Tree(";"));
            default:
                throw new ParseException("'id' expected at position " + lex.getPos(), lex.getPos());
        }
    }

    private Tree GROUPS() throws ParseException {
        switch (lex.getToken()) {
            case ID:
                // GROUP
                Tree sub = GROUP();
                // GROUPS'
                Tree cont = GROUPSPRIME();
                return new Tree("GROUPS", sub, cont);
            default:
                throw new ParseException("'id' expected at position " + lex.getPos(), lex.getPos());
        }
    }

    private Tree GROUPSPRIME() throws ParseException {
        switch (lex.getToken()) {
            case ID:
                // GROUP
                Tree sub = GROUP();
                // GROUPS'
                Tree cont = GROUPSPRIME();

                return new Tree("GROUPS'", sub, cont);
            case END:
                return new Tree("GROUPS'", new Tree("eps"));
            default:
                throw new ParseException("'id' or 'end' expected at position " + lex.getPos(), lex.getPos());
        }
    }

    private Tree VARS() throws ParseException {
        switch (lex.getToken()) {
            case ID:
                // ID
                lex.nextToken();
                // VARS'
                Tree sub = VARSPRIME();

                return new Tree("VARS", new Tree("id"), sub);
            default:
                throw new ParseException("'id' expected at position " + lex.getPos(), lex.getPos());
        }
    }

    private Tree VARSPRIME() throws ParseException {
        switch (lex.getToken()) {
            case COMMA:
                // ,
                lex.nextToken();
                // 'id'
                if (lex.getToken() != Token.ID) {
                    throw new ParseException("'id' expected at position " + lex.getPos(), lex.getPos());
                }
                lex.nextToken();
                // VARS'
                Tree sub = VARSPRIME();

                return new Tree("VARS'", new Tree(","), new Tree("id"), sub);
            case COLON:
                return new Tree("VARS'", new Tree("eps"));
            default:
                throw new ParseException("',' or ':' expected at position " + lex.getPos(), lex.getPos());
        }
    }



    public Tree parse(String input) throws ParseException {
        lex = new LexicalAnalyzer(input);
        lex.nextToken();
        return START();
    }
}
