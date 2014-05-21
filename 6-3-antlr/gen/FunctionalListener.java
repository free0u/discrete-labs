// Generated from /home/free0u/ifmo/discrete-labs/6-3-antlr/Functional.g4 by ANTLR 4.x
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link FunctionalParser}.
 */
public interface FunctionalListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link FunctionalParser#call}.
	 * @param ctx the parse tree
	 */
	void enterCall(@NotNull FunctionalParser.CallContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#call}.
	 * @param ctx the parse tree
	 */
	void exitCall(@NotNull FunctionalParser.CallContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterFunctions(@NotNull FunctionalParser.FunctionsContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitFunctions(@NotNull FunctionalParser.FunctionsContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(@NotNull FunctionalParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(@NotNull FunctionalParser.StmtContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#stmts}.
	 * @param ctx the parse tree
	 */
	void enterStmts(@NotNull FunctionalParser.StmtsContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#stmts}.
	 * @param ctx the parse tree
	 */
	void exitStmts(@NotNull FunctionalParser.StmtsContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#arg_type}.
	 * @param ctx the parse tree
	 */
	void enterArg_type(@NotNull FunctionalParser.Arg_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#arg_type}.
	 * @param ctx the parse tree
	 */
	void exitArg_type(@NotNull FunctionalParser.Arg_typeContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#stmt_args}.
	 * @param ctx the parse tree
	 */
	void enterStmt_args(@NotNull FunctionalParser.Stmt_argsContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#stmt_args}.
	 * @param ctx the parse tree
	 */
	void exitStmt_args(@NotNull FunctionalParser.Stmt_argsContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#init}.
	 * @param ctx the parse tree
	 */
	void enterInit(@NotNull FunctionalParser.InitContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#init}.
	 * @param ctx the parse tree
	 */
	void exitInit(@NotNull FunctionalParser.InitContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(@NotNull FunctionalParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(@NotNull FunctionalParser.ExprContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#ret_type}.
	 * @param ctx the parse tree
	 */
	void enterRet_type(@NotNull FunctionalParser.Ret_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#ret_type}.
	 * @param ctx the parse tree
	 */
	void exitRet_type(@NotNull FunctionalParser.Ret_typeContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#descr}.
	 * @param ctx the parse tree
	 */
	void enterDescr(@NotNull FunctionalParser.DescrContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#descr}.
	 * @param ctx the parse tree
	 */
	void exitDescr(@NotNull FunctionalParser.DescrContext ctx);

	/**
	 * Enter a parse tree produced by {@link FunctionalParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(@NotNull FunctionalParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link FunctionalParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(@NotNull FunctionalParser.FunctionContext ctx);
}