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
    int N, M, A, B, C, D, E, F;
    cin >> N >> M >> A >> B >> C >> D >> E >> F;
    vector<P_I> DIFF{P_I{A, B}, P_I{C, D}, P_I{E, F}};
    set<P_I> NG;
    rep(i, M){
        int x, y;
        cin >> x >> y;
        NG.insert(P_I{x, y});
    }

    map<P_I, mint> dp;
    dp[P_I{0, 0}] = 1;
    rep(i, N){
        map<P_I, mint> new_dp;
        for(auto s:dp){
            rep(dir, 3){
                P_I current = s.first;
                mint current_paths = s.second;
                P_I next = P_I{current.first + DIFF[dir].first, current.second + DIFF[dir].second};
                if(NG.find(next) != NG.end()) continue;
                new_dp[next] += current_paths;
            }
        }
        swap(dp, new_dp);
    }
    mint ans = 0;
    for(auto p:dp){
        ans += p.second;
    }
    cout << ans.val() << endl;
}