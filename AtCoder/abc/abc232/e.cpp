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

struct coord
{
    ll h;
    ll w;
};


int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    ll h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    h1--;
    w1--;
    h2--;
    w2--;
    coord start{h1, w1}, goal{h2, w2};
    vector<vector<modint998244353>> dp(K+1, vector<modint998244353>(4, 0));

    if((h1 == h2) && (w1 == w2)) dp.at(0).at(0) = 1;
    else if(h1 == h2) dp.at(0).at(1) = 1;
    else if(w1 == w2) dp.at(0).at(2) = 1;
    else dp.at(0).at(3) = 1;
    for(ll i=1; i<=K; i++){
        dp.at(i).at(0) = (dp.at(i-1).at(1) + dp.at(i-1).at(2));
        dp.at(i).at(1) = (dp.at(i-1).at(0)*(W-1) + dp.at(i-1).at(1)*(W-2) + dp.at(i-1).at(3));
        dp.at(i).at(2) = (dp.at(i-1).at(0)*(H-1) + dp.at(i-1).at(2)*(H-2) + dp.at(i-1).at(3));
        dp.at(i).at(3) = (dp.at(i-1).at(1)*(H-1) + dp.at(i-1).at(2)*(W-1) + 
                          dp.at(i-1).at(3)*(W-2) + dp.at(i-1).at(3)*(H-2));
    }
    cout << dp.at(K).at(0).val() << endl;
    return 0;
}
