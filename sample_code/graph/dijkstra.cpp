#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll LINF = 1001001001001001001ll;

struct edge{
    ll to;
    ll w;
};
vector<vector<edge>> graph = {{edge{1,5}, edge{3,10}},
                              {edge{0,5}, edge{2,3}, edge{6,2}},
                              {edge{1,3}, edge{3,1}, edge{5,8}, edge{6,9}},
                              {edge{0,10}, edge{2,1}, edge{4,6}},
                              {edge{3,6}, edge{5,4}},
                              {edge{2,8}, edge{4,4}, edge{6,6}},
                              {edge{1,2}, edge{2,9}, edge{5,6}}};

//1要素目に暫定の距離、2要素目にノード番号を格納するpair
typedef pair<ll, ll> P;

vector<ll> dijkstra(vector<vector<edge>> graph, ll n, ll start, ll goal, ll INF, vector<ll> &prev){
    priority_queue<P, vector<P>, greater<P>> que;
    vector<ll> dst(n, INF);
    dst.at(start) = 0;
    que.push(P(0, start));
    while(!que.empty()){
        ll d = que.top().first;
        ll current_node = que.top().second;
        que.pop();
        //全部探索するなら下の行をコメントアウト
        //if(current_node == goal) return dst;
        //queの中には過去追加した最短ではない距離のデータも入っており、それが来たらスルー
        if(dst.at(current_node) < d) continue;
        for(edge next: graph.at(current_node)){
            //現在のノードと次のノードのgraphがつながっており、dst[next_node]が更新できる場合
            //dst[next_node]を更新し、queにそのデータを追加
            if(dst.at(next.to) > d + next.w){
                    dst.at(next.to) = d + next.w;
                    que.push(P(dst.at(next.to), next.to));
                    prev.at(next.to) = current_node;
                }
        }
    }
    return dst;
}                  

vector<ll> get_path(vector<ll> prev,ll start, ll goal){
    vector<ll> path;
    for(ll t=goal;t != -1;t = prev[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    ll n = graph.size();
    ll start = 0, goal = 5;
    vector<ll> prev(n, -1);
    vector<ll> dst = dijkstra(graph, n, start, goal, LINF, prev);
    for(ll d: dst){
        cout << d << endl;
    }

    vector<ll> path = get_path(prev, start, goal);
    cout << "path is" << endl;
    for(ll p: path){
        cout << p << endl;
    }
}