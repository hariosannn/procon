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

ll min_dfs(vector<V_L> &graph, V_L &A, V_L &memo, vector<bool> &visited, ll node){
    if(visited.at(node)) return memo.at(node);
    ll ret = LINF;
    for(ll next:graph.at(node)){
        chmin(ret, A.at(next));
        if(visited.at(next)){
            chmin(ret, memo.at(next));
            continue;
        }
        ll tmp_min = min_dfs(graph, A, memo, visited, next);
        chmin(ret, tmp_min);
    }
    visited.at(node) = true;
    memo.at(node) = ret;
    return ret;
}

ll max_dfs(vector<V_L> &graph, V_L &A, V_L &memo, vector<bool> &visited, ll node){
    if(visited.at(node)) return memo.at(node);
    ll ret = -LINF;
    for(ll next:graph.at(node)){
        chmax(ret, A.at(next));
        if(visited.at(next)){
            chmax(ret, memo.at(next));
            continue;
        }
        ll tmp_max = max_dfs(graph, A, memo, visited, next);
        chmax(ret, tmp_max);
    }
    visited.at(node) = true;
    memo.at(node) = ret;
    return ret;
}

int main() {
    ll N, M;
    cin >> N >> M;
    V_L A(N);
    cin >> A;

    vector<V_L> graph(N);
    vector<V_L> reverse_graph(N);

    rep(i, M){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        graph.at(x).push_back(y);
        reverse_graph.at(y).push_back(x);
    }
    V_L max_A(N), min_A(N);
    vector<bool> visited(N, false);
    rep(i, N) max_dfs(graph, A, max_A, visited, N-i-1);
    rep(i, N) visited.at(i) = false;
    rep(i, N) min_dfs(reverse_graph, A, min_A, visited, N-i-1);
    ll ans = -LINF;
    rep(i, N) chmax(ans, A.at(i) - min_A.at(i));
    cout << ans << endl;

}