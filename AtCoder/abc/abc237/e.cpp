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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    ll N, M;
    cin >> N >> M;
    V_L P(N);
    cin >> P;
    vector<vector<edge>> graph(N, vector<edge>{});
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if(P.at(u) >= P.at(v)){
            graph.at(u).push_back(edge{v, 0});
            graph.at(v).push_back(edge{u, P.at(u) - P.at(v)});
        }
        else{
            graph.at(u).push_back(edge{v, P.at(v) - P.at(u)});
            graph.at(v).push_back(edge{u, 0});
        }
    }
    vector<ll> prev(N, -1);
    ll start = 0;
    ll goal = -1;
    vector<ll> dst = dijkstra(graph, N, start, goal, LINF, prev);
    ll ans = 0;
    rep(i, N){
        ll tmp_ans = -(dst.at(i) + P.at(i) - P.at(0));
        chmax(ans, tmp_ans);
    }

    cout << ans << endl;
}
