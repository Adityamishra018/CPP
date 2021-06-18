#include <bits/stdc++.h>

using namespace std;

const int N = 100100; 
const int Q = 100100;   
int n, m, a[N], cnt[N], ans[N];
int curL, curR, curAns;
int blockSize;


struct query {
    int l, r, i;

    bool operator<(const query& rhs) const {
        if (l / blockSize != rhs.l / blockSize) {
            return l < rhs.l;
        }

        return r < rhs.r;
    }
} queries[Q];

void insert(int k) {
    curAns += (++cnt[a[k]] == 1);
}

void remove(int k) {
    curAns -= (--cnt[a[k]] == 0);
}

void solveMO() {
   
    blockSize = sqrt(n) + 1;
    curL = 0, curR = -1, curAns = 0;

    sort(queries, queries + m);

    for (int i = 0; i < m; ++i) {
        query& q = queries[i];

        while (curL < q.l) remove(curL++);
        while (curL > q.l) insert(--curL);
        while (curR < q.r) insert(++curR);
        while (curR > q.r) remove(curR--);

        ans[q.i] = curAns;
    }
}


void read() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < m; ++i) {
        query& q = queries[i];
        q.i = i;
        scanf("%d %d", &q.l, &q.r);
    }
}

int main(){
    //
}