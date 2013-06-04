#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>
#include <set>
#include <unistd.h>
#include <memory.h>
#include <cassert>

using namespace std;
#define task_name "cheese"

const int maxN = 30;
const int maxM = 30;
const int maxP = 100000;
const int maxT = 10000000;
const int maxS = 100000;
const int maxV = 2 * maxN * maxN + maxN + maxM + 2;

const int iter = 40;
const int flowIter = 40;
const double eps = 1e-9;

struct edge
{
  double c, f;
  int to, r;
  edge() {}
  edge( int _to, double _c, int _r ):
    c(_c), f(0), to(_to), r(_r) {}
};

int n, m, p[maxN], r[maxN], d[maxN], s[maxM];
vector <edge> c[maxV];
int vs, vt, nv;
bool u[maxV];

int addV() { c[nv].clear(); return nv++; }
void addE( int a, int b, double ca )
{
  c[a].push_back(edge(b, ca, c[b].size()));
  c[b].push_back(edge(a, 0, c[a].size() - 1));
}

bool dfs( int v, double d , bool deb)
{
  if (v == vt)
    return true;
  u[v] = true;
  for (int i = 0; i < (int)c[v].size(); i++)
  {
    edge t = c[v][i];
    if (t.f + d <= t.c && !u[t.to] && dfs(t.to, d, deb))
    {
      c[v][i].f += d;
      c[t.to][t.r].f -= d;
      return true;
    }
  }
  return false;
}

double maxFlow()
{
  double cu = 1 << 20, sum = 0;
  int cnt = 0;
  for (int i = 0; i < flowIter; i++, cu *= 0.5) {
      while (true)
        {
          ++cnt;
          memset(u, 0, sizeof(u));
           bool res = !dfs(vs, cu, cnt == 19);
           if (res)
            break;
          sum += cu;
        }
  }
  return sum;
}

bool check( double add )
{
  nv = 0;
  vs = addV();
  vt = addV();
  int vj = nv;
  for (int i = 0; i < n; i++)
    addE(addV(), vt, (double)p[i]);
  vector <double> ti;
  for (int i = 0; i < n; i++)
  {
    ti.push_back((double)r[i]);
    ti.push_back(d[i] + add);
  }
  sort(ti.begin(), ti.end());
  ti.resize(unique(ti.begin(), ti.end()) - ti.begin());
  for (int i = 1; i < (int)ti.size(); i++)
  {
    double dt = ti[i] - ti[i - 1];
    int vc = nv;
    for (int j = 0; j < m; j++)
      addE(vs, addV(), dt * s[j] * (j + 1));
    for (int j = 0; j < m; j++)
      for (int k = 0; k < n; k++)
        if (r[k] - eps <= ti[i - 1] &&
          ti[i] <= d[k] + add + eps)
          addE(vc + j, vj + k, dt * s[j]);
  }
  int need = 0;
  for (int i = 0; i < n; i++)
    need += p[i];

  double mt = maxFlow() - need;
  return fabs(mt) < eps;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &p[i], &r[i], &d[i]);
    }
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &s[i]);
    }
    sort(s, s + m, greater <int>());
    for (int i = 0; i < m - 1; i++)
      s[i] -= s[i + 1];


    double mi = 0, ma = maxN * maxP;
    for (int i = 0; i < iter; i++)
    {
      double av = (mi + ma) * 0.5;
      if (check(av)) {
        ma = av;
      }
      else {
        mi = av;
      }

   }
printf("%.7lf\n", mi);

    return 0;
}
