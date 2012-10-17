#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define task_name "movetofront"


struct node {
    int x, y;
    int size;
    node *l, *r;
    node() {l = r = NULL;}
    node(int data, int prior) {
        x = data;
        y = prior;
        l = r = NULL;
        size = 1;
    }
    ~node() {
        if (l) delete l;
        if (r) delete r;
    }
};
typedef node* pnode;
 
 
int size(pnode t) {
    return (t ? t->size : 0);
}
 
void recalc(pnode t) {
    if (t) {
        t->size = 1 + size(t->l) + size(t->r);
    }
}
 
void split(pnode t, int x, pnode &l, pnode &r) {
    if (!t) {
        l = r = NULL;
    } else
    {
        int cur_ind = size(t->l) + 1;
        if (x < cur_ind) {
            split(t->l, x, l, t->l);
            r = t;
        } else
        {
            split(t->r, x - cur_ind, t->r, r);
            l = t;
        }
    }
    recalc(t);
}
 
void insert(pnode &t, pnode it) {
    if (!t) t = it;
    else if (it->y > t->y)
        split(t, it->x, it->l, it->r), t = it;
    else insert(it->x <= t->x ? t->l : t->r, it);
    recalc(t);
}
 
 
void merge(pnode &t, pnode l, pnode r) {
    if (!l || !r) t = (l ? l : r);
    else if (l->y > r->y)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    recalc(t);
}
 
void insert(pnode &t, int ind, pnode it) {
    pnode l, r;
    split(t, ind, l, r);
    merge(t, l, it);
    pnode nt = NULL;
    merge(nt, t, r);
    t = nt;
}
 
 
void pr(pnode t) {
    if (!t) return void();
    if (t->l) pr(t->l);
    //cout << t->x << " ";
    printf("%d ", t->x);
	if (t->r) pr(t->r);
}
 
void change(pnode &t, int a, int b) {
    pnode A, B, C;
    A = B = C = NULL;
    split(t, a, A, B);
    split(B, b - a + 1, B, C);
    merge(B, B, A);
    merge(B, B, C);
    t = B;
}


int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
    cin >> n >> m;
   
    pnode t = NULL;
    for (int i = 0; i < n; i++) {
        insert(t, i, new node(i + 1, rand()));
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
        change(t, x, y);
    }
 
    pr(t);

	return 0;
}