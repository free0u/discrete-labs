/**
 * Created by free0u on 4/20/14.
 */
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import java.io.IOException;

public class FunctionalDemo {
    public static void main(String[] args) throws IOException {
        ANTLRFileStream source = new ANTLRFileStream("test.txt" );

        FunctionalLexer lexer = new FunctionalLexer(source);
        CommonTokenStream tokens = new CommonTokenStream(lexer);

        FunctionalParser parser = new FunctionalParser(tokens);
        ParseTree tree = parser.init();

        ParseTreeWalker walker = new ParseTreeWalker();
        walker.walk(new ConvertSource(), tree);
        System.out.println();
    }
}


