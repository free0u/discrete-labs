#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;
#define task_name "chinese"
 
 
class DSU {
public:
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
 
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rand() & 1) {
                par[x] = y;
            } else
            {
                par[y] = x;
            }
        }
    }
    int size() {
        return par.size();
    }
private:
    vector<int> par;
};
 
 
struct edge {
    int from, to, w;
    edge * par;
 
    edge() {}
     
    edge(int from, int to, int w) : from(from), to(to), w(w)
    {
        par = NULL;
    }
 
    edge(int from, int to, int w, edge * par) : from(from), to(to), w(w), par(par)
    {
    }
};
 
typedef vector< edge > Edges;
typedef vector< Edges > Graph;
typedef pair<int, int> pii;
typedef edge * p_edge;
 
const int inf = 1e9 + 31;
 
// for test connectivity
void dfs(Graph &g, vector<bool> &used, int v) {
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to]) {
            dfs(g, used, to);
        }
    }
}
 
void dfs_zero_edges(Graph &g, vector<bool> &used, int v, vector<p_edge> &ind) {
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to] && w == 0) {
            //ind.push_back(make_pair(v, i));
            ind.push_back(&g[v][i]);
            dfs_zero_edges(g, used, to, ind);
        }
    }
}
 
void dfs_order(Graph &g, vector<bool> &used, int v, vector<int> &order) {
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to] && w == 0) {
            dfs_order(g, used, to, order);
        }
    }
    order.push_back(v);
}
 
void dfs_component(Graph &g, vector<bool> &used, int v, int &source_v, DSU &dsu) {
    used[v] = true;
    //comp.push_back(v);
    dsu.unite(v, source_v);
    int to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to] && w == 0) {
            dfs_component(g, used, to, source_v, dsu);
        }
    }
}
 
void dfs_tree(Graph &g, vector<bool> &used, int v, vector<p_edge> &ind, DSU &dsu) {
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        if (dsu.find(from) != dsu.find(to)) continue; // in different component;
        w = g[v][i].w;
        if (!used[to] && w == 0) {
            //ind.push_back(make_pair(v, i));
            ind.push_back(&g[v][i]);
            dfs_tree(g, used, to, ind, dsu);
        }
    }
}
 
void transpose_graph(Graph &g, Graph &gt) {
    int from, to, w;
    gt.resize(g.size());
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            from = g[i][j].from;
            to = g[i][j].to;
            w = g[i][j].w;
            gt[to].push_back(edge(to, from, w));
        }
    }
}
 
void edges_to_zero(Graph &g, int &start_v, vector<int> &m) {
    int n = g.size();
    int from, to, w;
 
    // find minimum
    m.assign(n, inf);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            from = g[i][j].from;
            to = g[i][j].to;
            w = g[i][j].w;
             
            //if (to == start_v) continue;
            m[to] = min(m[to], w);
        }
    }
 
    // decrease edges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            from = g[i][j].from;
            to = g[i][j].to;
 
            //if (to == start_v) continue;
            g[i][j].w -= m[to];
        }
    }
}
 
void numerate(vector<int> &m, DSU &dsu) {
    int c = 0;
    int par;
    for (int i = 0; i < dsu.size(); ++i) {
        par = dsu.find(i);
        if (m[par] != -1) continue;
        m[par] = c++;
    }
}
 

vector<int> dsu_ind;
vector<int> order;
vector<int> for_min;
Graph g_transpose;
vector<bool> used;
map<int, edge> edge_minimum;
 


