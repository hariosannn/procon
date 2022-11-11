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

//n以下の整数について最小の素因数を求めた結果の配列を返す
//min_factor[i]はiを割り切る最小の数（iの素因数のうち最小のもの）
//min_factor[i] == iならiは素数（i=0, 1のときを除く）
vector<int> sieve(int n){
    //素数候補を管理する配列
    vector<int> min_factor(n+1);
    //2以上の数を一度素数候補に入れる
    for(int i=0; i<=n; i++) min_factor[i] = i;
    //それぞれの数について最小の素因数を求める
    for(int i=2; i*i<=n; i++){
        if(min_factor[i] == i){
            for(int j=2; i*j<=n; j++){
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
vector<int> factor(vector<int> &min_factor, int m){
    vector<int> ans;
    while(m > 1){
        ans.push_back(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}

int main(){
    ll Q;
    cin >> Q;

    vector<int> min_factor = sieve(100000);
    V_L is_prime(100001);
    for(int i=2;i<=100000; i++){
        if(i%2 == 0) continue;
        vector<int> primes1 = factor(min_factor, i);
        vector<int> primes2 = factor(min_factor, (i+1)/2);

        if((primes1.size() == 1) && (primes2.size() == 1)) is_prime.at(i) = 1;
    }

    V_L prime_sum(100002, 0);
    rep(i, 100001){
        prime_sum.at(i+1) = prime_sum.at(i) + is_prime.at(i);
    }

    rep(i, Q){
        ll l, r;
        cin >> l >> r;
        cout << prime_sum.at(r+1) - prime_sum.at(l) << endl;
    }
}