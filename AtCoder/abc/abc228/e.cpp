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

ll iterative_square(ll n, ll a, ll P){
    // n^aを返す関数
    ll ret = 1;
    ll n_2i = n%(P-1);
    while(a > 0){
        if(a & 1) ret *= n_2i;
        n_2i *= n_2i;
        a = (a >> 1);
        
        n_2i %= P-1;
        ret %= P-1;
    }
    return ret;
}

mint iterative_square_mod(ll n, ll a){
    // n^aを返す関数
    mint ret = 1;
    mint n_2i = n;
    while(a > 0){
        if(a & 1) ret *= n_2i;
        n_2i *= n_2i;
        a = (a >> 1);
    }
    return ret;
}

int main(){
    ll N, K, M;
    cin >> N >> K >> M;
    if(M%998244353 == 0){
        cout << 0 << endl;
        return 0;
    }
    ll POW_K_N = iterative_square(K, N, 998244353);
    mint ans = iterative_square_mod(M, POW_K_N);
    cout << ans.val() << endl;


}