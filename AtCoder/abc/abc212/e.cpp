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

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<V_L> closed_city_map(N);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        closed_city_map[u].push_back(v);
        closed_city_map[v].push_back(u);
    }

    vector<vector<ll>> dp(K+1, vector<ll>(N, 0));
    dp.at(0).at(0) = 1;
    rep(day, K){
        ll dp_sum = 0;
        rep(i, N) dp_sum += dp.at(day).at(i), dp_sum%=998244353;
        rep(city, N){
            ll tmp_add = dp_sum;
            for(ll closed_city:closed_city_map[city]){
                tmp_add -= dp.at(day).at(closed_city);
            }
            tmp_add -= dp.at(day).at(city);
            tmp_add = (tmp_add%998244353+998244353)%998244353;
            dp.at(day+1).at(city) = tmp_add;
        }
    }
    cout << dp.at(K).at(0) << endl;
}