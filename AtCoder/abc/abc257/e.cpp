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

int main(){
    ll N;
    cin >> N;
    V_L C(9);
    cin >> C;

    ll min_cost = LINF;
    ll min_cost_i = -1;
    rep(i, 9){
        if(min_cost >= C.at(i)){
            min_cost = C.at(i);
            min_cost_i = i+1;
        }
    }

    ll ketasu = N/min_cost;
    V_L ans(ketasu, min_cost_i);
    N = N%min_cost;
    rep(i, ketasu){
        if(N == 0) break;
        for(ll j=8; j>=0; j--){
            if(N + C.at(ans.at(i)-1) - C.at(j) >= 0){
                N += C.at(ans.at(i)-1) - C.at(j);
                ans.at(i) = j+1;
                break;
            }
        }
    }
    for(ll a: ans){
        cout << a;
    }
    cout << endl;
}