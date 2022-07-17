#include <bits/stdc++.h>
using namespace std;

int inf = 1e9;

vector<vector<int>> ad_mat = {{0, 1, 0, 1, 0, 0},
                             {0, 0, 0, 0, 1, 0},
                             {0, 1, 0, 0, 1, 0},
                             {0, 0, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 1},
                             {0, 0, 0, 0, 0, 0}};

struct Edge {
    int to;
};

using Graph = vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G) {  // bfs
    //トポロジカルソートをする関数　帰り値が全ノードより短かったらDAGでない
    vector<int> ans;
    int n = G.size();
    vector<int> ind(n);  // ind[i]: 頂点iに入る辺の数(次数)
    for(auto vec_e: G){
        for(auto e: vec_e){
            ind.at(e.to) ++;
        }
    }

    queue<int> que;
    for(int i=0; i<n; i++){  // 次数が0の点をキューに入れる
        if(ind.at(i) == 0){
            que.push(i);
        }
    }

    while (!que.empty()) {  // 幅優先探索
        int now = que.front();
        que.pop();
        ans.push_back(now);
        vector<Edge> now_vec_e = G.at(now);
        for(auto e: now_vec_e){
            ind.at(e.to)--;
            if(ind.at(e.to) == 0){
                que.push(e.to);
            }
        }
    }
    return ans;
}

int main(){
    int graph_n = ad_mat.size();
    Graph graph;
    for(int i=0; i<graph_n; i++){
        vector<Edge> tmp_vec_e;
        for(int j=0; j<graph_n; j++){
            if(ad_mat.at(i).at(j) == 1){
                tmp_vec_e.push_back(Edge{j});
            }
        }
        graph.push_back(tmp_vec_e);
    }

    vector<int> ans = topo_sort(graph);
    for(auto e: ans){
        cout << e << endl;
    }
}