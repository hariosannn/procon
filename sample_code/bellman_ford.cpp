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

struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};


vector<int> bellman_ford(vector<vector<int>> graph, int n, int start, int goal, int INF, vector<int> &prev){
    vector<edge> edges;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cost = graph.at(i).at(j);
            if(cost != 0){
                edges.push_back(edge{i, j, cost});
            }
        }
    }
    vector<int> dst(n, INF);
    dst.at(start) = 0;
    for(int i=0; i<n; i++){
        for(auto e: edges){
            int cur_cost = dst.at(e.to);
            int new_cost = dst.at(e.from) + e.cost;
            if(cur_cost > new_cost){
                dst.at(e.to) = new_cost;
                prev.at(e.to) = e.from;
                //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                if(i == n-1){
                    break;
                }
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
    vector<int> dst = bellman_ford(graph, n, start, goal, inf, prev);
    for(int d: dst){
        cout << d << endl;
    }

    vector<int> path = get_path(prev, start, goal);
    for(int p: path){
        cout << p << endl;
    }
}