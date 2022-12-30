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

ll V;
vector<V_L> G;  // グラフ
vector<V_L> dp;

// メモ化再帰 S：訪れた頂点の組み合わせを表す数 v:最後に訪れた頂点
// 帰り値はSを訪れる経路の中で、最後にｖを訪れる場合の最短経路長
ll rec(ll S, ll v) {  
    // S==0 スタートの段階でまだどこも訪れていない
    if (S == 0) {
        // スタートの頂点(v=0)だった場合、最短経路長として0を返す　
        // それ以外は訪れることができないとして無限を返す
        return 0;
    }
    if ((S & (1 << v)) == 0) {  // Sに{v}が含まれていない
        return LINF;
    }
    ll &ret = dp[S][v];
    if (ret != 0) return ret;
    ret = LINF;
    // Sからvを除いた頂点を通り、最後にuを訪れた場合の中から最短を探す
    rep(u, V) { chmin(ret, rec(S ^ (1 << v), u) + G[u][v]); }
    return ret;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<V_L> graph(N);
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    cin >> V;
    G.assign(V, V_L(V, LINF));
    V_L C(V);
    cin >> C;
    rep(i, V) C.at(i)--;

    rep(i, V){
        for(ll j=i+1; j<V; j++){
            queue<ll> que;
            ll start = C.at(i);
            ll goal = C.at(j);
            que.push(start);
            ll n = graph.size();
            vector<ll> dist(n, -1); 
            dist.at(start) = 0;

            while(!que.empty()){
                ll v = que.front(); // キューから先頭頂点を取り出す
                que.pop();
                if(v == goal) break;
                for(ll next:graph.at(v)){
                    // すでに訪れているなら次の探索候補に入れない
                    if(dist.at(next) != -1) continue;
                    que.push(next);
                    dist.at(next) = dist.at(v) + 1;
                }
            }
            if(dist.at(goal) != -1){
                G.at(i).at(j) = dist.at(goal);
                G.at(j).at(i) = dist.at(goal);
            }
        }
    }

    dp.assign((1 << V), V_L(V, 0));

    rep(i, V) dp.at(1<<i).at(i) = 1;
    rep(i, V) rec((1 << V) - 1, i);
    ll ans = LINF;
    rep(i, V){
        chmin(ans, dp.at((1 << V) - 1).at(i));
    }
    if (ans != LINF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}