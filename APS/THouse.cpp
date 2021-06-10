#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
const int max_nodes = 3E5 + 5;
long k;

typedef struct Node{
    long idx,wt;
    Node(long i,long w) : idx(i),wt(w){}
}Node;

vector<long> weights;
vector<vector<long> > tree(max_nodes);
vector<Node> temp;

void calculate(long curr=0,long x = -1){
    for(auto n : tree[curr]){
        if(n != x)
            calculate(n,curr);
    }

    temp.clear();
    for(auto n : tree[curr]){
        if(n != x)
            temp.emplace_back(n,weights[n]);
    }
    sort(temp.begin(),temp.end(),[](Node &a,Node &b){ return a.wt > b.wt ;});
    k = 1;
    for(auto n : temp){
        weights[curr] += k * weights[n.idx];
        ++k;
    }
}

int32_t main(){
  long N,t,x,u,v;
  long val;
  scanf("%ld",&t);

  for(long i=0;i<t;++i){
    scanf("%ld%ld",&N,&x);

    weights.assign(N,1);
    for(long i=0;i<N;++i)
        tree[i].erase(tree[i].begin(),tree[i].end());

    for(long i=0;i<N-1;++i){
        scanf("%ld%ld",&u,&v);
        tree[u-1].emplace_back(v-1);
        tree[v-1].emplace_back(u-1);
    }
    calculate();
    val = (weights[0] % 1000000007)*x % 1000000007;
    printf("%ld\n",val);
  }
}


