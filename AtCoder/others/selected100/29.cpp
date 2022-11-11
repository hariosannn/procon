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
    ll N;
    cin >> N;
    vector<char> colors{'R', 'B', 'W'};
    vector<vector<char>> F;
    rep(i, 5){
        vector<char> tmp(N);
        cin >> tmp;
        F.push_back(tmp);
    }

    vector<V_L> dp(N+1, V_L(3, LINF));
    rep(i, 3) dp.at(0).at(i) = 0;
    
    rep(i, N){
        ll paint_num;
        rep(paint_c_ind, 3){
            paint_num = 0;
            rep(j, 5){
                if(F.at(j).at(i) != colors.at(paint_c_ind)) paint_num++;
            }
            rep(c_ind, 3){
                if(c_ind == paint_c_ind) continue;
                dp.at(i+1).at(paint_c_ind) = min((dp.at(i).at(c_ind)), (dp.at(i+1).at(paint_c_ind))); 
            }
            dp.at(i+1).at(paint_c_ind) += paint_num;
        }   
    }

    ll ans = LINF;
    rep(i, 3){
        chmin(ans, dp.at(N).at(i));
    }

    cout << ans << endl;
}