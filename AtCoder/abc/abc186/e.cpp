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
using P_L = pair<ll, ll>;
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define reps(i, x) for (ll i = 1; i <= (ll)(x); i++)
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};
constexpr int DX2[] = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int DY2[] = {0, 1, 0, -1, 1, 1, -1, -1};
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

// 最大公約数
ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}

ll congruence(ll a, ll b, ll m)
{
    ll c, d, e, f;
    ll q, r;
    ll tmp;
    
    c = a;
    e = b;
    d = m;
    f = 0;
    while ((r = c % d) != 0) {
        q = c / d;
        c = d;
        d = r;
        tmp = f;
        f = e - q * f;
        e = tmp;
    }
    if (b % d != 0) return -1;
    q = (f/d) % (m/d);
    if (q < 0) q += m/d;
    return q;
}

int main() {
    ll T;
    cin >> T;
    rep(i, T){
        ll N, S, K;
        cin >> N >> S >> K;
        cout << congruence(K, N-S, N) << endl;
        /*
        ll gcd_num = gcd(N, K);
        if(gcd_num == 1){
            ll inv = modinv(K, N);
            cout << ((N-S)*inv)%N << endl;
        }
        else{
            if((N - S) % gcd_num == 0){
                K /= gcd_num;
                ll b = N-S;
                b /= gcd_num;
                ll inv = modinv(K, N);
                cout << ((b)*inv)%N << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        */
    }

}