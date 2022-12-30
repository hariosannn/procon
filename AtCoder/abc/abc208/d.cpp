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

         
ll warshall_floyd(ll n, vector<vector<ll>> &wf_graph, vector<vector<ll>> &next){
    ll cost_sum = 0;
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
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                ll c = wf_graph.at(i).at(j);
                if(c <= LINF/2) cost_sum += c;
            }
        }
    }
    return cost_sum;
}

void printPath(ll start, ll goal,vector<vector<ll>> &next) {
    for (ll cur = start; cur != goal; cur = next[cur][goal])
        printf("%d ", cur+1);
    printf("%d\n", goal+1);
}


int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> graph(N, V_L(N, LINF));
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph.at(a).at(b) = c;
    }
    rep(i, N) graph.at(i).at(i) = 0;

    vector<vector<ll>> next(N);
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            next.at(i).push_back(j);
        }
    }

    ll ans = warshall_floyd(N, graph, next);
    cout << ans << endl;

}