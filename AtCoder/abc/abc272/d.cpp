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
    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> move_dir;
    rep(i, N+1){
        rep(j, N+1){
            if(M == ((i)*(i) + (j)*(j))){
                move_dir.push_back(pair<ll, ll>{(i), (j)});
                move_dir.push_back(pair<ll, ll>{-(i), (j)});
                move_dir.push_back(pair<ll, ll>{(i), -(j)});
                move_dir.push_back(pair<ll, ll>{-(i), -(j)});
            }
        }
    }

    vector<V_L> graph(N*N, V_L{});
    rep(i, N){
        rep(j, N){
            for(auto v: move_dir){
                pair<ll, ll> next{(i+v.first),  (j+v.second)};
                if((0 <= next.first) && (next.first < N) && (0 <= next.second) && (next.second < N)){
                    graph.at(i*N + j).push_back(next.first*N + next.second);
                }
            }
        }
    }
    queue<ll> que;
    ll start = 0;
    que.push(start);
    ll n = graph.size();
    vector<ll> dist(n, -1); 
    dist.at(start) = 0;

    while(!que.empty()){
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(ll next:graph.at(v)){
            // すでに訪れているなら次の探索候補に入れない
            if(dist.at(next) != -1) continue;
            que.push(next);
            dist.at(next) = dist.at(v) + 1;
        }
    }

    rep(i, N*N){
        if((i+1)%N == 0) cout << dist.at(i) <<endl;
        else cout << dist.at(i) << " ";
    }
    return 0;
}