#include <bits/stdc++.h>

using namespace std;

class DSU {
    int setsCount;
    vector<int> siz;
    mutable vector<int> par;

public:

    DSU(int n) {
        setsCount = n;
        siz.resize(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int findSetId(int u) const {
        return u == par[u] ? u : par[u] = findSetId(par[u]);
    }

   
    bool unionSets(int u, int v) {
        u = findSetId(u);
        v = findSetId(v);

        if (u == v) {
            return false;
        }

        setsCount--;
        siz[v] += siz[u];
        par[u] = v;
        return true;
    }

    int getSetSize(int u) const {
        return siz[findSetId(u)];
    }

    int getSetsCount() const {
        return setsCount;
    }
};

int main(){
    //
}