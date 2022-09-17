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

vector<pair<ll, ll>> calc_run_length(V_L &a){
    vector<pair<ll, ll>> ret;
    ll j=0;
    for(ll i=0; i<(ll)a.size();){
        ll tmp_val = a.at(i);
        while((j != (ll)a.size()) && (a.at(i) == a.at(j))){
            j++;
        }
        ret.push_back(pair<ll, ll>{tmp_val, j-i});
        i = j;
    }
    return ret;
}


int main(){
    ll N;
    cin >> N;
    V_L A(N);
    cin >> A;
    sort(A.begin(), A.end());
    vector<pair<ll, ll>> run_length = calc_run_length(A);

    vector<V_L> dp(run_length.size()+1, V_L(4, 0));
    rep(i, dp.size()){
        dp.at(i).at(0) = 1;
    }

    rep(i, run_length.size()){
        for(ll j=1; j<4; j++){
            dp.at(i+1).at(j) = dp.at(i).at(j) + dp.at(i).at(j-1)*run_length.at(i).second;
        }
    }

    cout << dp.at(run_length.size()).at(3) << endl;
    return 0;
}