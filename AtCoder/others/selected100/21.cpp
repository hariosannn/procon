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

map<ll, ll> make_comb_list(ll N){
    // map[nC2] = n
    map<ll, ll> ret;
    ll tmp_c = 0;
    ll n = 2;
    while(tmp_c <= N){
        tmp_c = (n*(n-1))/2;
        ret[tmp_c] = n;
        n++;
    }    
    return ret;
}

int main(){
    ll H, W;
    cin >> H >> W;
    pair<ll, ll> start{0, 0}, goal{H-1, W-1};
    vector<vector<char>> maze;
    rep(i, H){
        vector<char> tmp_v(W);
        cin >> tmp_v;
        maze.push_back(tmp_v);
    }

    ll white_num = 0;
    rep(i, H){
        rep(j, W){
            if(maze.at(i).at(j) == '.') white_num++;
        }
    }
    queue<pair<ll, ll>> que;
    que.push(start);
    ll n = H*W;
    map<pair<ll, ll>, ll> dist; 
    rep(i, H){
        rep(j, W){
            dist[pair<ll, ll>{i, j}] = -1;
        }
    }
    dist.at(start) = 0;

    while(!que.empty()){
        pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        rep(i, 4){
            pair<ll, ll> next = pair<ll, ll>{v.first+DX[i], v.second+DY[i]};
            if((next.first < 0) | (next.first >= H) | (next.second < 0) | (next.second >= W)) continue;
            if(maze.at(next.first).at(next.second) == '#') continue;
            if(dist.at(next) != -1) continue;
            que.push(next);
            dist.at(next) = dist.at(v) + 1;
        }
    }
    if(dist[goal] == -1) cout << -1 << endl;
    else cout << white_num - dist[goal] - 1 << endl;
}