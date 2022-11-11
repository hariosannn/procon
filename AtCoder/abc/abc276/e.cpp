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
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> maze;
    rep(i, H){
        vector<char> tmp(W);
        cin >> tmp;
        maze.push_back(tmp);
    }

    pair<ll, ll> start;
    rep(i, H){
        rep(j, W){
            if(maze.at(i).at(j) == 'S') start = pair<ll, ll>{i, j};
        }
    }

    ll N = H*W;
    dsu UF(N);

    rep(h, H){
        rep(w, W){
            rep(dir_i, 4){
                if((maze.at(h).at(w) == '#') || (maze.at(h).at(w) == 'S')) continue;
                ll dw = DX[dir_i];
                ll dh = DY[dir_i];
                pair<ll, ll> next{dh+h, dw+w};
                if((next.first < 0) || (next.first >= H) || (next.second < 0) || (next.second >= W)) continue;
                if(maze.at(next.first).at(next.second) == '#') continue;
                if(maze.at(next.first).at(next.second) == 'S') continue;
                UF.merge(h*W + w, next.first*W + next.second);
            }
        }
    }

    string ans = "No";
    rep(dir_i_1, 4){
        for(ll dir_i_2 = dir_i_1+1; dir_i_2<4; dir_i_2++){
            ll dw1 = DX[dir_i_1];
            ll dh1 = DY[dir_i_1];
            pair<ll, ll> next1{dh1+start.first, dw1+start.second};

            ll dw2 = DX[dir_i_2];
            ll dh2 = DY[dir_i_2];
            pair<ll, ll> next2{dh2+start.first, dw2+start.second};
            if((next1.first < 0) || (next1.first >= H) || (next1.second < 0) || (next1.second >= W)) continue;
            if(maze.at(next1.first).at(next1.second) == '#') continue;
            if((next2.first < 0) || (next2.first >= H) || (next2.second < 0) || (next2.second >= W)) continue;
            if(maze.at(next2.first).at(next2.second) == '#') continue;

            if((UF.leader(next1.first*W + next1.second) == -1) || (UF.leader(next2.first*W + next2.second) == -1)) continue;
            if(UF.same(next1.first*W + next1.second, next2.first*W + next2.second)) ans = "Yes";
        }
    }

    cout << ans << endl;
}