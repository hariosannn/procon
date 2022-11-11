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

void f_num(vector<V_I> graph, ll x, ll y, ll ret, ll &ans){
    graph.at(x).at(y) = 0;
    bool is_goal = true;
    ret += 1;
    rep(dir, 4){
        if(graph.at(x+DX[dir]).at(y+DY[dir]) == 1){
            f_num(graph, x+DX[dir], y+DY[dir], ret, ans);
            is_goal = false;
        }
    }
    //graph.at(x).at(y) = 1;
    if(is_goal) {
        if(ans < ret) ans = ret;
        return;
    }
}

int main(){
    ll H, W;
    cin >> W >> H;
    vector<V_I> graph(1, V_I(W+2, 0));
    rep(i, H){
        V_I tmp{0};
        rep(j, W){
            ll f;
            cin >> f;
            tmp.push_back(f);
        }
        tmp.push_back(0);
        graph.push_back(tmp);
    }
    graph.push_back(V_I(W+2, 0));

    ll ans = 0;
    rep(h, H){
        rep(w, W){
            if(graph.at(h+1).at(w+1) == 1){
                f_num(graph, h+1, w+1, 0, ans);
            }
        }
    }
    cout << ans << endl;
} 