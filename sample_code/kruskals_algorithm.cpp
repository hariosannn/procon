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

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge{
    ll a, b, cost;
    // コストの大小で順序定義
    bool operator<(const Edge& o) const{
        return cost < o.cost;
    }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
    ll n; //頂点数
    vector<Edge> es; //辺集合

    // クラスカル法で無向最小全域木のコストの和を計算する
    // グラフが非連結のときは最小全域森のコストの和となる
    ll kruskal(){
        //コストが小さい順にソート
        sort(es.begin(), es.end());

        dsu uf(n);
        ll min_cost = 0;

        rep(ei, es.size()){
            Edge& e = es[ei];
            if(!uf.same(e.a, e.b)){
                //辺を追加しても閉路ができないなら、その辺を採用する
                min_cost += e.cost;
                uf.merge(e.a, e.b);
            }
        }
        return min_cost;
    }
};

int main(){
    Graph g{4, vector<Edge>{Edge{0, 1, 1}, Edge{0, 2, 2}, 
                            Edge{0, 3, 1}, Edge{1, 2, 1}, Edge{1, 3, 2}}};
    cout << g.kruskal() << endl;
}