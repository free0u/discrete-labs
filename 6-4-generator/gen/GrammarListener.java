// Generated from /home/free0u/ifmo/discrete-labs/6-4-generator/Grammar.g4 by ANTLR 4.x
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link GrammarParser}.
 */
public interface GrammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link GrammarParser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(@NotNull GrammarParser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(@NotNull GrammarParser.StartContext ctx);

	/**
	 * Enter a parse tree produced by {@link GrammarParser#rrule}.
	 * @param ctx the parse tree
	 */
	void enterRrule(@NotNull GrammarParser.RruleContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#rrule}.
	 * @param ctx the parse tree
	 */
	void exitRrule(@NotNull GrammarParser.RruleContext ctx);

	/**
	 * Enter a parse tree produced by {@link GrammarParser#terms}.
	 * @param ctx the parse tree
	 */
	void enterTerms(@NotNull GrammarParser.TermsContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#terms}.
	 * @param ctx the parse tree
	 */
	void exitTerms(@NotNull GrammarParser.TermsContext ctx);

	/**
	 * Enter a parse tree produced by {@link GrammarParser#rule_}.
	 * @param ctx the parse tree
	 */
	void enterRule_(@NotNull GrammarParser.Rule_Context ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#rule_}.
	 * @param ctx the parse tree
	 */
	void exitRule_(@NotNull GrammarParser.Rule_Context ctx);

	/**
	 * Enter a parse tree produced by {@link GrammarParser#rules}.
	 * @param ctx the parse tree
	 */
	void enterRules(@NotNull GrammarParser.RulesContext ctx);
	/**
	 * Exit a parse tree produced by {@link GrammarParser#rules}.
	 * @param ctx the parse tree
	 */
	void exitRules(@NotNull GrammarParser.RulesContext ctx);
}