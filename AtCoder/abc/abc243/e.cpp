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

         
void warshall_floyd(ll n, vector<vector<P_L>> &wf_graph, vector<vector<ll>> &next){
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if((wf_graph.at(i).at(k).first == LINF) || (wf_graph.at(k).at(j).first == LINF)) continue;
                ll d_via_ks = wf_graph.at(i).at(k).first + wf_graph.at(k).at(j).first; 
                ll num_via_ks = wf_graph.at(i).at(k).second + wf_graph.at(k).at(j).second; 
                if(d_via_ks < wf_graph.at(i).at(j).first){
                    wf_graph.at(i).at(j).first = d_via_ks;
                    wf_graph.at(i).at(j).second = num_via_ks;
                    next.at(i).at(j) = next.at(i).at(k);
                }
                else if(d_via_ks == wf_graph.at(i).at(j).first){
                    if(num_via_ks < wf_graph.at(i).at(j).second){
                        wf_graph.at(i).at(j).second = num_via_ks;
                        next.at(i).at(j) = next.at(i).at(k);
                    }
                }
            }
        }
    }
}

void printPath(ll start, ll goal,vector<vector<ll>> &next, set<P_L> &ans) {
    ll prev = start;
    ll cur = next[prev][goal];
    for (;cur != goal; cur = next[cur][goal]){
        ans.insert(P_L{max(cur, prev), min(cur, prev)});
        prev = cur;
    }
    ans.insert(P_L{max(goal, prev), min(goal, prev)});
}

int main(){
    ll N, M;
    cin >> N >> M;
    // P_L{cost, edge_num}
    vector<vector<P_L>> wf_graph(N, vector<P_L>(N, P_L{LINF, 1}));
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        wf_graph.at(a).at(b).first = c;
        wf_graph.at(b).at(a).first = c;
    }
    rep(i, N){
        wf_graph.at(i).at(i) = P_L{0, 0};
    }

    vector<vector<ll>> next(N);
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            next.at(i).push_back(j);
        }
    }

    warshall_floyd(N, wf_graph, next);
    set<P_L> ans;
    rep(i, N){
        rep(j, N){
            if(i==j) continue;
            printPath(i, j, next, ans);
        }
    }

    cout << M-ll(ans.size()) << endl;
}