import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by free0u on 4/22/14.
 */

public class ConvertSource extends FunctionalBaseListener {
    @Override public void enterFunction(FunctionalParser.FunctionContext ctx) {
        // get description of function
        FunctionalParser.DescrContext descr = ctx.descr();

        // get name of function
        String name_function = descr.ID().getText();

        // get return type
        String ret_type = ctx.descr().ret_type().getText();

        // get type of arguments
        ArrayList<String> args_type = new ArrayList<String>();
        for (TerminalNode type : descr.arg_type().ID()) {
            args_type.add(type.getText());
        }

        // get count of arguments
        int cntArgs = ctx.stmts().stmt(0).stmt_args().getChildCount();

        // get name of arguments
        ArrayList<String> args_name = new ArrayList<String>();
        String main_expr= "";
        for (FunctionalParser.StmtContext stmt : ctx.stmts().stmt()) {
            FunctionalParser.Stmt_argsContext args = stmt.stmt_args();

            List<TerminalNode> ids = args.ID();
            if (ids.size() == cntArgs) {
                    for (TerminalNode name : args.ID()) {
                    args_name.add(name.getText());
                }
                main_expr = stmt.expr().getText();

                break;
            }
        }

        // print description
        System.out.print(String.format("function %s(", name_function));
        for (int i = 0; i < args_name.size(); i++) {
            if (i > 0) {
                System.out.print(", ");
            }
            System.out.print(String.format("%s:%s", args_name.get(i), args_type.get(i).toLowerCase()));
        }
        System.out.println(String.format("):%s;", ret_type.toLowerCase()));
        System.out.println("begin");


        for (FunctionalParser.StmtContext stmt : ctx.stmts().stmt()) {
            FunctionalParser.Stmt_argsContext args = stmt.stmt_args();
            List<TerminalNode> ids = args.ID();
            if (ids.size() != cntArgs) {
                List<String> left = new ArrayList<String>();
                List<String> right = new ArrayList<String>();
                for (int i = 0; i < args.children.size(); i++) {
                    String l = args_name.get(i);
                    String r = args.children.get(i).getText();
                    if (l.equals(r)) continue;
                    left.add(l);
                    right.add(r);
                }

                System.out.print("  if (");
                for (int i = 0; i < left.size(); i++ ) {
                    if (i > 0) {
                        System.out.print(" and ");
                    }
                    System.out.print(String.format("%s == %s", left.get(i), right.get(i)));
                }
                System.out.println(") then");
                System.out.println(String.format("    return %s;", stmt.expr().getText()));
            }
        }

        // default return
        System.out.println(String.format("  return %s;", main_expr));

        System.out.println("end;");

        System.out.println();
    }

}
