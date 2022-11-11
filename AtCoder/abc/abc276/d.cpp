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

struct factors
{
    ll two;
    ll three;
    ll other;
};

factors calc_f(ll a){
    ll two = 0;
    ll three = 0;
    while((a%2 == 0) || (a%3 == 0)){
        if(a%2 == 0){
            two++;
            a /= 2;
        }
        if(a%3 == 0){
            three++;
            a /= 3;
        }
    }
    return factors{two, three, a};
}
int main(){
    ll N;
    cin >> N;
    V_L A(N);
    cin >> A;

    vector<factors> F;
    ll min_two = LINF;
    ll min_three = LINF;
    set<ll> set_other;

    rep(i, N){
        factors tmp = calc_f(A.at(i));
        chmin(min_two, tmp.two);
        chmin(min_three, tmp.three);
        set_other.insert(tmp.other);
        F.push_back(tmp);
    }
    if(set_other.size() > 1) cout << -1 << endl;
    else{
        ll ans = 0;
        for(factors fs:F){
            ans += fs.two - min_two;
            ans += fs.three - min_three;
        }
        cout << ans << endl;
    }
}