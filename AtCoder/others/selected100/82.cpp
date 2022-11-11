#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using ll = long long;
using ld = long double;
using V_I = vector<int>;
using V_L = vector<ll>;
using P_I = pair<int, int>;
#define ALL(a) (a).begin(),(a).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};
constexpr int DX2[] = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int DY2[] = {0, 1, 0, -1, 1, 1, -1, -1};
template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

struct edge{
    ll to;
    ll w;
};


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
    ll N, M, K, S, P, Q;
    cin >> N >> M >> K >> S >> P >> Q;
    set<ll> zombi_island;
    rep(i, K){
        ll z;
        cin >>z;
        z--;
        zombi_island.insert(z);
    }

    vector<V_L> graph(N, V_L{});
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    queue<ll> que;
    vector<ll> dist(N, -1); 
    for(ll z:zombi_island){
        que.push(z);
        dist.at(z) = 0;
    }

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

    vector<vector<edge>> d_graph(N, vector<edge>{});
    rep(i, N){
        for(auto next:graph.at(i)){
            if(zombi_island.find(next) != zombi_island.end()) continue;
            if(next == N-1) d_graph.at(i).push_back(edge{next, 0});
            if(dist.at(next) <= S) d_graph.at(i).push_back(edge{next, Q});
            else d_graph.at(i).push_back(edge{next, P});
        }
    }
    vector<ll> prev(N, -1);
    vector<ll> dst = dijkstra(d_graph, N, 0, N-1, LINF, prev);
    cout << dst.at(N-1) << endl;
}