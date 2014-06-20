public class Term {
    TERMS type;
    String v;

    public Term(TERMS type, String value ) {
        this.type = type;
        this.v = value;
    }

    public String toString() {
        return String.format("type:%s value:%s", type, v);
    }
}

enum TERMS {
    NONTERM, TOKEN, EPS, SYM;
}
