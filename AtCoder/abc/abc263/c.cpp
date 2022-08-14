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
set<int> factor(vector<int> &min_factor, int m){
    set<int> ans;
    while(m > 1){
        ans.insert(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}


int gcd(int a, int b){
    while((a > 0) && (b > 0)){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }    
    return max(a, b);
}

int main(){
    int N;
    cin >> N;
    V_I A(N);
    cin >> A;

    bool pair_p = true;
    bool set_p = true;

    V_I min_factor = sieve(1e6);
    map<int, int> factor_map;
    rep(i, N){
        set<int> tmp_factor = factor(min_factor, A.at(i));
        for(int f:tmp_factor){
            factor_map[f] += 1;
        }
    }
    for(auto p:factor_map){
        if(p.second > 1){
            pair_p = false;
        }
    }
    int tmp_gcd = A.at(0);
    for(int i=1; i<N; i++){
        tmp_gcd = gcd(A.at(i), tmp_gcd);
    }
    if(tmp_gcd != 1){
        set_p = false;
    }
    if(pair_p){
        cout << "pairwise coprime" << endl;
    }
    else if(set_p){
        cout << "setwise coprime" << endl;
    }
    else{
        cout << "not coprime" << endl;
    }
}
