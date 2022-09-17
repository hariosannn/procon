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

//n以下の整数について最小の素因数を求めた結果の配列を返す
//min_factor[i]はiを割り切る最小の数（iの素因数のうち最小のもの）
//min_factor[i] == iならiは素数（i=0, 1のときを除く）
vector<ll> sieve(ll n){
    //素数候補を管理する配列
    vector<ll> min_factor(n+1);
    //2以上の数を一度素数候補に入れる
    for(ll i=0; i<=n; i++) min_factor[i] = i;
    //それぞれの数について最小の素因数を求める
    for(ll i=2; i*i<=n; i++){
        if(min_factor[i] == i){
            for(ll j=2; i*j<=n; j++){
                if(min_factor[i*j] > i){
                    min_factor[i*j] = i;
                }
            }
        }
    }
    return min_factor;
}

//配列min_factorを使ってmを素因数分解する
//配列ansにはmの素因数が小さい順に格納される
vector<ll> factor(vector<ll> &min_factor, ll m){
    vector<ll> ans;
    while(m > 1){
        ans.push_back(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}

int main(){
    ll N, M;
    cin >> N >> M;
    V_L A(N);
    cin >> A;
    V_L min_factor = sieve(1e5);
    set<ll> A_factors;
    rep(i, N){
        V_L tmp_f = factor(min_factor, A.at(i));
        for(ll a:tmp_f){
            A_factors.insert(a);
        }
    }
    set<ll> ans;
    rep(i, M){
        ans.insert(i+1);
    }
    for(ll p:A_factors){
        for(ll i=1; i*p <= M; i++){
            ans.erase(i*p);
        }
    }
    cout << ans.size() << endl;
    for(ll a:ans){
        cout << a << endl;
    }
    return 0;
}