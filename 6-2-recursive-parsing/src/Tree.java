import java.util.Arrays;
import java.util.List;

/**
 * Created by free0u on 4/16/14.
 */
public class Tree {
    String node;

    List<Tree> children;

    public Tree(String node, Tree... children) {
        this.node = node;
        this.children = Arrays.asList(children);
    }

    public Tree(String node) {
        this.node = node;
    }

    private String getSpaces(int n) {
        char[] chars = new char[n];
        Arrays.fill(chars, ' ');
        String result = new String(chars);
        return result;
    }

    private String genString(int shift) {
        String spaces = getSpaces(shift);
        String result = spaces + node;
        if (children == null) {
            return result;
        }
        for (int i = 0; i < children.size(); ++i) {
            String t = children.get(i).genString(shift + 4);
            result = result + '\n' + t;
        }
        return result;
    }

    public String toString() {
        return genString(0);
    }
}
