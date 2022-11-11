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

mint iterative_square(ll n, ll a){
    // n^aを返す関数
    mint ret = 1;
    mint n_2i = n;
    while(a > 0){
        if(a & 1) ret *= n_2i;
        n_2i *= n_2i;
        a = (a >> 1);
    }
    return ret;
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    V_L A(N);
    V_L C{0};
    cin >> A;
    rep(i, Q){
        ll c;
        cin >> c;
        c--;
        C.push_back(c);
    }

    vector<mint> dist_sum(N, 0);
    rep(i, N-1){
        dist_sum.at(i+1) = dist_sum.at(i) + iterative_square(A.at(i), A.at(i+1));
    }
    mint ans = 0;
    rep(i, Q){
        ans += dist_sum.at(max(C.at(i+1), C.at(i))) - dist_sum.at(min(C.at(i+1), C.at(i)));
    }
    ans += dist_sum.at(C.at(Q)) - dist_sum.at(0);

    cout << ans.val() << endl;
}