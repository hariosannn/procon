#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
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
    int lx, ly, rx, ry;
};


int main(){
    ll N, L, R;
    cin >> N >> L >> R;
    V_L A(N);
    cin >> A;

    V_L L_min;
    V_L R_min;

    L_min.push_back(0);
    R_min.push_back(0);

    for(int i=0; i<N; i++){
        L_min.push_back(min(L_min.at(i)+A.at(i), L*(i+1)));
    }
    
    for(int i=0; i<N; i++){
        R_min.push_back(min(R_min.at(i)+A.at(N-i-1), R*(i+1)));
    }

    ll ans = LINF;
    rep(i, N+1){
        chmin(ans, L_min.at(i) + R_min.at(N-i));
    }

    cout << ans << endl;
}