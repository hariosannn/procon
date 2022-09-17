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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

struct bento
{
    ll a;
    ll b;
};

struct coord
{
    ll x;
    ll y;
};

bool is_same_fig(vector<coord> S,vector<coord> T){
    if(S.size() != T.size()){
        return false;
    }
    set<pair<ll, ll>> diffs;
    rep(i, S.size()){
        diffs.insert(pair<ll, ll>{S.at(i).x - T.at(i).x, S.at(i).y - T.at(i).y});
    }
    return (diffs.size() == 1);
}

int main(){
    ll N;
    cin >> N;
    vector<coord> S, T;
    vector<vector<char>> S_c;
    rep(i, N){
        vector<char> tmp_v;
        rep(j, N){
            char c;
            cin >> c;
            tmp_v.push_back(c);
            if(c == '#') S.push_back(coord{i, j});
        }
        S_c.push_back(tmp_v);
    }
    rep(i, N){
        rep(j, N){
            char c;
            cin >> c;
            if(c == '#') T.push_back(coord{i, j});
        }
    }

    if(is_same_fig(S, T)){
        cout << "Yes" << endl;
        return 0;
    }
    rep(i, 3){
        vector<vector<char>> S_c_copy = S_c;
        rep(j, N){
            rep(k, N){
                S_c.at(j).at(k) = S_c_copy.at(N-k-1).at(j);
            }
        }
        vector<coord> tmp_S;
        rep(l, N){
            vector<char> tmp_v;
            rep(m, N){
                if(S_c.at(l).at(m) == '#') tmp_S.push_back(coord{l, m});
            }
        }
        if(is_same_fig(tmp_S, T)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}