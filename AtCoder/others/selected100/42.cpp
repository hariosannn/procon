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

ll N;
vector<V_L> dp(N+1, V_L(N+1, -1));

ll update_dp(ll l, ll r, V_L &W){
    if(dp.at(l).at(r) != -1) return dp.at(l).at(r);
    else{
        ll ret = 0;
        if((r - l) <= 1) ret = 0;
        else if((r - l == 2) ){
            if(abs(W.at(l) - W.at(r-1)) <= 1){
                ret = 2;
            }
            else ret = 0;
        }
        else{
            rep(i, (r - l)-1){
                ret = max(ret, update_dp(l, l+i+1, W) + update_dp(l+i+1, r, W));
            }
            if(dp.at(l+1).at(r-1) == r - l -2){
                if(abs(W.at(l) - W.at(r-1))<= 1) ret = max(ret,  r - l);
                else ret = max(ret,  r - l -2);
            }
        }
        dp.at(l).at(r) = ret;
        return ret;
    }
}

int main(){
    while(true){
        cin >> N;
        if(N==0) return 0;
        V_L W(N);
        cin >> W;
        vector<V_L> tmp_dp(N+1, V_L(N+1, -1));
        dp = tmp_dp;
        ll ans = update_dp(0, N, W);
        cout << ans << endl;
    }
}