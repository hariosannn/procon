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

V_L M_to_nadic(ll M, ll n){
    V_L ret;
    while(M > 0){
        ret.push_back(M%n);
        M /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// index が条件を満たすかどうか
bool isOK(ll n, ll M, string X) {
    V_L M_string = M_to_nadic(M, n);
    if(M_string.size() < X.size()) return false;
    else if(M_string.size() > X.size()) return true;
    else{
        bool ret = true;
        rep(i, X.size()){
            if(M_string.at(i) < (X.at(i) - '0')){
                ret = false;
                break;
            }
            else if(M_string.at(i) > (X.at(i) - '0')){
                ret = true;
                break;
            }
        }
        return ret;
    }
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll min_n, ll max_n, ll M, string X) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = min_n-1; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = max_n+1; //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, M, X)) ok = mid;
        else ng = mid;
    }
    return ok;
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

int main(){
    string X;
    cin >> X;
    ll M;
    cin >> M;
    if(X.size() == 1){
        if((X.at(0)- '0') <= M){
            cout << 1 << endl;
            return 0;
        }
        else {
            cout << 0 << endl;
            return 0;
        }
    }
    ll min_n = 0;
    for(char c:X){
        chmax(min_n, c-'0');
    }
    min_n++;
    //cout << M_to_nadic(120, 2) << endl;
    //ll max_n = pow(2.0, 18.5*log2(10.0)/(max(ll(1), ll(X.size()-1))));
    ll max_n = 1000000000000000000;
    //max_n = 14;
    ll ans = binary_search(min_n, max_n, M, X);
    cout << max(ll(0), ans - min_n + 1) << endl;
}