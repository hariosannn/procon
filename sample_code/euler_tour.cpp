#include <bits/stdc++.h>
using namespace std;
//参考:https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
int inf = 1e9;

vector<vector<int>> tree = { {2,5},
                             {2},
                             {0,1,4},
                             {5},
                             {2},
                             {0,3,6},
                             {5,7},
                             {6}};

vector<int> euler_tour;
vector<int> node_num(euler_tour.size());
vector<int> edge_num(euler_tour.size());


void ET_node(int v, int parent=-1){
    // 通る頂点を記録していくオイラーツアー
    euler_tour.push_back(v+1);
    for(int next:tree.at(v)){
        if(next == parent) continue;
        ET_node(next, v);
        euler_tour.push_back(v+1);
    }
}

void ET_edge(int v, int parent=-1){
    // 通る辺を記録していくオイラーツアー
    //iの根側の辺をiとして、辺に番号をつける
    //上から下に通ったときに+i 下から上に通ったときに-i
    euler_tour.push_back(v+1);
    for(int next:tree.at(v)){
        if(next == parent) continue;
        ET_edge(next, v);
    }
    euler_tour.push_back(-v-1);
}
                             
int main(){
    ET_edge(0);
    map<int, int> node_in;
    map<int, int> node_out;

    for(int i=0; i<euler_tour.size(); i++){
        int node = euler_tour.at(i);
        if(node_in.find(node) == node_in.end()){
            if(node > 0) node_in[node] = i;
        }
    }

    for(int i=0; i<euler_tour.size(); i++){
        int node = euler_tour.at(i);
        if(node < 0) node_out[-node] = i;
    }
    cout << 1 << endl;
}