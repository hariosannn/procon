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

// index が条件を満たすかどうか
bool isOK(ll mid, vector<V_L> &graph, V_L &costs, V_L &A) {
    V_L costs_copy = costs;
    ll N = costs.size();
    vector<bool> visited(N, false);
    queue<ll> que;
    rep(i, N){
        if(costs.at(i) <= mid){
            visited.at(i) = true;
            que.push(i);
        }
    }
    if(que.size() == 0) return false;


    ll visit_num = 0;
    while(!que.empty()){
        ll now = que.front();
        visit_num++;
        que.pop();
        for(ll next:graph.at(now)){
            if(visited.at(next)) continue;
            ll tmp_cost = A.at(now);
            costs.at(next) -= tmp_cost;
            if((costs.at(next) <= mid) && !visited.at(next)){
                que.push(next);
                visited.at(next) = true;
            }
        }
    }
    costs = costs_copy;
    return visit_num == N;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key, vector<V_L> &graph, V_L &costs, V_L &A) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = key+1; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = -1; //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, graph, costs, A)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(){
    ll N, M;
    cin >> N >> M;
    V_L A(N);
    cin >> A;
    vector<V_L> graph(N, V_L{});
    V_L vanish_cost(N);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
        vanish_cost.at(u) += A.at(v);
        vanish_cost.at(v) += A.at(u);
    }

    ll ans = binary_search(2*1e14, graph, vanish_cost, A);
    cout << ans << endl;
    return 0;
}