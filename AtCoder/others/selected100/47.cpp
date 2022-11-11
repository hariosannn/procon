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

void warshall_floyd(ll n, vector<vector<ll>> &wf_graph, vector<vector<ll>> &next){
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if((wf_graph.at(i).at(k) == LINF) || (wf_graph.at(k).at(j) == LINF)) continue;
                ll d_via_ks = wf_graph.at(i).at(k) + wf_graph.at(k).at(j); 
                if(d_via_ks < wf_graph.at(i).at(j)){
                    wf_graph.at(i).at(j) = d_via_ks;
                    next.at(i).at(j) = next.at(i).at(k);
                }
            }
        }
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    vector<V_L> graph;
    rep(i, 10){
        V_L tmp(10);
        cin >> tmp;
        graph.push_back(tmp);
    }

    vector<vector<ll>> wf_graph = graph;
    ll n = wf_graph.size();

    vector<vector<ll>> next(n);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            next.at(i).push_back(j);
        }
    }

    warshall_floyd(n, wf_graph, next);

    ll ans = 0;
    rep(i, H){
        rep(j, W){
            ll a;
            cin >> a;
            if(a != -1){
                ans += wf_graph.at(a).at(1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}