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

void dfs(vector<V_L> room, P_L prev_pivot, ll left2, ll left1, ll &ans_num){
    ll H = room.size();
    ll W = room.at(0).size();
    ll h = prev_pivot.first, w = prev_pivot.second;
    while((h < H) && (w < W) && (room.at(h).at(w) == 1)){
        w ++;
        if(w % W == 0){
            w = 0;
            h++;
        }
    }
    if(h == H){
        ans_num++;
        return;
    }
    else{
        vector<V_L> new_room = room;
        P_L next_pivot{h, w};
        // 1x1
        if(left1 >= 1){
            new_room.at(h).at(w) = 1;
            dfs(new_room, next_pivot, left2, left1-1, ans_num);
            new_room = room;
        }
        // 1x2 縦
        if((left2 >= 1) && (h < H-1) && (room.at(h+1).at(w) == 0)){
            new_room.at(h).at(w) = 1;
            new_room.at(h+1).at(w) = 1;
            dfs(new_room, next_pivot, left2-1, left1, ans_num);
            new_room = room;
        }
        // 1x2 横
        if((left2 >= 1) && (w < W-1) && (room.at(h).at(w+1) == 0)){
            new_room.at(h).at(w) = 1;
            new_room.at(h).at(w+1) = 1;
            dfs(new_room, next_pivot, left2-1, left1, ans_num);
            new_room = room;
        }
    }
    return;
}

int main(){
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<V_L> room(H, V_L(W, 0));
    ll ans = 0;
    dfs(room, P_L{0, 0}, A, B, ans);
    cout << ans << endl;
}