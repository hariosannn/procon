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

struct dish
{
    ll to;
    ll candies;
};

int main(){
    ll N, K;
    cin >> N >> K;
    V_L A(N);
    cin >> A;

    vector<vector<dish>> doubling(40, vector<dish>(N, dish{0, 0}));
    rep(i, N){
        doubling.at(0).at(i) = dish{(i+A.at(i))%N, A.at((i+A.at(i))%N)};
    }
    for(ll i=1; i<40; i++){
        rep(j, N){
            dish prev = doubling.at(i-1).at(j);
            doubling.at(i).at(j) = dish{doubling.at(i-1).at(prev.to).to, 
                                        doubling.at(i-1).at(prev.to).candies + prev.candies};
        }
    }

    ll ans = 0;
    ll to = 0;
    K--;
    for (ll k = 0; K > 0; k++) {
        if (K & 1){
            ll tmp_to = to;
            to = doubling[k][tmp_to].to;
            ans += doubling[k][tmp_to].candies;
        }
        K = K >> 1;
    }

    cout << ans+A.at(0) << endl;
    return 0;
}
