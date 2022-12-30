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
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};
constexpr int DX2[] = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int DY2[] = {0, 1, 0, -1, 1, 1, -1, -1};
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}

vector<V_L> graph;
V_L child_node_sum;
V_L ans;
vector<bool> seen;  // 既に見たことがある頂点か記録
// 深さ優先探索
ll dfs(vector<V_L> &G, ll v, ll d) {
    ll partial_tree_size = 1;
    ans.at(0) += d;
    seen[v] = true;
    if((G[v].size() == 1) && (v != 0)){
        child_node_sum.at(v) = 1;
        return 1;
    }
    for (auto next : G[v]) {
        if (seen[next]) continue;
        partial_tree_size += dfs(G, next, d+1);
    }
    child_node_sum.at(v) = partial_tree_size;
    return partial_tree_size;
}

int main() {
    ll N;
    cin >> N;
    graph.assign(N, V_L{});
    child_node_sum.assign(N, 0);
    seen.assign(N, false);
    ans.assign(N, 0);
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
    }
    dfs(graph, 0, 0);

    queue<ll> que;
    que.push(0);
    vector<bool> ansed(N, false);
    ansed.at(0) = true;
    while(!que.empty()){
        ll current_v = que.front();
        que.pop();
        for(ll next:graph.at(current_v)){
            if(ansed.at(next)) continue;
            ans.at(next) = ans.at(current_v) + N - 2*child_node_sum.at(next);
            ansed.at(next) = true;
            que.push(next);
        }
    }
    
    for(ll a:ans){
        cout << a << endl;
    }
    return 0;
}
