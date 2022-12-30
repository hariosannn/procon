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

ll calc_sum(ll n, ll first, ll d){
    return (n*(2*first+(n-1)*d))/2;
}

ll solve(vector<P_L> &A){
    ll cumsum = 0;
    ll cum_cumsum = 0;
    ll ans = A.at(0).first;
    rep(i, A.size()){
        ll cumsum_first = cumsum + A.at(i).first;
        if((cumsum >= 0) && (A.at(i).first < 0)){
            ll cumsum_reverse_ind;
            cumsum_reverse_ind = cumsum/(-A.at(i).first) + 1;
            rep(add, 10){
                ll new_n = cumsum_reverse_ind-5+add;
                chmax(new_n, 1);
                chmin(new_n, A.at(i).second);
                chmax(ans, cum_cumsum + calc_sum(new_n, cumsum_first, A.at(i).first));
            }
        }
        cumsum += A.at(i).first*A.at(i).second;
        cum_cumsum += calc_sum(A.at(i).second, cumsum_first, A.at(i).first);
        chmax(ans, cum_cumsum);
    }
    return ans;
}

int main() {
    ll T;
    cin >> T;
    rep(t, T) {
        ll N, M;
        cin >> N >> M;
        vector<P_L> A(N);
        rep(i, N) {
            ll x, y;
            cin >> x >> y;
            A.at(i).first = x, A.at(i).second = y;
        }
        ll ans = solve(A);
        cout << ans << endl;
    }
}