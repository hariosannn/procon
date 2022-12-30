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
    vector<P_L> AB;
    V_L A(N);
    V_L B(N);
    cin >> A >> B;
    rep(i, N){
        AB.push_back(P_L{A.at(i), B.at(i)});
    }
    sort(AB.begin(), AB.end());

    vector<mint> dp(5001, 0);
    dp.at(0) = 1;
    mint ans = 0;
    rep(AB_i, N){
        ll a = AB.at(AB_i).first;
        ll b = AB.at(AB_i).second;
        vector<mint> tmp_dp(5001, 0);
        for(ll sum_b = 5000; sum_b >= b; sum_b--){
            tmp_dp.at(sum_b) += dp.at(sum_b - b);
            dp.at(sum_b) += dp.at(sum_b - b);
        }
        tmp_dp.at(0) = 1;
        for(ll dp_i=1; dp_i<=a; dp_i++){
            ans += tmp_dp.at(dp_i);
        }
    }
    cout << ans.val() << endl;
}
