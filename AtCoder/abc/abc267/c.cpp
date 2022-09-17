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
 
int main()
{
    ll N, M;
    cin >> N >> M;
    V_L A(N);
    cin >> A;
    ll first_sum = 0;
    rep(i, M){
        first_sum += (i+1)*A.at(i);
    }
    V_L A_sum(N+1);
    rep(i, N){
        A_sum.at(i+1) = A_sum.at(i) + A.at(i);
    }
    ll ans = first_sum;
    ll tmp_sum = first_sum;
    for(ll i=1; i<N-M+1; i++){
        tmp_sum -= (A_sum.at(M+i-1) - A_sum.at(i-1));
        tmp_sum += A.at(i+M-1)*M;
        chmax(ans, tmp_sum);
    }
    cout << ans << endl;
}
 