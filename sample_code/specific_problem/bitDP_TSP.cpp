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

ll V, E;
ll G[20][20];  // グラフ
ll dp[50000][20];

int main() {
    cin >> V >> E;
    // グラフの初期化
    rep(i, 20) {
        rep(j, 20) { G[i][j] = LINF; }
    }
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    // dp の初期化
    rep(i, 50000) {
        rep(j, 20) { dp[i][j] = LINF; }
    }
    dp[0][0] = 0;  // スタートを頂点 0 とする
    rep(S, 1 << V) {
        rep(v, V) {
            rep(u, V) {
                if (S != 0 && !(S & (1 << u))) continue; // u を含まない場合を除く
                if ((S & (1 << v)) == 0) {
                    if (v != u) chmin(dp[S | (1 << v)][v], dp[S][u] + G[u][v]);
                }
            }
        }
    }
    if (dp[(1 << V) - 1][0] != LINF) {
        cout << dp[(1 << V) - 1][0] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}