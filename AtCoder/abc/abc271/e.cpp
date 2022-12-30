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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

struct edge
{
    ll a, b, c;
};

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<edge> edges;
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back(edge{a, b, c});
    }
    V_L E(K);
    cin >> E;
    rep(i, K){
        E.at(i) --;
    }

    V_L dp(N, LINF);
    dp.at(0) = 0;
    for(ll e_ind:E){
        ll a, b, c;
        a = edges.at(e_ind).a;
        b = edges.at(e_ind).b;
        c = edges.at(e_ind).c;
        dp.at(b) = min(dp.at(b), dp.at(a) + c);
    }
    if(dp.at(N-1) == LINF) cout << -1 << endl;
    else cout << dp.at(N-1) << endl;
}