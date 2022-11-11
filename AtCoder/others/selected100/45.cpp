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

int main(){
    ll H, W, N;
    cin >> H >> W >> N;
    map<ll, pair<ll, ll>> check_point;
    vector<vector<char>> maze(H, vector<char>(W, '.'));
    rep(i, H){
        rep(j, W){
            char tmp;
            cin >> tmp;
            if(tmp == 'S') check_point[0] = pair<ll, ll>{i, j};
            if((1 <= tmp - '0') && (9 >= tmp - '0')) check_point[tmp - '0'] = pair<ll, ll>{i, j};
            maze.at(i).at(j) = tmp;
        }
    }

    ll ans = 0;
    rep(i, N){
        queue<pair<ll, ll>> que;
        pair<ll, ll> start = check_point[i];
        pair<ll, ll> goal = check_point[i+1];
        que.push(start);
        ll n = H*W;
        map<pair<ll, ll>, ll> dist;
        rep(h, H){
            rep(w, W){
                dist[pair<ll, ll>{h, w}] = -1;
            }
        }
        dist.at(start) = 0;

        while(!que.empty()){
            pair<ll, ll> v = que.front(); // キューから先頭頂点を取り出す
            que.pop();
            if(v == goal){
                ans += dist[v];
                break;
            } 
            rep(dir, 4){
                // すでに訪れているなら次の探索候補に入れない
                ll next_h = v.first + DX[dir];
                ll next_w = v.second + DY[dir];
                pair<ll, ll> next{next_h, next_w};
                if((next_h < 0) || (next_h >= H) || (next_w < 0) || (next_w >= W)) continue;
                if(maze.at(next_h).at(next_w) == 'X') continue;
                if(dist.at(next) != -1) continue;
                que.push(next);
                dist.at(next) = dist.at(v) + 1;
            }
        }
    }

    cout << ans << endl;
}