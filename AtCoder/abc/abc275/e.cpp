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

int main(){
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<modint998244353>> dp(K+1, vector<modint998244353>(N+1, 0));
    dp.at(0).at(0) = 1;
    rep(turn, K){
        rep(place, N){
            rep(add, M){
                if(place + add + 1 < N){
                    dp.at(turn + 1).at(place + add + 1) += dp.at(turn).at(place)/M;
                }
                else{
                    dp.at(turn + 1).at(2*(N) -(place + add + 1) ) += dp.at(turn).at(place)/M;
                }
            }
        }
    }

    modint998244353 ans = 0;
    rep(i, K+1){
        ans += dp.at(i).at(N);
    }

    cout << ans.val() << endl;
}