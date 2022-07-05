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

//1要素目に暫定の距離、2要素目にノード番号を格納するpair
typedef pair<int, int> P;

vector<int> dijkstra(vector<vector<int>> graph, int n, int start, int goal, int INF, vector<int> &prev){
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> dst(n, INF);
    dst.at(start) = 0;
    que.push(P(0, start));
    while(!que.empty()){
        int d = que.top().first;
        int current_node = que.top().second;
        que.pop();
        //全部探索するなら下の行をコメントアウト
        //if(current_node == goal) return dst;
        //queの中には過去追加した最短ではない距離のデータも入っており、それが来たらスルー
        if(dst.at(current_node) < d) continue;
        for(int next_node=0; next_node<n; next_node++){
            //現在のノードと次のノードのgraphがつながっており、dst[next_node]が更新できる場合
            //dst[next_node]を更新し、queにそのデータを追加
            if(graph.at(current_node).at(next_node) > 0 && 
                dst.at(next_node) > d + graph.at(current_node).at(next_node)){
                    dst.at(next_node) = d + graph.at(current_node).at(next_node);
                    que.push(P(dst.at(next_node), next_node));
                    prev.at(next_node) = current_node;
                }
        }
    }
    return dst;
}                  

vector<int> get_path(vector<int> prev,int start, int goal){
    vector<int> path;
    for(int t=goal;t != -1;t = prev[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int n = graph.size();
    int start = 0, goal = 5;
    vector<int> prev(n, -1);
    vector<int> dst = dijkstra(graph, n, start, goal, inf, prev);
    for(int d: dst){
        cout << d << endl;
    }

    vector<int> path = get_path(prev, start, goal);
    for(int p: path){
        cout << p << endl;
    }
}