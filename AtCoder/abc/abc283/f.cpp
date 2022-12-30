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

bool is_isolate(vector<V_L> &A){
    ll W = A.at(0).size();
    bool ret = false;

    rep(j, W){
        if((j == 0)){
            if((A.at(1).at(j) != A.at(0).at(j)) && 
               (A.at(1).at(j) != A.at(2).at(j)) && 
               (A.at(1).at(j) != A.at(1).at(j+1))) ret = true;
        }
        else if(j == W-1){
            if((A.at(1).at(j) != A.at(0).at(j)) && 
               (A.at(1).at(j) != A.at(2).at(j)) && 
               (A.at(1).at(j) != A.at(1).at(j-1))) ret = true;
        }
        else{
            if((A.at(1).at(j) != A.at(0).at(j)) && 
               (A.at(1).at(j) != A.at(2).at(j)) && 
               (A.at(1).at(j) != A.at(1).at(j+1)) && 
               (A.at(1).at(j) != A.at(1).at(j-1)))ret = true;
        }
    }
    return ret;
}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<V_L> A(1, V_L(W, LINF));
    rep(i, H){
        V_L tmp(W);
        cin >> tmp;
        A.push_back(tmp);
    }
    A.push_back(V_L(W, LINF));

    vector<vector<V_L>> dp(H+1, vector<V_L>(2, V_L(2, LINF)));
    rep(i, 2) rep(j, 2) dp.at(0).at(i).at(j) = 0;

    reps(i, H){
        vector<V_L> tmp_A{A.at(i-1), A.at(i), A.at(i+1)};
        vector<V_L> tmp_A_flip = tmp_A;
        rep(j, 3){
            rep(k, W) tmp_A_flip.at(j).at(k) = 1 - tmp_A_flip.at(j).at(k);
        }
        for(ll flip_2=0; flip_2<2; flip_2++){
            for(ll flip_1=0; flip_1<2; flip_1++){
                for(ll flip_0=0; flip_0<2; flip_0++){
                    V_L A2 = tmp_A.at(2), A1 = tmp_A.at(1), A0 = tmp_A.at(0);
                    if(flip_0) A0 = tmp_A_flip.at(0);
                    if(flip_1) A1 = tmp_A_flip.at(1);
                    if(flip_2) A2 = tmp_A_flip.at(2);
                    vector<V_L> check_A{A0, A1, A2};
                    if(!is_isolate(check_A)){
                        if(flip_0) chmin(dp.at(i).at(flip_1).at(flip_0), dp.at(i-1).at(flip_2).at(flip_1) + 1);
                        else chmin(dp.at(i).at(flip_1).at(flip_0), dp.at(i-1).at(flip_2).at(flip_1));
                    }
                }
            }
        }
    }
    ll ans = LINF;
    rep(i, 2){
        rep(j, 2) chmin(ans, dp.at(H).at(i).at(j));
    }
    if(ans >= LINF/2) cout << -1 << endl;
    else cout << ans << endl;
}