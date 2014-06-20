// Generated from /home/free0u/ifmo/discrete-labs/6-4-generator/Grammar.g4 by ANTLR 4.x
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link GrammarParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface GrammarVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link GrammarParser#start}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStart(@NotNull GrammarParser.StartContext ctx);

	/**
	 * Visit a parse tree produced by {@link GrammarParser#rrule}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRrule(@NotNull GrammarParser.RruleContext ctx);

	/**
	 * Visit a parse tree produced by {@link GrammarParser#terms}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTerms(@NotNull GrammarParser.TermsContext ctx);

	/**
	 * Visit a parse tree produced by {@link GrammarParser#rule_}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRule_(@NotNull GrammarParser.Rule_Context ctx);

	/**
	 * Visit a parse tree produced by {@link GrammarParser#rules}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRules(@NotNull GrammarParser.RulesContext ctx);
}