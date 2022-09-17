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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main(){
    ll N;
    cin >> N;
    V_L A(N), B(N);
    cin >> A;
    cin >> B;

    vector<V_L> dp(N, V_L(5000, 0));
    V_L dp_sum(5000, 0);
    for(ll i=A.at(0); i<=B.at(0); i++){
        dp.at(0).at(i) = 1;
    }

    rep(i, 5000-1){
        dp_sum.at(i+1) = dp_sum.at(i) + dp.at(0).at(i);
    }

    for(ll i=1; i<N; i++){
        for(int j=A.at(i); j<=B.at(i); j++){
            dp.at(i).at(j) = dp_sum.at(j+1);
        }
        dp_sum = V_L(5000, 0);
        rep(k, 5000-1){
            dp_sum.at(k+1) = (dp_sum.at(k) + dp.at(i).at(k))%998244353;
        }
    }
    ll ans = 0;
    rep(i, 5000){
        ans += dp.at(N-1).at(i)%998244353;
        ans %= 998244353;
    }

    cout << ans << endl;
}