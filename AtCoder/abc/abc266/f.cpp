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
    ll N, Q;
    cin >> N;
    vector<V_L> graph(N, V_L{});
    V_L edge_num(N, 0);
    rep(i, N){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
        edge_num.at(u)++;
        edge_num.at(v)++;
    }
    queue<ll> que;
    vector<bool> visited(N, false);
    rep(i, N){
        if(edge_num.at(i) <= 1){
            que.push(i);
            visited.at(i) = true;
        }
    }
    while(!que.empty()){
        ll now = que.front();
        que.pop();
        for(ll next:graph.at(now)){
            if(!visited.at(next)){
                edge_num.at(next) --;
                if(edge_num.at(next) <= 1){
                    que.push(next);
                    visited.at(next) = true;
                }
            }
        }
    }

    set<ll> cycle_node;
    rep(i, N){
        if(!visited.at(i)) cycle_node.insert(i);
    }
    vector<V_L> new_graph(N);
    rep(i, N){
        V_L tmp_g = graph.at(i);
        V_L new_g;
        if(cycle_node.find(i) != cycle_node.end()){
            for(ll n:tmp_g){
                if(cycle_node.find(n) == cycle_node.end()){
                    new_g.push_back(n);
                }
            }
        }
        else{
            new_g = graph.at(i);
        }
        new_graph.at(i) = new_g;
    }

    dsu uf(N);
    rep(i, N){
        for(ll n:new_graph.at(i)){
            uf.merge(i, n);
        }
    }
    cin >> Q;
    rep(i, Q){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        if(uf.same(x, y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}