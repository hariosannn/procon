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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

bool is_complete(V_L &state){
    bool ret = true;
    rep(i, 8){
        if(state[i] != i) ret = false;
    }
    return ret;
}

ll node_to_pieces(V_L &state, ll node){
    ll ret = 0;
    for(ll i=0; i<state.size(); i++){
        if(node == state.at(i)) ret = i;
    }
    return ret;
}

int main(){
    ll M;
    cin >> M;
    vector<V_L> graph(9, V_L{});
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
    }
    V_L P(8);
    cin >> P;
    set<ll> place{0,1,2,3,4,5,6,7,8};
    V_L state(9);
    rep(i, 8){
        P.at(i) -= 1;
        place.erase(P.at(i));
        state[i] = P.at(i);
    }
    state[8] = *place.begin();

    queue<V_L> que;
    que.push(state);
    map<V_L, ll> dist; 

    V_L perm(9);
    rep(i, 9){
        perm.at(i) = i;
    }
    do {
        dist[perm] = -1;
    } while (next_permutation(perm.begin(), perm.end()));
    dist[state] = 0;

    while(!que.empty()){
        V_L current_state = que.front(); // キューから先頭頂点を取り出す
        if(is_complete(current_state)){
            cout << dist[current_state] << endl;
            return 0;
        }
        que.pop();
        ll void_node = current_state[8];
        for(ll next:graph.at(current_state[8])){
            // すでに訪れているなら次の探索候補に入れない
            V_L next_state = current_state;
            next_state[8] = next;
            next_state[node_to_pieces(current_state, next)] = void_node;
            if(dist[next_state] != -1) continue;
            que.push(next_state);
            dist[next_state] = dist.at(current_state) + 1;
        }
    }
    cout << -1 << endl;
}