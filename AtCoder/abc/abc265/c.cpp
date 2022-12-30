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
using P_L = pair<ll, ll>;
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


int main(){
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> G;
    rep(i, H){
        vector<char> tmp(W);
        cin >> tmp;
        G.push_back(tmp);
    }

    map<char, ll> c_dir_map;
    c_dir_map['U'] = 2;
    c_dir_map['D'] = 0;
    c_dir_map['L'] = 3;
    c_dir_map['R'] = 1;

    set<P_L> visited_coord;
    P_L current_coord = P_L{0, 0};
    visited_coord.insert(current_coord);
    rep(i, H*W+1){
        char current_c = G.at(current_coord.first).at(current_coord.second);
        ll dir = c_dir_map[current_c];

        P_L next_coord = P_L{current_coord.first + DX[dir], current_coord.second + DY[dir]};
        if((next_coord.first < 0) || (next_coord.first >= H) || (next_coord.second < 0) || (next_coord.second >= W)){
            cout << current_coord.first+1 << " " << current_coord.second+1 << endl;
            return 0;
        }
        else if(visited_coord.find(next_coord) != visited_coord.end()){
            cout << -1 << endl;
            return 0;
        }
        visited_coord.insert(current_coord);
        current_coord = next_coord;
    }
}