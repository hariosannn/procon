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

int main(){
    ll N, K;
    cin >> N >> K;
    V_L A(N);
    cin >> A;
    A.push_back(0);
    sort(A.begin(), A.end(), greater<ll>());
    V_L A_diff;
    rep(i, N){
        A_diff.push_back(A.at(i) - A.at(i+1));
    }

    ll ans = 0;
    rep(i, N){
        ll tmp_diff = A_diff.at(i);
        ll tmp_plus;
        if((i+1)*tmp_diff < K){
            tmp_plus = (i+1)*tmp_diff*(2*A.at(i)-tmp_diff+1)/2;
            ans += tmp_plus;
            K -= (i+1)*tmp_diff;
        }
        else{
            ll quotient = K/(i+1);
            ll remainder = K%(i+1);
            tmp_plus = (i+1)*quotient*(2*A.at(i)-quotient+1)/2;
            tmp_plus += (A.at(i)-quotient)*remainder;
            ans += tmp_plus;
            break;
        }
    }
    cout << ans << endl;
}