#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using V_I = vector<int>;
using V_L = vector<ll>;
using P_I = pair<int, int>;
using P_L = pair<ll, ll>;
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

int main(){
    V_L tetra;
    rep(i, 200){
        tetra.push_back((i+1)*(i+2)*(i+3)/6);
    }
    V_L odd_tetra;
    for(ll t:tetra){
        if(t%2==1) odd_tetra.push_back(t);
    }
    ll N = 1000001;
    V_L dp(N+1, LINF);
    dp.at(0) = 0;
    rep(i, tetra.size()){
        if(tetra.at(i) > N) break;
        rep(j, N+1){
            if(j - tetra.at(i) >= 0) dp.at(j) = min(dp.at(j - tetra.at(i)) + 1, dp.at(j));
            else dp.at(j) = dp.at(j);
        }
    }

    V_L odd_dp(N+1, LINF);
    odd_dp.at(0) = 0;
    rep(i, odd_tetra.size()){
        if(odd_tetra.at(i) > N) break;
        rep(j, N+1){
            if(j - odd_tetra.at(i) >= 0) odd_dp.at(j) = min(odd_dp.at(j - odd_tetra.at(i)) + 1, odd_dp.at(j));
            else odd_dp.at(j) = odd_dp.at(j);
        }
    }

    while(true){
        ll tmp_N;
        cin >> tmp_N;
        if(tmp_N==0) break;
        cout << dp.at(tmp_N) << " " << odd_dp.at(tmp_N) << endl;
    }
}