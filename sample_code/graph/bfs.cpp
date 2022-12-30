#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll LINF = 1001001001001001001ll;

vector<vector<ll>> graph = { {1, 3},
                             {0, 2, 6},
                             {1, 3, 5, 6},
                             {0, 2, 4},
                             {3, 5},
                             {2, 4, 6},
                             {1, 2, 5} };

                             

int main(){
    queue<ll> que;
    ll start = 0;
    que.push(start);
    ll n = graph.size();
    vector<ll> dist(n, -1); 
    dist.at(start) = 0;

    while(!que.empty()){
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(ll next:graph.at(v)){
            // すでに訪れているなら次の探索候補に入れない
            if(dist.at(next) != -1) continue;
            que.push(next);
            dist.at(next) = dist.at(v) + 1;
        }
    }

    for (ll v = 0; v < n; ++v) cout << v << ": " << dist[v] << endl;
}