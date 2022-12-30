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

mint combinatinon_n(ll a, ll n){
    mint ret = 1;
    rep(i, n){
        ret *= (a-i);
    }
    rep(i, n){
        ret /= (i+1);
    }
    return ret;
}

mint power_mint(ll a, ll n){
    mint ret = 1;
    rep(i, n){
        ret *= a;
    }
    return ret;
}

struct state{
    ll x, y;
};

bool operator<(const state &left, const state &right) {
  // left < right の場合に true を返すように実装する
  if(left.x != right.x){
    return left.x < right.x;
  }
  else if(left.y != right.y){
    return left.y < right.y;
  }
  // ここfalseでないとsetなどで重複してしまう
  else return false;
}

bool operator==(const state &left, const state &right) {
  if(left.x != right.x){
    return false;
  }
  else if(left.y != right.y){
    return false;
  }
  else return true;
}

int main(){
    set<state> S;
    S.insert(state{0, 1});
    S.insert(state{1, 2});
    S.insert(state{0, 3});
    S.insert(state{1, 2});
    cout << S.size() << endl;
    if(state{1, 2} == state{1, 2}){
        cout << "Yes 1" << endl;
    }
    if(state{1, 3} == state{1, 2}){
        cout << "Yes 2" << endl;
    }
    return 0;
}