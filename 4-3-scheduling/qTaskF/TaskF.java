import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class TaskF implements Runnable {
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

   
    class Func {
    	BigInteger[] coef;
    	
    	public Func(int[] coef) {
    		this.coef = new BigInteger[coef.length];
    		for (int i = 0; i < coef.length; i++) {
    			this.coef[i] = BigInteger.valueOf(coef[i]);
    		}
    	}
    	public BigInteger calc(long x) {
            BigInteger res = BigInteger.ZERO;
            BigInteger st = BigInteger.ONE;
            BigInteger value = BigInteger.valueOf(x);
            
            for (int i = coef.length - 1; i >= 0; --i) {
                res = res.add(coef[i].multiply(st));
                st = st.multiply(value);
            }

            return res;
        }

    }
    
    void solve() throws IOException {
        int n = nextInt();
        int[] p = new int[n];
        Set<Integer> S = new TreeSet<>();
        
        long p_all = 0;
        for (int i = 0; i < n; ++i) {
            p[i] = nextInt();
            p_all += p[i];
            S.add(i);
        }

        Func[] fs = new Func[n];
        for (int i = 0; i < n; ++i) {
            int m = nextInt() + 1;
            int[] coef = new int[m];
            
            for (int j = 0; j < m; ++j) {
                coef[j] = nextInt();
            }

            fs[i] = new Func(coef);
        }
        
        
        int d = nextInt();
        int[][] g = new int[n][n];
        for (int i = 0; i < d; ++i) {
            g[nextInt() - 1][nextInt() - 1] = 1;
        }

        int[] ni = new int[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ni[i] += g[i][j];
            }
        }
       
        BigInteger ans = BigInteger.ZERO, t = null;

        long[] pi = new long[n];
        int ind;
        for (int k = n - 1; k >= 0;  --k) {
            ind = -1;
            for (Integer i : S) {
                if (ni[i] != 0) continue;
                if (ind == -1) {
                    ind = i;
                    t = fs[ind].calc(p_all);
                    continue;
                }
                if (fs[i].calc(p_all).compareTo(t) < 0) {
                    ind = i;
                    t = fs[ind].calc(p_all);
                }
            }

            if (ans.compareTo(t) < 0) {
                ans = t;
            }

            S.remove(ind);
            p_all -= p[ind];
            pi[ind] = p_all;
            for (int i = 0; i < n; ++i) {
                if (g[i][ind] == 1) {
                    --ni[i];
                }
            }
        }
        
        out.println(ans);
        for (int i = 0; i < pi.length; i++) {
        	out.print(pi[i] + " ");
        }

    }

    public void run() {
        try {
        	out = new PrintWriter("p1precfmax.out");
            in = new BufferedReader(new FileReader("p1precfmax.in"));
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
        new Thread(new TaskF()).start();
    }
}