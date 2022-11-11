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

// index が条件を満たすかどうか
bool isOK(ll index, ll key, vector<ll> &a) {
    if (a[index] <= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key, vector<ll> &a) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = -1; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = (ll)a.size(); //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    ll N, M;
    cin >> N >> M;
    V_L P(N);
    cin >> P;
    V_L P_P;
    rep(i, N){
        rep(j, N){
            P_P.push_back(P.at(i)+P.at(j));
        }
    }
    sort(P.begin(), P.end());
    sort(P_P.begin(), P_P.end());
    ll ans = 0;
    //1回だけ投げる
    ll ans_ind = binary_search(M, P);
    if((ans_ind >= 0) && (ans_ind < N)) chmax(ans, P.at(ans_ind));
    //2回だけ投げる
    if(N>=2){
        ll ans_ind = binary_search(M, P_P);
        if((ans_ind >= 0) && (ans_ind < N*N)) chmax(ans, P_P.at(ans_ind));
    }
    //3回だけ投げる
    if(N>=3){
        rep(i, N){
            ll one_point = P.at(i);
            ll ans_ind = binary_search(M-one_point, P_P);
            if((ans_ind >= 0) && (ans_ind < N*N)){
                ll tmp_ans = one_point + P_P.at(ans_ind);
                chmax(ans, tmp_ans);
            }
        }
    }
    //4回だけ投げる
    if(N>=4){
        rep(i, N*N){
            ll two_point = P_P.at(i);
            ll ans_ind = binary_search(M-two_point, P_P);
            if((ans_ind >= 0) && (ans_ind < N*N)){
                ll tmp_ans = two_point + P_P.at(ans_ind);
                chmax(ans, tmp_ans);
            }
        }
    }

    cout << ans << endl;
}