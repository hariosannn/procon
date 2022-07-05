#include <bits/stdc++.h>
using namespace std;

int inf = 1e9;

vector<vector<int>> graph = {{0 , 5, 0, 10, 0, 0, 0},
                             {5 , 0, 3, 0 , 0, 0, 2},
                             {0 , 3, 0, 1 , 0, 8, 9},
                             {10, 0, 1, 0 , 6, 0, 0},
                             {0 , 0, 0, 6 , 0, 4, 0},
                             {0 , 0, 8, 0 , 4, 0, 6},
                             {0 , 2, 9, 0 , 0, 6, 0}};

                             

int main(){
    queue<int> que;
    int start = 2;
    que.push(start);
    int n = graph.size();
    vector<int> dist(n, -1); 
    dist.at(start) = 0;

    while(!que.empty()){
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(int i=0; i<n; i++){
            int w = graph.at(v).at(i);
            if((w == 0) | (dist.at(i) != -1)) continue;
            que.push(i);
            dist.at(i) = dist.at(v) + 1;
        }
    }

    for (int v = 0; v < n; ++v) cout << v << ": " << dist[v] << endl;
}