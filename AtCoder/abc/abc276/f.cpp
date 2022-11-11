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
mint iterative_square(ll n, ll a){
    // n^aを返す関数
    mint ret = 1;
    mint n_2i = n;
    while(a > 0){
        if(a & 1) ret *= n_2i;
        n_2i *= n_2i;
        a = (a >> 1);
    }
    return ret;
}
int main(){
    ll N;
    cin >> N;
    V_L A(N);
    cin >> A;

    set<ll> set_A{A.at(0)};
    ll ans = A.at(0);
    rep(i, N-1){
        auto Iter1 = set_A.upper_bound(A.at(i));
        ll n = set_A.end() - Iter1;
        set_A.insert(A.at(i));
    }
    mint ans = 0;
    sort(A.begin(), A.end());
    V_L A_sum(N+1, 0);
    rep(i, N){
        A_sum.at(i+1) = A_sum.at(i) + A.at(i);
    }
    rep(i, N){
        mint tmp_ans1 = 1;
        tmp_ans1*=(i+1);
        tmp_ans1/=N;
        tmp_ans1/=N;
        tmp_ans1*=A.at(i);
        mint tmp_ans2 = 1;
        tmp_ans2*=(N-i-1);
        tmp_ans2/=N;
        tmp_ans2/=N;
        tmp_ans2*=A_sum.at(N) - A_sum.at(i);
        ans += tmp_ans1;
        ans += tmp_ans2;
    }

    cout << ans.val() << endl;
}