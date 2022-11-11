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
    ll N, M;
    cin >> N >> M;
    vector<V_L> nails(N+2, V_L(N+2, 0));
    rep(i, M){
        ll a,b,x;
        cin >> a >> b >> x;
        a--;
        b--;
        nails.at(a).at(b) += 1;
        nails.at(a).at(b+1) += -1;
        nails.at(a+x+1).at(b) += -1;
        nails.at(a+x+2).at(b+1) += 1;
        nails.at(a+x+2).at(b+x+2) += -1;
        nails.at(a+x+1).at(b+x+2) += 1;
    }

    vector<V_L> nails_sum(N+2, V_L(N+2, 0));
    rep(i, N+2){
        rep(j, N+1){
            nails.at(i).at(j+1) = nails.at(i).at(j+1) + nails.at(i).at(j);
        }
    }
    rep(i, N+2){
        rep(j, N+1){
            nails.at(j+1).at(i) = nails.at(j+1).at(i) + nails.at(j).at(i);        
        }
    }
    rep(i, N+2){
        rep(j, N+2-i-1){
            nails.at(i+j+1).at(j+1) = nails.at(i+j+1).at(j+1) + nails.at(i+j).at(j);
        }
    }

    ll ans = 0;
    rep(i, N){
        rep(j, N){
            if(nails.at(i).at(j) > 0) ans++;
        }
    }
    cout << ans << endl;
}