import org.antlr.v4.runtime.ANTLRFileStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.text.ParseException;
import java.util.*;

/**
 * Created by free0u on 6/14/14.
 */
public class Generator extends GrammarBaseListener {
    List<Rule> rules;
    String header, members;


    public Generator() {
        rules = new ArrayList<Rule>();
    }

    @Override
    public void enterStart(GrammarParser.StartContext ctx) {
        header = ctx.HEADER().getText();
        header = header.substring(7, header.length() - 2);
        members = ctx.MEMBERS().getText();
        members = members.substring(8, members.length() - 3);
    }

    @Override
    public void enterRule_(GrammarParser.Rule_Context ctx) {
        Rule rule = new Rule();

        // trans attr -- return type
        if (ctx.RETURN_SYM() != null) {
            String ret = ctx.RETURN_SYM().toString();
            ret = ret.substring(1, ret.length() - 1);
            rule.ret = ret;
        }

        // NON_TERM -- left part
        rule.non_term = ctx.NONTERM().toString();

        for (GrammarParser.RruleContext part : ctx.rrule()) {
            Rpart rpart = new Rpart();
            for (GrammarParser.TermsContext term : part.terms()) {
                if (term.WS() != null) {
                    continue;
                }
                if (term.SYM() != null) {
                    Term termd = new Term(TERMS.SYM, term.SYM().getText());
                    rpart.terms.add(termd);
                }
                if (term.NONTERM() != null) {
                    Term termd = new Term(TERMS.NONTERM, term.NONTERM().getText());
                    rpart.terms.add(termd);
                }
                if (term.TOKEN() != null) {
                    Term termd = new Term(TERMS.TOKEN, term.TOKEN().getText());
                    rpart.terms.add(termd);
                }
                if (term.EPS() != null) {
                    Term termd = new Term(TERMS.EPS, term.EPS().getText());
                    rpart.terms.add(termd);
                }
            }
            rule.rparts.add(rpart);
        }
        rules.add(rule);
    }

    public void parseGrammar() throws IOException {
        GrammarLexer lexer = new GrammarLexer(new ANTLRFileStream("PascalGrammar"));
        CommonTokenStream tokens = new CommonTokenStream(lexer);

        GrammarParser parser = new GrammarParser(tokens);
        ParseTree tree = parser.start();

        ParseTreeWalker walker = new ParseTreeWalker();
        walker.walk(this, tree);
    }

    Map<String, Set<String>> first = new HashMap<>();
    Map<String, Set<String>> follow = new HashMap<>();

    private boolean ntContainEps(String nt) {
        if (!first.containsKey(nt)) return false;
        return first.get(nt).contains("eps");
    }

    private Set<String> getFirst(Rpart part, int ind) {
        Set<String> ret = new HashSet<>();
        List<Term> terms = part.terms;

        // transform to eps?
        boolean maybe_eps = true;
        for (int i = ind; i < terms.size(); ++i) {
            Term term = terms.get(i);
            if (term.type == TERMS.TOKEN) {
                maybe_eps = false;
                break;
            } else if (term.type == TERMS.NONTERM) {
                if (!ntContainEps(term.v)) {
                    maybe_eps = false;
                    break;
                }
            }
        }
        if (maybe_eps) {
            ret.add("eps");
        }

        for (int i = ind; i < terms.size(); ++i) {
            Term term = terms.get(i);
            if (term.type == TERMS.TOKEN) {
                ret.add(term.v);
                break;
            }
            if (term.type == TERMS.NONTERM) {
                for (String t : first.get(term.v)) {
                    if (!t.equals("eps")) {
                        ret.add(t);
                    }
                }
                if (!ntContainEps(term.v)) {
                    break;
                }
            }
        }
        return ret;
    }

