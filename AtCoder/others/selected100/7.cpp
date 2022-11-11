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

bool is_full_light(V_L &S, map<ll, set<ll>> switch_to_l, V_L &P, ll M){
    V_L on_num(M, 0);
    for(ll s:S){
        for(ll light:switch_to_l[s]){
            on_num.at(light) += 1;
        }
    }

    bool ret = true;
    rep(i, M){
        if(on_num.at(i) % 2 != P.at(i)) ret = false;
    }
    return ret;
}

int main(){
    ll N, M;
    cin >> N >> M;

    map<ll, set<ll>> switch_to_l;
    rep(i, M){
        ll k;
        cin >> k;
        V_L tmp(k);
        cin >> tmp;
        for(ll sw:tmp){
            switch_to_l[sw-1].insert(i);
        }
    }

    V_L P(M);
    cin >> P;

    ll ans = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (ll bit = 0; bit < (1<<N); ++bit) {
        vector<ll> S;
        for (ll i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        if(is_full_light(S, switch_to_l, P, M)){
            ans ++;
        }
    }
    cout << ans << endl;
}