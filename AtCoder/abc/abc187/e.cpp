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
#define reps(i, x) for (ll i = 1; i <= (ll)(x); i++)
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


// 深さ優先探索
vector<bool> seen;  // 既に見たことがある頂点か記録
void dfs(vector<V_L> &G, int v, vector<bool> &visited, V_L &imos, ll add_num, V_L &ans) {
    visited[v] = true;
    add_num += imos.at(v);
    ans.at(v) = add_num;
    for (auto next : G[v]) {
        if (!visited[next]) {  // 訪問済みでなければ探索
            dfs(G, next, visited, imos, add_num, ans);
        }
    }
    return;
}

int main() {
    ll N;
    cin >> N;

    vector<P_L> edges;
    vector<V_L> tree(N, V_L{});
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
        edges.push_back(P_L{a, b});
    }

    queue<ll> que;
    ll start = 0;
    que.push(start);
    vector<ll> dist(N, -1); 
    dist.at(start) = 0;

    while(!que.empty()){
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(ll next:tree.at(v)){
            // すでに訪れているなら次の探索候補に入れない
            if(dist.at(next) != -1) continue;
            que.push(next);
            dist.at(next) = dist.at(v) + 1;
        }
    }

    V_L imos(N, 0);
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll t, e, x;
        cin >> t >> e >> x;
        e--;
        P_L edge = edges.at(e);
        ll ok_node, ng_node;
        if(t == 1){
            ok_node = edge.first;
            ng_node = edge.second;
        }
        else{
            ok_node = edge.second;
            ng_node = edge.first;
        }
        if(dist.at(ok_node) < dist.at(ng_node)){
            imos.at(0) += x;
            imos.at(ng_node) -= x;
        }
        else{
            imos.at(ok_node) += x;
        }
    }

    vector<bool> visited(N, false);
    V_L ans(N, 0);
    dfs(tree, 0, visited, imos, 0, ans);
    for(ll a:ans){
        cout << a << endl;
    }
}