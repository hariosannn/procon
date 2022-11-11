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
    ll N;
    cin >> N;
    V_L A(N);
    cin >> A;

    vector<V_L> dp(N, V_L(N, -LINF));

    rep(i, N){
        dp.at(i).at((i+N-2)%N) = A.at((i+N-1)%N);
    }

    bool my_turn = false;
    for(ll offset = N-3; offset >= 0; offset--){
        rep(l, N){
            ll r = (l + offset)%N;
            if(my_turn){
                dp.at(l).at(r) = max(dp.at(l).at((r+1)%N) + A.at((r+1)%N),
                                     dp.at(((l-1)%N+N)%N).at(r) + A.at(((l-1)%N+N)%N));
            }
            else{
                if(A.at(r) < A.at(((l-1)%N+N)%N)){
                    dp.at(l).at(r) = max(dp.at(l).at(r), dp.at(((l-1)%N+N)%N).at(r));
                }
                if(A.at(l) < A.at((r+1)%N)){
                    dp.at(l).at(r) = max(dp.at(l).at(r), dp.at(l).at((r+1)%N));
                }
            }
        }
        my_turn = !my_turn;
    }
    ll ans = 0;
    rep(i, N){
        if(my_turn)
            chmax(ans, dp.at(i).at(i) + A.at(i));
        else chmax(ans, dp.at(i).at(i));
    }
    cout << ans << endl;
}