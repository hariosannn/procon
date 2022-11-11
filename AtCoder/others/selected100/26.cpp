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
    while(true){
        ll N, M;
        cin >> N >> M;
        if((N==0) && (M==0)) break;
        V_L C(M);
        cin >> C;
        V_L X(N);
        cin >> X;

        vector<V_L> dp(N+1, V_L(256, LINF));
        dp.at(0).at(128) = 0;

        rep(i, N){
            rep(j, 256){
                rep(k, M){
                    ll next_val = j+C.at(k);
                    next_val = min(ll(255), next_val);
                    next_val = max(ll(0), next_val);

                    dp.at(i+1).at(next_val) = min(dp.at(i+1).at(next_val), 
                                                dp.at(i).at(j) + (X.at(i)-next_val)*(X.at(i)-next_val));
                }
            }
        }

        ll ans = LINF;
        rep(i, 256){
            chmin(ans, dp.at(N).at(i));
        }
        cout << ans << endl;
    }
}