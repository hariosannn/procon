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
                             
void warshall_floyd(int n, vector<vector<int>> &wf_graph, vector<vector<int>> &next){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int d_via_ks = wf_graph.at(i).at(k) + wf_graph.at(k).at(j); 
                if(d_via_ks < wf_graph.at(i).at(j)){
                    wf_graph.at(i).at(j) = d_via_ks;
                    next.at(i).at(j) = next.at(i).at(k);
                }
            }
        }
    }
}

void printPath(int start, int goal,vector<vector<int>> &next) {
    for (int cur = start; cur != goal; cur = next[cur][goal])
        printf("%d ", cur+1);
    printf("%d\n", goal+1);
}

int main(){
    vector<vector<int>> wf_graph = graph;
    int n = wf_graph.size();
    for(int i=0; i<wf_graph.size(); i++){
        for(int j=0; j<wf_graph.at(i).size(); j++){
            if((wf_graph.at(i).at(j) == 0) && (i != j)){
                wf_graph.at(i).at(j) = inf;
            }
        }
    }
    vector<vector<int>> next(7);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            next.at(i).push_back(j);
        }
    }

    warshall_floyd(n, wf_graph, next);
    int start = 4-1, end = 7-1;

    printPath(start, end, next);
}