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


struct circle{
    ll x;
    ll y;
    ll r;
    bool is_corid(circle c){
        return ((c.x - x)*(c.x - x) + (c.y - y)*(c.y - y)) < (c.r + r)*(c.r + r);
    }
};

// index が条件を満たすかどうか
bool isOK(ll r, vector<circle> C, vector<pair<ll, ll>> &new_C) {
    rep(i, new_C.size()){
        C.push_back(circle{new_C.at(i).first, new_C.at(i).second, r});
    }
    bool ret = true;
    rep(i, C.size()){
        rep(j, C.size()){
            if(i != j){
                if(C.at(i).is_corid(C.at(j))) ret = false;
            }
        }
    }
    return ret;
}

// 汎用的な二分探索のテンプレ
ll binary_search(vector<circle> &C, vector<pair<ll, ll>> &new_C) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = 0; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = 1e8; //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, C, new_C)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<circle> C;
    ll min_r = 1e10;
    rep(i, N){
        ll x, y, r;
        cin >> x >> y >> r;
        chmin(min_r, r);
        x*= 1e6;
        y*= 1e6;
        r*= 1e6;

        C.push_back(circle{x, y, r});
    }
    vector<pair<ll, ll>> new_C;
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        x*= 1e6;
        y*= 1e6;
        new_C.push_back(pair<ll, ll>{x, y});
    }
    ll ans = binary_search(C, new_C);
    if(M == 0) cout << min_r << endl;
    else cout << setprecision(10) << ans/ld(1e6) << endl;
}