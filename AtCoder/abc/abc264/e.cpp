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

int main(){
    ll N, M, E;
    cin >> N >> M >> E;
    vector<pair<ll, ll>> edges;
    rep(i, E){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.push_back(pair<ll, ll>{u, v});
    }

    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> cutted_edge;
    set<ll> cutted_edge_ind_set;
    rep(i, Q){
        ll x;
        cin >> x;
        x--;
        cutted_edge_ind_set.insert(x);
        cutted_edge.push_back(edges.at(x));
    }

    vector<V_L> graph(N+M, V_L{});
    rep(i, E){
        if(cutted_edge_ind_set.find(i) == cutted_edge_ind_set.end()){
            pair<ll, ll> tmp_e = edges.at(i);
            graph.at(tmp_e.first).push_back(tmp_e.second);
            graph.at(tmp_e.second).push_back(tmp_e.first);
        }
    }
    reverse(cutted_edge.begin(), cutted_edge.end());

    dsu uf(N+M);
    rep(i, N+M){
        for(ll n:graph.at(i)){
            uf.merge(i, n);
        }
    }

    set<ll> root_E;
    for(ll i=N; i<N+M; i++){
        root_E.insert(uf.leader(i));
    }

    ll ans = 0;
    for(ll e:root_E){
        ans += uf.size(e);
    }
    ans -= M;

    V_L ans_v = {ans};
    rep(i, Q){
        pair<ll, ll> add_edge = cutted_edge.at(i);
        if((root_E.find(uf.leader(add_edge.first)) == root_E.end()) && (root_E.find(uf.leader(add_edge.second)) != root_E.end())){
            ans += uf.size(add_edge.first);
            ans_v.push_back(ans);
            uf.merge(add_edge.first, add_edge.second);
            root_E.insert(uf.leader(add_edge.first));
        }
        else if((root_E.find(uf.leader(add_edge.second)) == root_E.end()) && (root_E.find(uf.leader(add_edge.first)) != root_E.end())){
            ans += uf.size(add_edge.second);
            ans_v.push_back(ans);
            uf.merge(add_edge.first, add_edge.second);
            root_E.insert(uf.leader(add_edge.first));
        }
        else{
            uf.merge(add_edge.first, add_edge.second);
            ans_v.push_back(ans);
        }
    }
    ans_v.pop_back();
    reverse(ans_v.begin(), ans_v.end());
    for(ll a:ans_v){
        cout << a << endl;
    }
}