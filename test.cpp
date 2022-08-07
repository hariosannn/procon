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

int main(){
    ll N, L, R;
    cin >> N >> L >> R;
    V_L A(N);
    cin >> A;

    ll max_diff = 0;
    ll max_ind = -1;
    ll sum_A = 0;
    ll sum_L = 0;
    rep(i, N){
        sum_A += A.at(i);
        sum_L += L;
        if(max_diff < sum_A-sum_L){
            max_diff = sum_A-sum_L;
            max_ind = i;
        }
    }

    ll max_diff_r = 0;
    ll max_ind_r = N;
    ll sum_A_r = 0;
    ll sum_R = 0;
    rep(i, N){
        sum_A_r += A.at(N-i-1);
        sum_R += R;
        if(max_diff_r < sum_A_r-sum_R){
            max_diff_r = sum_A_r-sum_R;
            max_ind_r = N-i-1;
        }
    }
    ll ans = 0;
    ans += (max_ind+1)*L + (N-max_ind_r)*R;
    rep(i, N){
        if((i>max_ind) & (i<max_ind_r)){
            ans += A.at(i);
        }
    }
    cout << ans << endl;
}