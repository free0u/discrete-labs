import java.util.ArrayList;
import java.util.List;

/**
 * Created by free0u on 6/15/14.
 */
public class Rule {
    String non_term;
    String ret;
    List<Rpart> rparts = new ArrayList<Rpart>();

    public Rule() {
    }

    public String toString() {
        return String.format("NT:%s; RET:%s; rparts:%s", non_term, ret, rparts);
    }
}

