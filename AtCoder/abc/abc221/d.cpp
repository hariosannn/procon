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

struct bento
{
    ll a;
    ll b;
};


int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<bento> B;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        B.push_back(bento{a, b});
    }

    vector<vector<V_L>> dp(N+1, vector<V_L>(301, V_L(301, LINF)));
    dp.at(0).at(B.at(0).a).at(B.at(0).b) = 1;
    for(ll i=1; i<N; i++){
        bento tmp_bento = B.at(i);
        ll tmp_a = tmp_bento.a;
        ll tmp_b = tmp_bento.b;
        rep(j, 300){
            rep(k, 300){
                dp.at(i+1).at(min(j + tmp_a, ll(300))).at(min(k + tmp_b, ll(300))) = min(dp.at(i).at(min(j + tmp_a, ll(300))).at(min(k + tmp_b, ll(300))), dp.at(i).at(j).at(k) + 1);
            }
        }
    }

    ll ans = LINF;
    rep(i, 301){
        rep(j, 301){
            ans = min(ans, dp.at(N).at(i).at(j));
        }
    }
    if (ans == LINF) cout << -1 << endl;
    else cout << ans << endl;
}