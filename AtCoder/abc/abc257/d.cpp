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

struct jump_ramp
{
    ll x;
    ll y;
    ll p;
};

bool dfs(vector<V_L> &graph, ll start){
    queue<ll> que;
    que.push(start);
    ll n = graph.size();
    vector<ll> dist(n, -1); 
    dist.at(start) = 0;

    ll counter = 1;
    while(!que.empty()){
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(ll next:graph.at(v)){
            if(dist.at(next) != -1) continue;
            que.push(next);
            dist.at(next) = dist.at(v) + 1;
            counter ++;
        }
    }
    return counter == n;
}

// index が条件を満たすかどうか
bool isOK(ll train, ll start, vector<jump_ramp> &J, vector<V_L> &dist) {
    ll N = J.size();
    vector<V_L> graph(N, V_L{});
    rep(i, N){
        rep(j, N){
            if(dist.at(i).at(j) <= train*J.at(i).p){
                graph.at(i).push_back(j);
            }
        }
    }
    return dfs(graph, start);
}

// 汎用的な二分探索のテンプレ
ll binary_search(vector<jump_ramp> &J, vector<V_L> &dist, ll start) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = (ll)4*1e9; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = -1; //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, start, J, dist)) ok = mid;
        else ng = mid;
    }
    return ok;
}



int main(){
    ll N;
    cin >> N;
    vector<jump_ramp> J;
    rep(i, N){
        ll x, y, p;
        cin >> x >> y >> p;
        J.push_back(jump_ramp{x, y, p});
    }

    vector<V_L> dist(N, V_L{});
    rep(i, N){
        rep(j, N){
            dist.at(i).push_back(abs(J.at(i).x - J.at(j).x) + abs(J.at(i).y - J.at(j).y));
        }
    }

    ll ans = LINF;
    rep(i, N){
        chmin(ans, binary_search(J, dist, i));
    }

    cout << ans << endl;
    return 0;
}