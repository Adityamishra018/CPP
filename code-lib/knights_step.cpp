#include<bits/stdc++.h>
using namespace std;

int minStepToReach(int knightX, int knightY, int targetX, int targetY, int N) {
   if (knightX == targetX && knightY == targetY) return 0;

    int visited[N + 1][N + 1] = {0};
    visited[knightX][knightY] = 1;

    queue<pair<int, int> > q;
    q.push({knightX, knightY});
    int rr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int cc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextr = r + rr[i];
            int nextc = c + cc[i];

            if (nextr < 1 || nextc < 1 || nextr > N || nextc > N) continue;
            if (visited[nextr][nextc] != 0) continue;
            if (nextr == targetX && nextc == targetY)
                return visited[r][c];
            visited[nextr][nextc] = visited[r][c] + 1;
            q.push(pair<int, int>(nextr, nextc));
        }
    }
    return 0;
}

int minStepToReachTarget(int k[], int T[], int n){
    return minStepToReach(k[0], k[1], T[0], T[1], n);
}

int main(){
    
    int N, a, b, c,d;
    cin>>N>>a>>b>>c>>d;
    int knightPos[] = {a, b};
    int targetPos[] = {c, d};
    cout<< minStepToReachTarget(knightPos, targetPos, N);
}


