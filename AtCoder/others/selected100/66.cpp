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
    ll R, C;
    cin >> R >> C;
    vector<V_L> senbei;
    rep(i, R){
        V_L tmp(C);
        cin >> tmp;
        senbei.push_back(tmp);
    }

    ll ans = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<R); ++bit) {
        vector<bool> ret(R, false);
        for (int i = 0; i < R; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                ret.at(i) = true;
            }
        }

        ll tmp_ans = 0;
        rep(c, C){
            ll front_n = 0;
            ll back_n = R;
            rep(r, R){
                if(ret.at(r)){
                    if(senbei.at(r).at(c) == 0) front_n++;
                }
                else{
                    if(senbei.at(r).at(c) == 1) front_n++;
                }
            }
            back_n -= front_n;
            tmp_ans += max(back_n, front_n);
        }
        chmax(ans, tmp_ans);
    }
    cout << ans << endl;
}