#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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

struct city
{
    ll x;
    ll y;
    ll n;
};

bool compare_city_y(city& c1, city& c2){
    if(c1.y != c2.y){
        return c1.y < c2.y;
    }
    else{
        return c1.x < c2.x;
    }
}

bool compare_city_x(city& c1, city& c2){
    if(c1.x != c2.x){
        return c1.x < c2.x;
    }
    else{
        return c1.y < c2.y;
    }
}

int main(){
    ll N;
    cin >> N;
    vector<city> cities;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        cities.push_back(city{x, y, i});
    }

    vector<Edge> E;
    sort(cities.begin(), cities.end(), compare_city_x);
    rep(i, N-1){
        E.push_back(Edge{cities.at(i).n, cities.at(i+1).n, abs(cities.at(i).x - cities.at(i+1).x)});
        E.push_back(Edge{cities.at(i+1).n, cities.at(i).n, abs(cities.at(i).x - cities.at(i+1).x)});
    }
    sort(cities.begin(), cities.end(), compare_city_y);
    rep(i, N-1){
        E.push_back(Edge{cities.at(i).n, cities.at(i+1).n, abs(cities.at(i).y - cities.at(i+1).y)});
        E.push_back(Edge{cities.at(i+1).n, cities.at(i).n, abs(cities.at(i).y - cities.at(i+1).y)});
    }

    Graph g{N, E};
    cout << g.kruskal() << endl;
}