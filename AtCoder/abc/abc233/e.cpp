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

// index が条件を満たすかどうか
bool isOK(int index, int key, vector<pair<ll, ll>> &a) {
    if (a.at(index).first > key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<pair<ll, ll>> &a) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    int ok = (int)a.size(); //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(int)a.size()
    int ng = -1; //ng以上から右端が条件を必ず満たさないような場合(int)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(){
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> walls;
    rep(i, N){
        ll l, r;
        cin >> l >> r;
        walls.push_back(pair<ll, ll>{l, r});
    }

    sort(walls.begin(), walls.end());

    ll ans = 0;
    for(int i=0; i<N;){
        ll next_r = walls.at(i).second;
        ll next_l = next_r+D-1;
        i = binary_search(next_l, walls);
        ans++;
    }

    cout << ans<< endl;
}