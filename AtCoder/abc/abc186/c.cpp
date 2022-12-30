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

ll iterative_square(ll n, ll a){
    // n^aを返す関数
    ll ret = 1;
    ll n_2i = n;
    while(a > 0){
        if(a & 1) ret *= n_2i;
        n_2i *= n_2i;
        a = (a >> 1);
    }
    return ret;
}

bool is_cointain_7(ll N){
    bool ret = false;
    while(N>0){
        if(N%10 == 7) ret = true;
        N/=10;
    }
    return ret;
}

bool is_cointain_7_8(ll N){
    bool ret = false;
    while(N>0){
        if(N%8 == 7) ret = true;
        N/=8;
    }
    return ret;
}

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    reps(i, N){
        if(!is_cointain_7(i) && !is_cointain_7_8(i)) ans++;
    }
    cout << ans << endl;
}