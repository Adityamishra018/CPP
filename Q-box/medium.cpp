/*
Que requires that we remove as many edges so that the resultant connected components
have even no of nodes.

sol : because we are only removing edges, the que guarantees we begin with even no of nodes in total.
also wkt that given graph is connected and has no cycles. The idea is to remove the edge from every subtree
to its parent if the resultant subtree remains even.you can implement a simple dfs for this while keeping
a count of no of children for every node.
*/

#include<bits/stdc++.h>
using namespace std;

int w[105][105] = {0}, v[105] = {0};
int n,m,ans=0;

int dfs(int x){
    v[x] = 1;
    int no_of_child = 0;
    for(int i=0; i<105;i++) 
        if(w[x][i] && !v[i]) no_of_child += dfs(i);

    /*if noc is odd , meaning including the parent the component size is even so we can
    remove its edge to its parent,notice how this if wont run for any leaf node, because you 
    cannot remove edge to any leaf node */
    if(no_of_child % 2) {
         ans++; //remove edge of this component to its parent
         return 0;
    }

    //otherwise count this entire component as one child for its parent.
    return 1;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d", &n,&m);
        for(int i=0,a,b; i<m;i++){
            scanf("%d%d", &a,&b);
            w[a][b] = w[b][a] = 1;
        }
        dfs(1);
        printf("%d\n", ans-1);  
        /*The -1 part is becuase the que guarantees that given graph would always have even no of nodes
        so calling dfs on vertex 1(or any node) will always receive odd no of childs, so that way we end up
        incrementing global ans by extra 1 at the end, because the entire graph given in que can be removed from
        its hypothetical parent node as it(the given graph) contains even no of nodes*/
        
        //clear
        ans = 0;
        for(int i=0;i<105;++i){
            v[i] = 0;
            for(int j=0;j<105;++j)
                w[i][j] = 0;
        }   
    }
    return 0;
}