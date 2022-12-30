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

bool is_able_to(ll n, vector<vector<ll>> &wf_graph, vector<vector<ll>> &next){
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if((wf_graph.at(i).at(k) == LINF) || (wf_graph.at(k).at(j) == LINF)) continue;
                ll d_via_ks = wf_graph.at(i).at(k) + wf_graph.at(k).at(j); 
                if(d_via_ks < wf_graph.at(i).at(j)){
                    return false;
                }
            }
        }
    }
    return true;
}

void warshall_floyd(ll n, vector<vector<ll>> &wf_graph, vector<vector<ll>> &next){
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if((wf_graph.at(i).at(k) == LINF) || (wf_graph.at(k).at(j) == LINF)) continue;
                ll d_via_ks = wf_graph.at(i).at(k) + wf_graph.at(k).at(j); 
                if((d_via_ks == wf_graph.at(i).at(j)) && (i != j) && (i != k) && (j != k)){
                    wf_graph.at(i).at(j) = LINF;
                }
            }
        }
    }
}

void printPath(ll start, ll goal,vector<vector<ll>> &next) {
    for (ll cur = start; cur != goal; cur = next[cur][goal])
        printf("%d ", cur+1);
    printf("%d\n", goal+1);
}

int main(){
    ll N;
    cin >> N;
    vector<V_L> graph;
    rep(i, N){
        V_L tmp(N);
        cin >> tmp;
        graph.push_back(tmp);
    }
    vector<vector<ll>> wf_graph = graph;
    for(ll i=0; i<wf_graph.size(); i++){
        for(ll j=0; j<wf_graph.at(i).size(); j++){
            if((wf_graph.at(i).at(j) == 0) && (i != j)){
                wf_graph.at(i).at(j) = LINF;
            }
        }
    }
    vector<vector<ll>> next(N);
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            next.at(i).push_back(j);
        }
    }

    bool is_able = is_able_to(N, wf_graph, next);
    warshall_floyd(N, wf_graph, next);

    if(is_able){
        ll ans = 0;
        rep(i, N){
            for(ll j=i+1; j<N; j++){
                if(wf_graph.at(i).at(j) != LINF) ans+= wf_graph.at(i).at(j);
            }
        }
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}