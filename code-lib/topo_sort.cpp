#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}


void top(int v , vector<int> adj[] ,bool vis[] , stack<int>& s){
    vector<int>::iterator it;
    vis[v] = true;
    for(it = adj[v].begin() ; it != adj[v].end() ; ++it){
        if(!vis[*it])
        top(*it,adj,vis,s);
    }
    s.push(v);
}

vector<int> topoSort(int V, vector<int> adj[])
{

    bool vis[V];
    for(int i = 0 ; i < V ; i++)
    vis[i] = false;
    stack<int> s;
    for(int i = 0 ; i < V ; i++){
        if(!vis[i]){
            top(i,adj,vis,s);}
    }
    vector<int> arr;
    while(s.size() > 0){
    arr.push_back(s.top());
    s.pop();
    }
    return arr;
}



int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}