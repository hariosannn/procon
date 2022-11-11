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

ll calc_l(vector<V_L> &A_sum,  map<ll, ll> &color_map, ll bit_c, ll M){
    ll l = 0;
    rep(i, M){
        if(bit_c & (1<<i)){
            l += color_map[i];
        }
    }
    return l;
}

int main(){
    ll N, M;
    cin >> N >> M;
    V_L A(N);
    cin >> A;
    vector<V_L> A_sum(M, V_L(N+1, 0));
    map<ll, ll> color_num;
    rep(i, N){
        color_num[A.at(i) - 1] += 1;
    }
    rep(i, M){
        rep(j, N){
            if(A.at(j) == (i+1)) A_sum.at(i).at(j+1) = A_sum.at(i).at(j) + 1;
            else A_sum.at(i).at(j+1) = A_sum.at(i).at(j);
        }
    }

    V_L dp(1<<M, LINF);
    dp.at(0) = 0;
    rep(bit_c, 1<<M){
        rep(new_c, M){
            if(!(bit_c & (1<<new_c))){
                ll l = calc_l(A_sum, color_num, bit_c, M);
                ll r = l + color_num[new_c];
                ll diff = color_num[new_c] - (A_sum.at(new_c).at(r) - A_sum.at(new_c).at(l));
                dp.at(bit_c + (1<<new_c)) = min(dp.at(bit_c) + diff, dp.at(bit_c + (1<<new_c)));
            }
        }
    }

    cout << dp.at((1<<M)-1) << endl;
}