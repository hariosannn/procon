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

struct train
{
    ll ticket;
    ll ic_fare;
    ll ic_card;
};

int main(){
    ll N, M;
    cin >> N >> M;
    V_L trip(M);
    cin >> trip;
    vector<train> T;
    rep(i, N-1){
        ll a, b, c;
        cin >> a >> b >> c;
        T.push_back(train{a, b, c});
    }

    V_L ride_num(N, 0);
    ll prev_station = trip.at(0);
    for(ll i=1; i<M; i++){
        ll next_station = trip.at(i);
        ride_num.at(min(prev_station, next_station) -1) += 1;
        ride_num.at(max(prev_station, next_station) -1) += -1;
        prev_station = next_station;
    }
    rep(i, N-1){
        ride_num.at(i+1) = ride_num.at(i+1) + ride_num.at(i);
    }

    ll ans = 0;
    rep(i, N-1){
        ll rn = ride_num.at(i);
        train tr = T.at(i);
        if(tr.ticket*rn >= (tr.ic_card + tr.ic_fare*rn)){
            ans += tr.ic_card + tr.ic_fare*rn;
        }
        else{
            ans += tr.ticket*rn;
        }
    }
    cout << ans << endl;
    return 0;
}