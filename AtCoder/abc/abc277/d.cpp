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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main(){
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<P_L>> graph(N);
    rep(i, M){
        ll a, b, s;
        cin >> a >> b >> s;
        a--;
        b--;
        graph.at(a).push_back(P_L{b, s});
        graph.at(b).push_back(P_L{a, s});
    }

    set<ll> switch_node;
    rep(i, K){
        ll k;
        cin >> k;
        k--;
        switch_node.insert(k);
    }

    queue<P_L> que;
    map<P_L, ll> dist; 
    rep(i, N){
        dist[P_L{i, 0}] = -1;
        dist[P_L{i, 1}] = -1;
    }
    ll start = 0;
    que.push(P_L{start, 1});
    dist[P_L{start, 1}] = 0;
    if(switch_node.find(0) != switch_node.end()){
        dist[P_L{start, 0}] = 0;
        que.push(P_L{start, 0});
    }

    while(!que.empty()){
        P_L v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(auto next:graph.at(v.first)){
            // すでに訪れているなら次の探索候補に入れない
            if(switch_node.find(v.first) == switch_node.end()){
                if(next.second != v.second) continue;
                if(dist.at(next) != -1) continue;
                que.push(next);
                dist.at(next) = dist.at(v) + 1;
            }
            else{
                if(next.second != v.second){
                    ll current_switch;
                    if(v.second == 1) current_switch=0;
                    else current_switch=1;
                    P_L next2{next.first, current_switch};
                    if(dist.at(next2) != -1) continue;
                    que.push(next2);
                    dist.at(next2) = dist.at(v) + 1;
                }
                else{
                    if(dist.at(next) != -1) continue;
                    que.push(next);
                    dist.at(next) = dist.at(v) + 1;
                }
            }
        }
    }

    ll ans = -1;
    V_L ans_v;
    if(dist[P_L{N-1, 0}] != -1) ans_v.push_back(dist[P_L{N-1, 0}]);
    if(dist[P_L{N-1, 1}] != -1) ans_v.push_back(dist[P_L{N-1, 1}]);

    if(ans_v.size() == 2) cout << min(ans_v.at(0), ans_v.at(1)) << endl;
    else if(ans_v.size() == 1) cout << ans_v.at(0) << endl;
    else cout << -1 << endl;
}