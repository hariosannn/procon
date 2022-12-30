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

struct state
{
    ll odd_even_bits;
    ll last_node;
};
bool operator<(const state &left, const state &right) {
  // left < right の場合に true を返すように実装する
  if(left.odd_even_bits != right.odd_even_bits){
    return left.odd_even_bits < right.odd_even_bits;
  }
  else if(left.last_node != right.last_node){
    return left.last_node < right.last_node;
  }
  // ここfalseでないとsetなどで重複してしまう
  else return false;
}
int main() {
    ll N, M;
    cin >> N >> M;

    vector<V_L> graph(N+1, V_L{});
    reps(i, N) graph.at(0).push_back(i);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
    }

    queue<state> que;
    state start{0, 0};
    que.push(start);
    vector<V_L> dist(1<<N, V_L(N+1, LINF)); 
    dist.at(start.odd_even_bits).at(start.last_node) = 0;

    while(!que.empty()){
        state v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(ll next:graph.at(v.last_node)){
            // すでに訪れているなら次の探索候補に入れない
            state next_state{v.odd_even_bits ^ (1<<(next-1)), next};
            if(dist.at(next_state.odd_even_bits).at(next_state.last_node) != LINF) continue;
            que.push(next_state);
            dist.at(next_state.odd_even_bits).at(next_state.last_node) = dist.at(v.odd_even_bits).at(v.last_node) + 1;
        }
    }
    ll ans = 0;
    rep(i, 1<<N){
        if(i == 0) continue;
        ll tmp_ans = LINF;
        reps(j, N) chmin(tmp_ans, dist.at(i).at(j));
        ans += (tmp_ans);
    }
    cout << ans << endl;
}