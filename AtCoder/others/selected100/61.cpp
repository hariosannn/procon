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

struct road
{
    ll dist;
    ll time;
};

int main(){
    ll V, E;
    cin >> V >> E;
    vector<V_L> graph(V, V_L(V, -1));
    rep(i, E){
        ll s,t, d;
        cin >> s >> t >> d;
        graph.at(s).at(t) = d;
    }
    
    vector<V_L> dp(1<<V, V_L(V, LINF));
    dp.at(1).at(0) = 0;
    for(ll visited_bit = 1; visited_bit<(1<<V); visited_bit++){
        rep(next_v, V){
            if(visited_bit & (1<<next_v)){
                if(visited_bit != ((1<<V)-1)) continue;
            }
            rep(last_v, V){
                if(graph.at(last_v).at(next_v) == -1) continue;
                dp.at(visited_bit | (1<<next_v)).at(next_v) = min(dp.at(visited_bit | (1<<next_v)).at(next_v), 
                                                                  dp.at(visited_bit).at(last_v) + graph.at(last_v).at(next_v));
            }
        }
    }
    if(dp.at((1<<V)-1).at(0) == LINF) cout << -1 << endl;
    else cout << dp.at((1<<V)-1).at(0) << endl;
}