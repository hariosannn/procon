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

mint combination(vector<mint> &n_fac, ll n, ll r) {
    return n_fac.at(n) / (n_fac.at(r) * n_fac.at(n - r));
}

int main() {
    string S;
    cin >> S;
    map<char, ll> char_num;
    for (char c : S) {
        char_num[c] += 1;
    }
    vector<mint> n_fac(S.size() + 1, 1);
    rep(i, S.size()) { n_fac.at(i + 1) = n_fac.at(i) * (i + 1); }

    vector<vector<mint>> dp(char_num.size() + 1, vector<mint>(S.size() + 1, 0));
    dp.at(0).at(0) = 1;
    ll c_ind = 0;
    ll max_len = 0;
    for (auto c_and_n : char_num) {
        ll char_num = c_and_n.second;
        rep(length, max_len + 1) {
            rep(add_n, char_num + 1) {
                dp.at(c_ind + 1).at(length + add_n) +=
                    combination(n_fac, length + add_n, add_n) *
                    dp.at(c_ind).at(length);
            }
        }
        c_ind++;
        max_len += char_num;
    }

    mint ans = 0;
    rep(j, S.size()) { ans += dp.at(char_num.size()).at(j + 1); }

    cout << ans.val() << endl;
}