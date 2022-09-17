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
 
int main()
{
    ll N, M;
    cin >> N >> M;
    V_L A(N);
    cin >> A;
    vector<V_L> dp(N+1, V_L(M+1, -LINF));
    rep(i, N+1){
        dp.at(i).at(0) = 0;
    }
    dp.at(0).at(1) = A.at(0);
    for(ll i=1; i<N; i++){
        for(ll j=1; j<=M; j++){
            dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-1).at(j-1) + (j)*A.at(i));
        }
    }
    ll ans = -LINF;
    rep(i, N+1){
        ans = max(dp.at(i).at(M), ans);
    }
    cout << ans << endl;
}
 