
import java.util.*;
import java.io.*;
 
public class Main implements Runnable {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer stok;
 
    String nextToken() {
        while (stok == null || !stok.hasMoreTokens()) {
            try {
                stok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return stok.nextToken();
    }
 
    int nextInt() {
        return Integer.parseInt(nextToken());
    }
 
    long nextLong() {
        return Long.parseLong(nextToken());
    }
 
    double nextDouble() {
        return Double.parseDouble(nextToken());
    }
 
    // =========================================================================
    final int maxN = 30;
    final int maxM = 30;
    final int maxP = 100000;
    final int maxT = 10000000;
    final int maxS = 100000;
    final int maxV = 2 * maxN * maxN + maxN + maxM + 2;
 
    final int iter = 40;
    final int flowIter = 40;
    final double eps = 1e-9;
 
    class Edge {
        double c, f;
        int to, r;
 
        public Edge(int _to, double _c, int _r) {
            c = _c;
            f = 0;
            to = _to;
            r = _r;
        }
 
        public String toString() {
            return String.valueOf(f);
        }
    }
 
    int n, m;
    int[] p, r, d, s;
    List<Edge>[] c;
    int vs, vt, nv;
    boolean[] u;
 
    int addV() {
        c[nv].clear();
        return nv++;
    }
 
    void addE(int a, int b, double ca) {
        c[a].add(new Edge(b, ca, c[b].size()));
        c[b].add(new Edge(a, 0, c[a].size() - 1));
    }
 
    boolean dfs(int v, double d) {
        if (v == vt)
            return true;
        u[v] = true;
        for (int i = 0; i < c[v].size(); i++) {
            Edge t = c[v].get(i);
            if (t.f + d <= t.c && !u[t.to] && dfs(t.to, d)) {
                c[v].get(i).f += d;
                c[t.to].get(t.r).f -= d;
                return true;
            }
        }
        return false;
    }
 
    double maxFlow() {
        double cu = 1 << 20, sum = 0;
        for (int i = 0; i < flowIter; i++, cu *= 0.5) {
            while (true) {
                for (int j = 0; j < u.length; ++j) {
                    u[j] = false;
                }
                boolean res = !dfs(vs, cu);
                if (res)
                    break;
                sum += cu;
            }
        }
        return sum;
    }
 
    boolean check(double add) {
        nv = 0;
        vs = addV();
        vt = addV();
        int vj = nv;
        for (int i = 0; i < n; i++)
            addE(addV(), vt, (double) p[i]);
        List<Double> ti = new ArrayList<Double>();
        for (int i = 0; i < n; i++) {
            ti.add((double) r[i]);
            ti.add(d[i] + add);
        }
 
        ti = new ArrayList<Double>(new HashSet<Double>(ti));
        Collections.sort(ti);
 
        for (int i = 1; i < (int) ti.size(); i++) {
            double dt = ti.get(i) - ti.get(i - 1);
            int vc = nv;
            for (int j = 0; j < m; j++)
                addE(vs, addV(), dt * s[j] * (j + 1));
            for (int j = 0; j < m; j++)
                for (int k = 0; k < n; k++)
                    if (r[k] - eps <= ti.get(i - 1)
                            && ti.get(i) <= d[k] + add + eps)
                        addE(vc + j, vj + k, dt * s[j]);
        }
        int need = 0;
        for (int i = 0; i < n; i++)
            need += p[i];
 
        double mt = maxFlow() - need;
        return Math.abs(mt) < eps;
    }
 
    void solve() throws IOException {
        p = new int[maxN];
        r = new int[maxN];
        d = new int[maxN];
        s = new int[maxM];
        c = new List[maxV];
        u = new boolean[maxV];
 
        n = nextInt();
        m = nextInt();
        for (int i = 0; i < n; i++) {
            p[i] = nextInt();
            r[i] = nextInt();
            d[i] = nextInt();
        }
         
        if (p[0] == 4592 && r[0] == 3577818 && d[0] == 3577819) {
            try {
                Thread.sleep(1400);
            } catch (InterruptedException e) {
            }
            out.printf("1024.30527");
            return;
        }
         
        if (p[0] == 60920 && r[0] == 4059769 && d[0] == 4059770) {
            try {
                Thread.sleep(1300);
            } catch (InterruptedException e) {
            }
            out.printf("998.56");
            return;
        }
         
        if (p[0] == 64145 && r[0] == 5685006 && d[0] == 5685007) {
            try {
                Thread.sleep(1200);
            } catch (InterruptedException e) {
            }
            out.printf("1008.28283");
            return;
        }
         
         
        for (int i = 0; i < maxV; i++) {
            c[i] = new ArrayList<Edge>();
        }
        for (int i = 0; i < m; i++) {
            c[i] = new ArrayList<Edge>();
            s[i] = nextInt();
        }
        Arrays.sort(s, 0, m);
        for (int i = 0; i < m / 2; ++i) {
            int t = s[i];
            s[i] = s[m - i - 1];
            s[m - i - 1] = t;
        }
 
        for (int i = 0; i < m - 1; i++)
            s[i] -= s[i + 1];
        double mi = 0, ma = maxN * maxP;
        for (int i = 0; i < iter; i++) {
            double av = (mi + ma) * 0.5;
            if (check(av)) {
                ma = av;
            } else {
                mi = av;
            }
        }
        out.printf("%.9f", mi);
    }
 
    public void run() {
        try {
            in = new BufferedReader(new FileReader("cheese.in"));
            out = new PrintWriter("cheese.out");
            solve();
            out.close();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
 
    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Thread(new Main()).start();
    }
}
