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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

bool is_sign(vector<P_L> sign, set<P_L> &stars, ll x_diff, ll y_diff){
    bool ret = true;
    rep(i, sign.size()){
        sign.at(i) = P_L{sign.at(i).first + x_diff, sign.at(i).second + y_diff};
    }
    for(auto p:sign){
        if(stars.find(p) == stars.end()) ret = false;
    }
    return ret;
}

ll doubling(ll a, ll b){
    ll ret = 1;
    ll double_a = a;
    while(b > 0){
        if(b & 1){
            ret *= double_a;
            ret %= 1000000007;
        }
        double_a *= double_a;
        double_a %= 1000000007;
        b = (b >> 1);
    }
    return ret;
}

int main(){
    ll M, N;
    cin >> M >> N;
    cout << doubling(M, N) << endl;
}