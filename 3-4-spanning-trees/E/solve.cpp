#pragma comment(linker, "/STACK:128000000")
  
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
  
#include <unordered_map>
 
using namespace std;
#define task_name "chinese"
    
    
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
    
vector<int> order;
vector<int> for_min;
Graph g_transpose;
vector<bool> used;
unordered_map<int, edge> edge_minimum;
int cnt_order;
 
// for test connectivity
void dfs(Graph &g, int v) {
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to]) {
            dfs(g, to);
        }
    }
}
    
void dfs_zero_edges(Graph &g, int v, vector<p_edge> &ind) 
{
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to] && w == for_min[to]) {
            ind.push_back(&g[v][i]);
            dfs_zero_edges(g, to, ind);
        }
    }
    order[cnt_order++] = v;
}
 
void dfs_order(Graph &g, int v) 
{
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to] && w == for_min[to]) {
            dfs_order(g, to);
        }
    }
    order[cnt_order++] = v;
}
    
void dfs_component(Graph &g, int v, int &source_v, vector<int> &colors, int color) {
    used[v] = true;
    colors[v] = color;
    int to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].to;
        w = g[v][i].w;
        if (!used[to] && w == for_min[g[v][i].from]) {
            dfs_component(g, to, source_v, colors, color);
        }
    }
}
    
void dfs_tree(Graph &g, int v, vector<p_edge> &ind, vector<int> &colors) {
    used[v] = true;
    int from, to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        from = g[v][i].from;
        to = g[v][i].to;
        w = g[v][i].w;
        if (colors[from] != colors[to]) continue; // in different component;
        if (!used[to] && w == 0) {
            ind.push_back(&g[v][i]);
            dfs_tree(g, to, ind, colors);
        }
    }
}
 
void edges_to_zero(Graph &g, int &start_v) {
    int n = g.size();
    int from, to, w;
    
    g_transpose.assign(n, Edges());
 
    // find minimum
    for_min.assign(n, inf);
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            from = g[i][j].from;
            to = g[i][j].to;
            w = g[i][j].w;
                
            g_transpose[to].push_back(edge(to, from, w));
 
            //if (to == start_v) continue;
            for_min[to] = min(for_min[to], w);
        }
    }
}
   
 
  
bool find_mst(Graph &g, int start_v, vector<p_edge> &indexes) 
{
    int n = g.size();
    
    // test for tree with zero edges:
    cnt_order = 0;
    edges_to_zero(g, start_v);
    used.assign(n, false);
    dfs_zero_edges(g, start_v, indexes);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        return true;
    }
    
 
    // order
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs_order(g, i);
        }
    }
    
 
    // components
    used.assign(n, false);
    vector<int> colors(n);
    int count_of_component = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs_component(g_transpose, v, v, colors, count_of_component);
            ++count_of_component;
        }
    }
    
    Graph zero_component_graph(count_of_component);
    int comp_with_start_v = colors[start_v];
    
    // look all edges
    int from, to, w, x, y;
    edge_minimum.clear();
    unordered_map<int, edge>::iterator it;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            g[i][j].w -= for_min[g[i][j].to];
            from = g[i][j].from, to = g[i][j].to, w = g[i][j].w;
            x = colors[from], y = colors[to];
            if (x != y) { // "from" and "to" in different components
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
    dfs_tree(g, start_v, indexes, colors);
    p_edge edge;
    for (int i = 0; i < indexes_in_zero_component_graph.size(); ++i) {
        edge = indexes_in_zero_component_graph[i];
            
        int to = edge->par->to;
        dfs_tree(g, to, indexes, colors);
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
 
    order.resize(n);
 
    Graph g(n);
    int from, to, w;
    edge e;
    //vector< vector<int> > test_g(n, vector<int> (n, -1));
    map<int, int> min_cost_edge;
    map<int, int>::iterator it;
    int hash;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &w);
        from--; to--;
        e = edge(from, to, w);
        g[from].push_back(e);
    
        hash = from * n + to;
        it = min_cost_edge.find(hash);
        if (it == min_cost_edge.end()) {
            min_cost_edge[hash] = w;
        } else {
            if (w < it->second) {
                it->second = w;
            }
        }
    }
    
  
  
    used.assign(n, false);
    dfs(g, 0);
    
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ok = false;
            cout << "NO";
            return 0;
        }
    }
    
    vector<p_edge> ind;
    find_mst(g, 0, ind);
    long long res = 0;
    int x, y;
    for (int i = 0; i < ind.size(); ++i) {
        from = ind[i]->from;
        to = ind[i]->to;
        res += min_cost_edge[from * n + to];
    }
    cout << "YES" << endl;
    cout << res;
     
    
    
    /*cout << endl << endl;
    for (int i = 0; i < n; ++i ){
        for (int j = 0; j < n; ++j) {
            cout << test_g[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}