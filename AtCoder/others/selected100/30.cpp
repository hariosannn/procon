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

struct coord
{   
    ll x, y;

    ld dist(coord c){
        return sqrt((c.x - x)*(c.x - x) + (c.y - y)*(c.y - y));
    }
};

int main(){
    ll N, M;
    cin >> N >> M;
    vector<set<ll>> graph(N, set<ll>{});
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        graph.at(x).insert(y);
        graph.at(y).insert(x);
    }

    ll ans = 1;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<N); ++bit) {
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }

        bool is_faction = true;
        for(ll x:S){
            for(ll y:S){
                if(x != y){
                    if(graph.at(x).find(y) == graph.at(x).end()) is_faction = false;
                }
            }
        }
        if(is_faction) chmax(ans, S.size());
    }

    cout << ans << endl;
}