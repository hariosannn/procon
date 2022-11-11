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

int main(){
    ll D, N;
    cin >> D >> N;

    V_L T(D);
    cin >> T;

    map<ll, set<ll>> temp_c_map;
    rep(i, N){
        ll a, b, c;
        cin >> a >> b >> c;
        for(ll t=a; t<=b; t++){
            temp_c_map[t].insert(c);
        }
    }

    vector<V_L> dp(D, V_L(101, -1));
    for(ll c:temp_c_map[T.at(0)]){
        dp.at(0).at(c) = 0;
    }
    for(ll d=0; d<D-1; d++){
        rep(c, 101){
            if(dp.at(d).at(c) == -1) continue;
            for(ll next_c:temp_c_map[T.at(d+1)]){
                dp.at(d+1).at(next_c) = max(dp.at(d+1).at(next_c), dp.at(d).at(c) + abs(c-next_c));
            }
        }
    }
    ll ans = 0;
    for(ll a:dp.at(D-1)){
        chmax(ans, a);
    }
    cout << ans << endl;
}