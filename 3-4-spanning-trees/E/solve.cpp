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
    
typedef pair<int, int> pii;
typedef vector< vector<pii> > Graph;
    
const int inf = 1e9 + 31;
    
vector<int> order;
//vector<int> for_min;
Graph g_transpose;
vector<bool> used;
map<int, int> edge_minimum;
int cnt_order;
 
// for test connectivity
void dfs(Graph &g, int v) {
    used[v] = true;
    int to;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].first;
        if (!used[to]) {
            dfs(g, to);
        }
    }
}
    
void dfs_zero_edges(Graph &g, int v, vector<int> &for_min) 
{
    used[v] = true;
    int to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].first;
        w = g[v][i].second;
        if (!used[to] && w == for_min[to]) {
            dfs_zero_edges(g, to, for_min);
        }
    }
    order[cnt_order++] = v;
}
 
void dfs_order(Graph &g, int v, vector<int> &for_min) 
{
    used[v] = true;
    int to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].first;
        w = g[v][i].second;
        if (!used[to] && w == for_min[to]) {
            dfs_order(g, to, for_min);
        }
    }
    order[cnt_order++] = v;
}
    
void dfs_component(Graph &g, int v, vector<int> &colors, int color, vector<int> &for_min) {
    used[v] = true;
    colors[v] = color;
    int to, w;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].first;
        w = g[v][i].second;
        if (!used[to] && w == for_min[v]) {
            dfs_component(g, to, colors, color, for_min);
        }
    }
}
    
void edges_to_zero(Graph &g, int &start_v, vector<int> &for_min) {
    int n = g.size();
    int from, to, w;
    
    g_transpose.assign(n, vector<pii> ());
 
    // find minimum
    for_min.assign(n, inf);
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            from = i;
            to = g[i][j].first;
            w = g[i][j].second;
                
            g_transpose[to].push_back(make_pair(from, w));
 
            for_min[to] = min(for_min[to], w);
        }
    }
}
   
 long long ans2;
  
bool find_mst(Graph &g, int start_v) 
{
    int n = g.size();

	vector<int> min_v(n);
	edges_to_zero(g, start_v, min_v);

    cnt_order = 0;
    used.assign(n, false);
    dfs_zero_edges(g, start_v, min_v);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
		if (i != start_v) {
			ans2 += min_v[i];
		}
		if (!used[i]) {
            ok = false;
        }
    }
    if (ok) {
        return true;
    }
    
 
    // order
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs_order(g, i, min_v);
        }
    }
    
 
    // components
    used.assign(n, false);
    vector<int> colors(n);
    int count_of_component = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs_component(g_transpose, v, colors, count_of_component, min_v);
            ++count_of_component;
        }
    }
    
    Graph zero_component_graph(count_of_component);
    int comp_with_start_v = colors[start_v];
    
    // look all edges
    int from, to, w, x, y;
    map<int, int>::iterator it;
	pii p;
    edge_minimum.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            p = g[i][j];
			p.second -= min_v[p.first];
            from = i, to = p.first, w = p.second;
            x = colors[from], y = colors[to];
            if (x != y) { // "from" and "to" in different components
                int edge_hash = x * count_of_component + y;
    
                it = edge_minimum.find(edge_hash);
                if (it == edge_minimum.end()) { // not found
					edge_minimum.insert(make_pair(edge_hash, w));
                } else
                {
                    if (w < it->second) {
                        it->second = w;
                    }
                }
            }
        }
    }
    
    // build edges
	int hash;
    for (it = edge_minimum.begin(); it != edge_minimum.end(); ++it) {
		hash = it->first;
		x = hash / count_of_component;
		y = hash - x * count_of_component;
		//zero_component_graph[x].push_back(edge(x, y, it->second));
		zero_component_graph[x].push_back(make_pair(y, it->second));
    }
    
    // recursive step

	min_v.clear();
	for (int i = 0; i < n; ++i) {
		g[i].clear();
	}
    find_mst(zero_component_graph, comp_with_start_v);
    return true;
}
    
int main() {
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
        
    string s;
    //getline(cin, s);
    
    
    int n, m;
	ans2 = 0;
	cin >> n >> m;
 
    order.resize(n);
    Graph g(n);

	int from, to, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &w);
        from--; to--;
        g[from].push_back(make_pair(to, w));
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
    
    find_mst(g, 0);
   
    cout << "YES" << endl;
    cout << ans2;
    return 0;
}