bool find_mst(Graph &g, int start_v, vector<p_edge> &indexes) 
{
    int n = g.size();
 
    // test for graph connectivity
    //vector<bool> used(n);
    used.assign(n, false);
    dfs(g, used, start_v);
 
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ok = false;
            break;
        }
    }
 
    // not connectivity graph
    if (!ok) {
        return false;
    }
 
    // we have connectivity graph
    // test for tree with zero edges:
    edges_to_zero(g, start_v, for_min);
    used.assign(n, false);
    dfs_zero_edges(g, used, start_v, indexes);
 
    ok = true;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ok = false;
            break;
        }
    }
    // find tree with zero edges
    if (ok) {
        return true;
    }
 
    // not find tree with zero edges =(
    // build zero components graph:
    //DSU dsu(n); dsu in global
    DSU dsu(n);
    // order was calculate by dfs_order:
    //vector<int> order; order in global
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs_order(g, used, i, order);
        }
    }
 
    //Graph g_transpose; g_traspose in global
    g_transpose.clear();
    transpose_graph(g, g_transpose);
    used.assign(n, false);
    int count_of_component = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs_component(g_transpose, used, v, v, dsu);
            ++count_of_component;
        }
    }
 
    Graph zero_component_graph(count_of_component);
    dsu_ind.assign(n, -1);
    numerate(dsu_ind, dsu);
    int comp_with_start_v = dsu_ind[dsu.find(start_v)];
 
    // look all edges
    int from, to, w, x, y;
    edge_minimum.clear();
    map<int, edge>::iterator it;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            from = g[i][j].from;
            to = g[i][j].to;
            w = g[i][j].w;
             
            x = dsu.find(from);
            y = dsu.find(to);
            if (x != y) { // "from" and "to" in different components
                x = dsu_ind[x];
                y = dsu_ind[y];
 
                //xy = make_pair(x, y);
 
                int edge_hash = x * n + y;
 
                it = edge_minimum.find(edge_hash);
                if (it == edge_minimum.end()) { // not found
                    edge_minimum[edge_hash] = edge(x, y, w, &g[i][j]);
                } else
                {
                    if (w < it->second.w) {
                        it->second.w = w;
						it->second.par = &g[i][j];
                    }
                }
            }
        }
    }
 
    // build edges
    for (it = edge_minimum.begin(); it != edge_minimum.end(); ++it) {
        from = it->second.from;
		zero_component_graph[from].push_back(it->second);
    }
 
    vector<p_edge> indexes_in_zero_component_graph;
    // recursive step
    find_mst(zero_component_graph, comp_with_start_v, indexes_in_zero_component_graph);
 
    // restore tree
    indexes.clear();
    used.assign(n, false);
    dfs_tree(g, used, start_v, indexes, dsu);
    p_edge edge;
    for (int i = 0; i < indexes_in_zero_component_graph.size(); ++i) {
        edge = indexes_in_zero_component_graph[i];
         
        int to = edge->par->to;
        dfs_tree(g, used, to, indexes, dsu);
        indexes.push_back(edge->par);
    }
 
    return true;
}
 
int main() {
    freopen("chinese.in", "r", stdin);
	freopen("chinese.out", "w", stdout);
     
     
    string s;
    getline(cin, s);
 
    int n, m;
    cin >> n >> m;
    Graph g(n);
    int from, to, w;
    edge e;
    //vector< vector<int> > test_g(n, vector<int> (n, -1));
    map<pii, int> min_cost_edge;
    map<pii, int>::iterator it;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &w);
        from--; to--;
        e = edge(from, to, w);
        g[from].push_back(e);
 
        it = min_cost_edge.find(make_pair(from, to));
        if (it == min_cost_edge.end()) {
            min_cost_edge[make_pair(from, to)] = w;
        } else {
            if (w < it->second) {
                it->second = w;
            }
        }
    }
 
    vector<p_edge> ind;
    bool ok = find_mst(g, 0, ind);
    if (ok) {
        long long res = 0;
        for (int i = 0; i < ind.size(); ++i) {
            from = ind[i]->from;
            to = ind[i]->to;
            res += min_cost_edge[make_pair(from, to)];
        }
        cout << "YES" << endl;
        cout << res;
    } else
    {
        cout << "NO";
    }
 
 
    /*cout << endl << endl;
    for (int i = 0; i < n; ++i ){
        for (int j = 0; j < n; ++j) {
            cout << test_g[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}