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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main(){
    ll N;
    cin >> N;
    vector<V_L> sunuke(1e6+3, V_L(5, 0));
    rep(i, N){
        ll t,x,a;
        cin >> t >> x >> a;
        sunuke.at(t).at(x) = a;
    }
    vector<V_L> dp(1e6+3, V_L(5, -LINF));
    dp.at(0) = {0, -LINF, -LINF, -LINF, -LINF};
    rep(i, 1e6+2){
        rep(j, 5){
            ll tmp_a = sunuke.at(i+1).at(j);
            dp.at(i+1).at(j) = max(max(dp.at(i).at(max(0, j-1))+tmp_a, dp.at(i).at(j)+tmp_a), dp.at(i).at(min(4, j+1))+tmp_a);
        }
    }
    ll ans = 0;
    rep(i, 5){
        ans = max(ans, dp.at(1e6+2).at(i));
    }
    cout << ans << endl;
}