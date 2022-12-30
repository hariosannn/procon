#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
using ld = long double;
using V_I = vector<int>;
using V_L = vector<ll>;
using P_I = pair<int, int>;
using P_L = pair<ll, ll>;
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


V_L color;
bool dfs(vector<V_L> &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<V_L> graph(N, V_L{});
    color.assign(N, -1);
    dsu uf(N);
    V_L alones;
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
        uf.merge(u, v);
    }
    rep(i, N){
        if(graph.at(i).size() == 0) alones.push_back(i);
    }

    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v が探索済みだったらスルー
        if (!dfs(graph, v)) is_bipartite = false;
    }
    if(!is_bipartite){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    V_L groups_size;
    ll squ = 0;
    for(auto p:uf.groups()){
        ll black_num = 0, white_num = 0;
        for(ll ind:p){
            if(color.at(ind) == 0) black_num++;
            else if(color.at(ind) == 1) white_num++;
        }
        ans += black_num*white_num;
        squ += p.size()*p.size();
    }

    ans += (N*N - squ)/2;

    cout << ans - M << endl;
}