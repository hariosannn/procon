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

// 最大公約数
ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}

// 最大公約数(配列版)
ll gcd_arr(vector<ll> &a){
    ll n = a.size();
    ll ret = a.at(0);
    for(ll i=1; i<n; i++){
        ret = gcd(ret, a.at(i));
    }
    return ret;
}

// 最小公倍数(配列版)
ll lcm_arr(vector<ll>& a){
    ll n = a.size();
    ll ret = a.at(0);
    for(ll i=1; i<n; i++){
        ret = lcm(ret, a.at(i));
    }
    return ret;
}

int main(){
  V_L A{60,120,156,180};
  cout << gcd_arr(A) << endl;
  cout << lcm_arr(A) << endl;
}