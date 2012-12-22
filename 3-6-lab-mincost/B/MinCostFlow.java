import java.io.*;
import java.util.*;

public class MinCostFlow {
	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	static class Edge {
		int to, f, rev;
		long cap, cost;
		Edge(int v, int cap, int cost, int rev) {
			this.to = v;
			this.cap = cap;
			this.cost = cost;
			this.rev = rev;
		}
	}

	static class Node {
		long a, b;
		Node(long a, long b) {
			this.a = a;
			this.b = b;
		}
	}
	
	public static List<Edge>[] createGraph(int n) {
		List<Edge>[] graph = new List[n];
		for (int i = 0; i < n; i++)
			graph[i] = new ArrayList<Edge>();
		return graph;
	}

	public static void addEdge(List<Edge>[] graph, int s, int t, int cap,
			int cost) {
		graph[s].add(new Edge(t, cap, cost, graph[t].size()));
		graph[t].add(new Edge(s, 0, -cost, graph[s].size() - 1));
	}

	static void bellmanFord(List<Edge>[] graph, int s, long[] dist) {
		int n = graph.length;
		Arrays.fill(dist, 0, n, Long.MAX_VALUE);
		dist[s] = 0;
		boolean[] inqueue = new boolean[n];
		int[] q = new int[n];
		int qt = 0;
		q[qt++] = s;
		for (int qh = 0; (qh - qt) % n != 0; qh++) {
			int u = q[qh % n];
			inqueue[u] = false;
			for (int i = 0; i < (int) graph[u].size(); i++) {
				Edge e = graph[u].get(i);
				if (e.cap <= e.f)
					continue;
				int v = e.to;
				long ndist = dist[u] + e.cost;
				if (dist[v] > ndist) {
					dist[v] = ndist;
					if (!inqueue[v]) {
						inqueue[v] = true;
						q[qt++ % n] = v;
					}
				}
			}
		}
	}

	static long minCostFlow(List<Edge>[] graph, int s, int t, long maxf) {
		int n = graph.length;
		long[] prio = new long[n];
		long[] curflow = new long[n];
		int[] prevedge = new int[n];
		int[] prevnode = new int[n];
		long[] pot = new long[n];

		// bellmanFord can be safely commented if edges costs are non-negative
		bellmanFord(graph, s, pot);
		long flow = 0;
		long flowCost = 0;
		while (flow < maxf) {
			//Queue<Long> q = new PriorityQueue<Long>();
			PriorityQueue<Node> q = new PriorityQueue<Node>(10, new Comparator<Node>() {
			    public int compare(Node n1, Node n2) {
			        if (n1.a < n2.a) return -1;
			        if (n1.a > n2.a) return 1;
			        if (n1.b < n2.b) return -1;
			        if (n1.b > n2.b) return 1;
			        return 0;
			    }
			});
			q.add(new Node(0, s));
			Arrays.fill(prio, 0, n, Long.MAX_VALUE);
			prio[s] = 0;
			curflow[s] = Long.MAX_VALUE;
			while (!q.isEmpty()) {
				Node cur = q.remove();
				long d = cur.a;//(int) (cur >>> 32);
				int u = (int) cur.b;//(int) cur;
				if (d != prio[u])
					continue;
				for (int i = 0; i < (int) graph[u].size(); i++) {
					Edge e = graph[u].get(i);
					int v = e.to;
					if (e.cap <= e.f)
						continue;
					long nprio = prio[u] + e.cost + pot[u] - pot[v];
					if (prio[v] > nprio) {
						prio[v] = nprio;
						//q.add(((long) nprio << 32) + v);
						q.add(new Node(nprio, v));
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = Math.min(curflow[u], e.cap - e.f);
					}
				}
			}
			if (prio[t] == Long.MAX_VALUE)
				break;
			for (int i = 0; i < n; i++)
				pot[i] += prio[i];
			long df = Math.min(curflow[t], maxf - flow);
			flow += df;
			for (int v = t; v != s; v = prevnode[v]) {
				Edge e = graph[prevnode[v]].get(prevedge[v]);
				e.f += df;
				graph[v].get(e.rev).f -= df;
				flowCost += df * e.cost;
			}
		}
		return flowCost;
	}

	void solve() throws IOException {
		int n, m;
		n = nextInt();
		m = nextInt();
		int from, to, cap, cost;
		List<Edge>[] graph = createGraph(n);
		for (int i = 0; i < m; ++i) {
			from = nextInt();
			to = nextInt();
			cap = nextInt();
			cost = nextInt();
			addEdge(graph, from - 1, to - 1, cap, cost);
		}
		
		long flowCost = minCostFlow(graph, 0, n - 1, Long.MAX_VALUE);
		out.println(flowCost);
	}

	void run() throws IOException {
		br = new BufferedReader(new FileReader("mincost.in"));
		out = new PrintWriter("mincost.out");
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Locale.setDefault(Locale.US);
		new MinCostFlow().run();
	}

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return null;
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}
}
