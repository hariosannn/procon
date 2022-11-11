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

// Union-Find
struct UnionFind {
    vector<int> par, rank, siz;

    // 構造体の初期化
    UnionFind(int n) : par(n,-1), rank(n,0), siz(n,1) { }

    // 根を求める
    int leader(int x) {
        if (par[x]==-1) return x; // x が根の場合は x を返す
        else return par[x] = leader(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool same(int x, int y) {
        return leader(x)==leader(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool merge(int x, int y) {
        int rx = leader(x), ry = leader(y); // x 側と y 側の根を取得する
        if (rx==ry) return false; // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx]<rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx; // ry を rx の子とする
        if (rank[rx]==rank[ry]) rank[rx]++; // rx 側の rank を調整する
        siz[rx] += siz[ry]; // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    int size(int x) {
        return siz[leader(x)];
    }
};
// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge{
    ll a, b;
    ld cost;
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
    ld kruskal(){
        //コストが小さい順にソート
        sort(es.begin(), es.end());

        UnionFind uf(n);
        ld min_cost = 0;

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

struct circle
{
    ld x, y, z, r;
    ld dist(circle c){
        ld d = sqrt((x-c.x)*(x-c.x) + (y-c.y)*(y-c.y) + (z-c.z)*(z-c.z));
        return(d - (r + c.r));
    }
};

int main(){
    while(true){
        ll N;
        cin >> N;
        if(N==0) break;
        vector<circle> circles;
        rep(i, N){
            ld x, y, z, r;
            cin >> x >> y >> z >> r;
            circles.push_back(circle{x, y, z, r});
        }

        vector<Edge> E;
        rep(i, N){
            rep(j, N){
                if(i == j) continue;
                ld dist = circles.at(i).dist(circles.at(j));
                dist = max(ld(0), dist);
                E.push_back(Edge{i, j, dist});
            }
        }

        Graph G{N, E};
        ld ans = G.kruskal();
        cout << fixed << setprecision(3) << ans << endl;
    }
}