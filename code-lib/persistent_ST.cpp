#include <bits/stdc++.h>

using namespace std;
struct node;

const int N = (1 << 17);

node *nil, *roots[N];
int n, q, x, l, r, k;

struct node {
    int size;
    node *childL, *childR;

    node() {
        size = 0;
        childL = childR = this;
    }

    node(int s, node* l = nil, node* r = nil) {
        size = s;
        childL = l;
        childR = r;
    }
};

void init() {
    roots[0] = nil = new node();
}

node* insert(node* root, int val, int l = -1e9, int r = 1e9) {
    if (val < l || val > r) {
        return root;
    }

    if (l == r) {
        return new node(1);
    }

    int mid = l + (r - l) / 2;

    node* L = insert(root->childL, val, l, mid);
    node* R = insert(root->childR, val, mid + 1, r);

    return new node(L->size + R->size, L, R);
}


int query(node* rootR, node* rootL, int idx, int l = -1e9, int r = 1e9) {
    if (l == r) {
        return l;
    }

    int cnt = rootR->childL->size - rootL->childL->size;
    int mid = l + (r - l) / 2;

    return (idx <= cnt) ?
        query(rootR->childL, rootL->childL, idx, l, mid) :
        query(rootR->childR, rootL->childR, idx - cnt, mid + 1, r);
}


int main() {
    init();
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        roots[i] = insert(roots[i - 1], x);
    }
    while (q--) {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", query(roots[r], roots[l - 1], k));
    }
    return 0;
}