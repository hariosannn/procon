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
    while(true){
    ll W, H;
    cin >> W >> H;
    if(W == 0) break;
    vector<V_L> walls;
    rep(i, 2*H-1){
        if(i%2 == 0){
            V_L tmp(W-1);
            cin >> tmp;
            tmp.push_back(1);
            walls.push_back(tmp);
        }
        else{
            V_L tmp(W);
            cin >> tmp;
            walls.push_back(tmp);
        }
    }
    walls.push_back(V_L(W, 1));

    vector<V_L> graph(W*H, V_L{});
    rep(h, H-1){
        rep(w, W){
            if(walls.at(2*h+1).at(w) != 1){
                graph.at(h*W + w).push_back((h+1)*W + w);
                graph.at((h+1)*W + w).push_back(h*W + w);
            }
            if(walls.at(2*h).at(w) != 1){
                graph.at(h*W + w).push_back(h*W + (w+1));
                graph.at(h*W + (w+1)).push_back(h*W + w);
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
    cout << dist.at(W*H-1) + 1 << endl;
    }
}