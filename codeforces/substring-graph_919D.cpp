#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int cnt = INT_MIN;
string cost;
string path;
vector<bool> recstack;
vector<bool> visited;
vector<vector<int> > mat;

int maxcount(){
     int ans = INT_MIN;
     for(auto c : path)
         ans = std::max(ans,int(std::count(path.begin(),path.end(),c)));
     return ans;
}

bool checkFor(int i){
    
    if(visited[i] == false){
        visited[i] = true;
        recstack[i] = true;

        for(auto v : mat[i]){
            if( !visited[v] and checkFor(v))
                return true;
            else if(recstack[v] == true)
                return true;
        }
    }
    recstack[i] = false;
    return false; 
}

bool isCyclic(int n){
    for(int i =1;i<=n;++i){
        if(checkFor(i))
            return true;
    }
    return false;
}

void calculate_dfs(int i){
    path.push_back(cost[i-1]);
    for(auto v : mat[i])
        calculate_dfs(v);
    cnt = std::max(cnt,maxcount());
    path.pop_back();
}

int main(){
    int m,n;
    int x,y;

    cin>>n>>m;
    cin>>cost;
    mat.assign(n+1,vector<int>(0));
    path.assign(n,' ');
    visited.assign(n+1,false);
    recstack.assign(n+1,false);
    
    for(int i=0;i<m;++i){
        cin>>x>>y;
        mat[x].emplace_back(y);
    }

    //if graph is cyclic print -1
    if(isCyclic(n)){
        cout<<"Max Count : -1";
        return 0;
    }


    //check for every path 
    path.erase(path.begin(),path.end());
    for(int i=1;i<=n;++i)
        calculate_dfs(i);
    
    cout<<"Max Count : "<<cnt;
    
} 