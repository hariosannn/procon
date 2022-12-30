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

int main() {
    ll N;
    cin >> N;
    V_L A(N);
    cin >> A;

    V_L A_squ;
    ll sum_A = 0;
    ll sum_A_squ = 0;
    rep(i, N){
        sum_A += A.at(i);
        A_squ.push_back(A.at(i)*A.at(i));
        sum_A_squ += A.at(i)*A.at(i);
    }

    V_L cumsum_A_squ{0};
    rep(i, N){
        cumsum_A_squ.push_back(cumsum_A_squ.back() + A_squ.at(i));
    }

    ll ans = 0;
    reps(i, N-1){
        ans += i*A_squ.at(i);
    }

    reps(i, N-1){
        ans += cumsum_A_squ.at(i);
    }

    ll minus_num = sum_A*sum_A - sum_A_squ;
    ans -= minus_num;
    cout << ans << endl;
}