    private void calcFirst() {
        boolean changed = true;
        while (changed) {
            changed = false;

            for (Rule rule : rules) {
                if (!first.containsKey(rule.non_term)) {
                    first.put(rule.non_term, new HashSet<String>());
                    changed = true;
                }
                for (Rpart part : rule.rparts) {
                    // transform to eps?
                    boolean maybe_eps = true;
                    for (Term term : part.terms) {
                        if (term.type == TERMS.TOKEN) {
                            maybe_eps = false;
                            break;
                        } else if (term.type == TERMS.NONTERM) {
                            if (!ntContainEps(term.v)) {
                                maybe_eps = false;
                                break;
                            }
                        }
                    }
                    if (maybe_eps) {
                        Set<String> s = first.get(rule.non_term);
                        if (!s.contains("eps")) {
                            s.add("eps");
                            changed = true;
                        }
                    }

                    // cont
                    for (Term term : part.terms) {
                        Set<String> s = first.get(rule.non_term);
                        if (term.type == TERMS.TOKEN) {
                            if (!s.contains(term.v)) {
                                s.add(term.v);
                                changed = true;
                            }
                            break;
                        } else if (term.type == TERMS.NONTERM) {
                            if (!first.containsKey(term.v)) break;
                            for (String i : first.get(term.v)) {
                                if (!i.equals("eps")) {
                                    if (!s.contains(i)) {
                                        s.add(i);
                                        changed = true;
                                    }
                                }
                            }
                            if (!ntContainEps(term.v)) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    private void calcFollow() {
        for (int i = 0; i < rules.size(); ++i) {
            Rule rule = rules.get(i);
            follow.put(rule.non_term, new HashSet<String>());
            if (i == 0) {
                follow.get(rule.non_term).add("$");
            }
        }

        //

        for (Rule rule : rules) {
            for (Rpart part : rule.rparts) {
                List<Term> terms = part.terms;
                for (int i = 0; i < terms.size(); ++i) {
                    Term term = terms.get(i);
                    if (term.type == TERMS.NONTERM) {
                        String B = term.v;
                        Set<String> ss = getFirst(part, i + 1);
                        for (String t : ss) {
                            if (t.equals("eps")) {
                                continue;
                            }
                            follow.get(B).add(t);
                        }
                    }
                }
            }
        }

        //

        boolean changed = true;
        while (changed) {
            changed = false;
            for (Rule rule : rules) {
                String A = rule.non_term;
                for (Rpart part : rule.rparts) {
                    List<Term> terms = part.terms;
                    for (int i = 0; i < terms.size(); ++i) {
                        Term term = terms.get(i);
                        if (term.type == TERMS.NONTERM) {
                            String B = term.v;
                            Set<String> ss = getFirst(part, i + 1);
                            if (ss.contains("eps")) {
                                for (String t : follow.get(A)) {
                                    boolean st = follow.get(B).add(t);
                                    if (st) {
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private void generateParser() throws FileNotFoundException, UnsupportedEncodingException {
        calcFirst();
        calcFollow();

//        System.out.println(first);
//        System.out.println(follow);

        PrintWriter writer = new PrintWriter("./src/MyParser.java", "UTF-8");
        writer.println("import java.text.ParseException;");
        writer.println(header);

        writer.println("public class MyParser {");
        writer.println("    LexicalAnalyzer lex;");
        writer.println(members);
        writer.println("    public MyParser(LexicalAnalyzer lex) {");
        writer.println("        this.lex = lex;");
        writer.println("    }");


        for (Rule rule : rules) {
            String A = rule.non_term;

            writer.println(String.format("public class %sContext {", A));
            writer.println("String text;");
            if (rule.ret != null) {
                String sm = rule.ret;
                writer.println(sm + ";");
            }
            writer.println("}");

            // print function
            writer.println(String.format("public %sContext %sRule() throws ParseException {", A, A));
            writer.println(String.format("%sContext ctx = new %sContext();", A, A));
            writer.println("ctx.text = \"\";");
            writer.println("char ntok = lex.getToken();");
            writer.println("    switch (lex.getToken()) {");
            for (Rpart part : rule.rparts) {
                Set<String> ss = getFirst(part, 0);
                if (ss.contains("eps")) {
                    for (String t : follow.get(A)) {
                        ss.add(t);
                    }
                    ss.remove("eps");
                }
                for (String t : ss) {
                    if (t != "$") {
                        writer.println(String.format("case %s:", t));
                    } else {
                        writer.println(String.format("case '$':"));
                    }
                }
                //writer.println("//" + part.terms);
                // print logic
                int cnt = 0;
                writer.println("{");
                for (Term term : part.terms) {
                    String nn = String.format("C%d", cnt);
                    if (term.type == TERMS.TOKEN) {
                        writer.println("ctx.text += lex.getToken();");
                        writer.println("lex.nextToken();");
                        //cnt++;
                    } else if (term.type == TERMS.NONTERM) {
                        writer.println(String.format("%sContext %s = %sRule();", term.v, nn, term.v));
                        writer.println(String.format("ctx.text += %s.text;", nn));
                        cnt++;
                    } else if (term.type == TERMS.SYM) {
                        term.v = term.v.replace("$", "ctx.");
                        writer.println(term.v);
                        writer.println("//sym");
                    }
                }

                writer.println("return ctx;");
                writer.println("}");
            }

//
//            writer.println("");
//            writer.println("");
//            writer.println("");
            writer.println("default:");
            writer.println("    throw new ParseException(\"? expected at position \" + lex.getPos(), lex.getPos());");
            writer.println("}");
            writer.println("}");


            for (Rpart part : rule.rparts) {
                Set<String> s = new HashSet<>(getFirst(part, 0));
                if (s.contains("eps")) {
                    s.addAll(follow.get(A));
                    s.remove("eps");
                }
            }
        }

        writer.println("}");
        writer.close();
    }

    public static void main(String[] args) throws IOException, ParseException {
        List<String> tests = new ArrayList<String>();

        tests.add("var a:Integer;");
        tests.add("var a,b:Integer;c,d:Real;");
        tests.add(" var a_int,b:Integer  ;   c  ,  d_real  :  Real  ;  ");
        tests.add("var cnt,sum:Integer; avg:Real;");
        tests.add("    var    cnt    ,     sum    :    Integer    ;    avg   :   Real   ;    ");
        tests.add("    var    a,b,c    ,d,e:Integer;   a:Real;   f,r     ,t,y,   y : Boolean  ;  ");

        tests.add("a,b:Integer");
        tests.add("var");
        tests.add("var a,:Integer;");
        tests.add("var a:Integer");
        tests.add("var a:Integer; b");
        tests.add("var a:Integer; b;Real;");
        String source = tests.get(1);
        LexicalAnalyzer lex = new LexicalAnalyzer(source);

//        Generator gen = new Generator();
//        gen.parseGrammar();
//        gen.generateParser();

        MyParser parser = new MyParser(lex);
        parser.STARTRule();
    }
}
