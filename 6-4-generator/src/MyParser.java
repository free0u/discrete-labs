import java.text.ParseException;

public class MyParser {
    LexicalAnalyzer lex;
    Tree root;

    public MyParser(LexicalAnalyzer lex) {
        this.lex = lex;
    }

    public class STARTContext {
        String text;
    }

    public STARTContext STARTRule() throws ParseException {
        STARTContext ctx = new STARTContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'v': {
                ctx.text += lex.getToken();
                lex.nextToken();
                ctx.text += lex.getToken();
                lex.nextToken();
                ctx.text += lex.getToken();
                lex.nextToken();
                ctx.text += lex.getToken();
                lex.nextToken();
                GROUPSContext C0 = GROUPSRule();
                ctx.text += C0.text;
                {
                    root = new Tree("var", C0.tree);
                    System.out.println(root);
                }
//sym
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class GROUPSContext {
        String text;
        Tree tree;
    }

    public GROUPSContext GROUPSRule() throws ParseException {
        GROUPSContext ctx = new GROUPSContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'J':
            case 'i':
            case 'V':
            case 'F':
            case 'z':
            case 'R':
            case 'm':
            case 'Z':
            case 'e':
            case 'r':
            case 'B':
            case 'a':
            case 'v':
            case 'U':
            case 'j':
            case 'K':
            case 'n':
            case 'Q':
            case 'G':
            case 'f':
            case 'w':
            case 'Y':
            case 'o':
            case 's':
            case ':':
            case ',':
            case 'C':
            case 'b':
            case 'g':
            case 'L':
            case 'T':
            case 'P':
            case 'k':
            case 'H':
            case 'x':
            case 'p':
            case 'X':
            case 'c':
            case 't':
            case 'D':
            case 'M':
            case 'S':
            case 'h':
            case 'I':
            case 'l':
            case 'y':
            case 'O':
            case 'N':
            case 'q':
            case 'd':
            case 'W':
            case 'A':
            case 'u':
            case 'E': {
                GROUPContext C0 = GROUPRule();
                ctx.text += C0.text;
                GROUPSPContext C1 = GROUPSPRule();
                ctx.text += C1.text;
                {
                    ctx.tree = new Tree("GROUPS", C0.tree, C1.tree);
                }
//sym
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class GROUPSPContext {
        String text;
        Tree tree;
    }

    public GROUPSPContext GROUPSPRule() throws ParseException {
        GROUPSPContext ctx = new GROUPSPContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'J':
            case 'i':
            case 'V':
            case 'F':
            case 'z':
            case 'R':
            case 'm':
            case 'Z':
            case 'e':
            case 'r':
            case 'B':
            case 'a':
            case 'v':
            case 'U':
            case 'j':
            case 'K':
            case 'n':
            case 'Q':
            case 'G':
            case 'f':
            case 'w':
            case 'Y':
            case 'o':
            case 's':
            case ':':
            case ',':
            case 'C':
            case 'b':
            case 'g':
            case 'L':
            case 'T':
            case 'P':
            case 'k':
            case 'H':
            case 'x':
            case 'p':
            case 'X':
            case 'c':
            case 't':
            case 'D':
            case 'M':
            case 'S':
            case 'h':
            case 'I':
            case 'l':
            case 'y':
            case 'O':
            case 'N':
            case 'q':
            case 'd':
            case 'W':
            case 'A':
            case 'u':
            case 'E': {
                GROUPContext C0 = GROUPRule();
                ctx.text += C0.text;
                GROUPSPContext C1 = GROUPSPRule();
                ctx.text += C1.text;
                {
                    ctx.tree = new Tree("GROUPSP", C0.tree, C1.tree);
                }
//sym
                return ctx;
            }
            case '$': {
                {
                    ctx.tree = new Tree("eps");
                }
//sym
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class GROUPContext {
        String text;
        Tree tree;
    }

    public GROUPContext GROUPRule() throws ParseException {
        GROUPContext ctx = new GROUPContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'J':
            case 'i':
            case 'V':
            case 'F':
            case 'z':
            case 'R':
            case 'm':
            case 'Z':
            case 'e':
            case 'r':
            case 'B':
            case 'a':
            case 'v':
            case 'U':
            case 'j':
            case 'K':
            case 'n':
            case 'Q':
            case 'G':
            case 'f':
            case 'Y':
            case 'w':
            case 'o':
            case 's':
            case ':':
            case ',':
            case 'C':
            case 'b':
            case 'g':
            case 'L':
            case 'T':
            case 'P':
            case 'k':
            case 'H':
            case 'x':
            case 'p':
            case 'X':
            case 'c':
            case 't':
            case 'D':
            case 'M':
            case 'S':
            case 'h':
            case 'I':
            case 'l':
            case 'y':
            case 'O':
            case 'N':
            case 'd':
            case 'q':
            case 'W':
            case 'A':
            case 'u':
            case 'E': {
                VARSContext C0 = VARSRule();
                ctx.text += C0.text;
                ctx.text += lex.getToken();
                lex.nextToken();
                IDContext C1 = IDRule();
                ctx.text += C1.text;
                ctx.text += lex.getToken();
                lex.nextToken();
                {
                    ctx.tree = new Tree("GROUP", C0.tree, new Tree(":"), new Tree(C1.text), new Tree(";"));
                }
//sym
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class VARSContext {
        String text;
        Tree tree;
    }

    public VARSContext VARSRule() throws ParseException {
        VARSContext ctx = new VARSContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'J':
            case 'i':
            case 'V':
            case 'F':
            case 'z':
            case 'R':
            case 'm':
            case 'Z':
            case 'e':
            case 'r':
            case 'B':
            case 'a':
            case 'v':
            case 'U':
            case 'j':
            case 'K':
            case 'n':
            case 'Q':
            case 'G':
            case 'f':
            case 'w':
            case 'Y':
            case 's':
            case 'o':
            case ':':
            case ',':
            case 'C':
            case 'b':
            case 'g':
            case 'L':
            case 'T':
            case 'P':
            case 'k':
            case 'H':
            case 'x':
            case 'p':
            case 'X':
            case 'c':
            case 't':
            case 'D':
            case 'M':
            case 'S':
            case 'h':
            case 'I':
            case 'l':
            case 'y':
            case 'O':
            case 'N':
            case 'q':
            case 'd':
            case 'W':
            case 'A':
            case 'u':
            case 'E': {
                IDContext C0 = IDRule();
                ctx.text += C0.text;
                VARSPContext C1 = VARSPRule();
                ctx.text += C1.text;
                {
                    ctx.tree = new Tree("VARS", new Tree(C0.text), C1.tree);
                }
//sym
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class VARSPContext {
        String text;
        Tree tree;
    }

    public VARSPContext VARSPRule() throws ParseException {
        VARSPContext ctx = new VARSPContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case ',': {
                ctx.text += lex.getToken();
                lex.nextToken();
                IDContext C0 = IDRule();
                ctx.text += C0.text;
                VARSPContext C1 = VARSPRule();
                ctx.text += C1.text;
                {
                    ctx.tree = new Tree("VARSP", new Tree(","), new Tree(C0.text), C1.tree);
                }
//sym
                return ctx;
            }
            case ':': {
                {
                    ctx.tree = new Tree("eps");
                }
//sym
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class IDContext {
        String text;
    }

    public IDContext IDRule() throws ParseException {
        IDContext ctx = new IDContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'J':
            case 'i':
            case 'V':
            case 'F':
            case 'z':
            case 'R':
            case 'm':
            case 'Z':
            case 'e':
            case 'r':
            case 'B':
            case 'a':
            case 'v':
            case 'U':
            case 'j':
            case 'K':
            case 'n':
            case 'Q':
            case 'G':
            case 'f':
            case 'Y':
            case 'w':
            case 'o':
            case 's':
            case 'C':
            case 'b':
            case 'g':
            case 'L':
            case 'T':
            case 'P':
            case 'k':
            case 'H':
            case 'x':
            case 'p':
            case 'X':
            case 'c':
            case 't':
            case 'D':
            case 'M':
            case 'S':
            case 'h':
            case 'I':
            case 'l':
            case 'y':
            case 'O':
            case 'N':
            case 'q':
            case 'd':
            case 'W':
            case 'A':
            case 'u':
            case 'E': {
                CHARContext C0 = CHARRule();
                ctx.text += C0.text;
                IDContext C1 = IDRule();
                ctx.text += C1.text;
                return ctx;
            }
            case ';':
            case ':':
            case ',': {
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class UPPER_CHARContext {
        String text;
    }

    public UPPER_CHARContext UPPER_CHARRule() throws ParseException {
        UPPER_CHARContext ctx = new UPPER_CHARContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'A': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'B': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'C': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'D': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'E': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'F': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'G': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'H': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'I': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'J': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'K': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'L': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'M': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'N': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'O': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'P': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'Q': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'R': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'S': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'T': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'U': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'V': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'W': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'X': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'Y': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'Z': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class LOWER_CHARContext {
        String text;
    }

    public LOWER_CHARContext LOWER_CHARRule() throws ParseException {
        LOWER_CHARContext ctx = new LOWER_CHARContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'a': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'b': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'c': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'd': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'e': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'f': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'g': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'h': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'i': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'j': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'k': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'l': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'm': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'n': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'o': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'p': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'q': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'r': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 's': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 't': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'u': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'v': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'w': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'x': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'y': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            case 'z': {
                ctx.text += lex.getToken();
                lex.nextToken();
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }

    public class CHARContext {
        String text;
    }

    public CHARContext CHARRule() throws ParseException {
        CHARContext ctx = new CHARContext();
        ctx.text = "";
        char ntok = lex.getToken();
        switch (lex.getToken()) {
            case 'g':
            case 'h':
            case 'j':
            case 'i':
            case 'n':
            case 'z':
            case 'm':
            case 'k':
            case 'l':
            case 'y':
            case 'x':
            case 'e':
            case 'f':
            case 'w':
            case 'r':
            case 'q':
            case 'd':
            case 'p':
            case 's':
            case 'o':
            case 'c':
            case 't':
            case 'u':
            case 'a':
            case 'v':
            case 'b': {
                LOWER_CHARContext C0 = LOWER_CHARRule();
                ctx.text += C0.text;
                return ctx;
            }
            case 'L':
            case 'T':
            case 'M':
            case 'S':
            case 'J':
            case 'U':
            case 'V':
            case 'F':
            case 'K':
            case 'Q':
            case 'R':
            case 'G':
            case 'I':
            case 'P':
            case 'H':
            case 'O':
            case 'Z':
            case 'N':
            case 'Y':
            case 'W':
            case 'A':
            case 'X':
            case 'B':
            case 'D':
            case 'E':
            case 'C': {
                UPPER_CHARContext C0 = UPPER_CHARRule();
                ctx.text += C0.text;
                return ctx;
            }
            default:
                throw new ParseException("? expected at position " + lex.getPos(), lex.getPos());
        }
    }
}
