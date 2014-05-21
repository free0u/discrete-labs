// Generated from /home/free0u/ifmo/discrete-labs/6-3-antlr/Functional.g4 by ANTLR 4.x
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link FunctionalParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface FunctionalVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link FunctionalParser#call}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall(@NotNull FunctionalParser.CallContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#functions}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctions(@NotNull FunctionalParser.FunctionsContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmt(@NotNull FunctionalParser.StmtContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#stmts}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmts(@NotNull FunctionalParser.StmtsContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#arg_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArg_type(@NotNull FunctionalParser.Arg_typeContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#stmt_args}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmt_args(@NotNull FunctionalParser.Stmt_argsContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#init}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInit(@NotNull FunctionalParser.InitContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(@NotNull FunctionalParser.ExprContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#ret_type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRet_type(@NotNull FunctionalParser.Ret_typeContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#descr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDescr(@NotNull FunctionalParser.DescrContext ctx);

	/**
	 * Visit a parse tree produced by {@link FunctionalParser#function}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunction(@NotNull FunctionalParser.FunctionContext ctx);
}