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

         
ll combination(ll n, ll k) {
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

void add_ab(string &S, ll left_a, ll left_b, ll K, ll max_size){
    if(S.size() == max_size) return;
    ll comb_select_a = combination(left_a-1 + left_b, left_b);
    if(K <= comb_select_a){
        S.push_back('a');
        left_a--;
        add_ab(S, left_a, left_b, K, max_size);
    }
    else{
        S.push_back('b');
        left_b--;
        K -= comb_select_a;
        add_ab(S, left_a, left_b, K, max_size);
    }
}

int main(){
    ll N;
    cin >> N;
    V_L A(N);
    cin >> A;

    // dp[saw_A_ind][add_num][remainder] = P_L{min(prev_ind), max(prev_ind)}
    vector<vector<V_L>> dp(N+1, vector<V_L>(N+1, V_L(200, 0)));
    // pre[saw_A_ind][add_num][remainder][0] = P_L{prev A_i, current_selected_Ai}
    vector<vector<vector<V_L>>> pre(N+1, vector<vector<V_L>>(N+1, vector<V_L>(200, V_L{})));
    dp.at(0).at(0).at(0) = 1;
    for(ll A_i=0; A_i<N; A_i++){
        rep(add_n, N){
            rep(rem, 200){
                ll add_comb = dp.at(A_i).at(add_n).at(rem);
                dp.at(A_i+1).at(add_n+1).at((rem+A.at(A_i))%200) += add_comb;
                dp.at(A_i+1).at(add_n+1).at((rem+A.at(A_i))%200) = min(ll(2), dp.at(A_i+1).at(add_n+1).at((rem+A.at(A_i))%200));
                if(add_comb > 0){
                    if(pre.at(A_i+1).at(add_n+1).at((rem+A.at(A_i))%200).size() < 2){
                        pre.at(A_i+1).at(add_n+1).at((rem+A.at(A_i))%200).push_back(A_i);
                    }
                }
                dp.at(A_i+1).at(add_n).at(rem) += add_comb;
                dp.at(A_i+1).at(add_n).at(rem) = min(ll(2), dp.at(A_i+1).at(add_n).at(rem));
                ll pre_i = 0;
                if(add_comb > 0){
                    while((pre.at(A_i+1).at(add_n).at(rem).size() < 2) &&
                        (pre_i < pre.at(A_i).at(add_n).at(rem).size())){
                        pre.at(A_i+1).at(add_n).at(rem).push_back(pre.at(A_i).at(add_n).at(rem).at(pre_i));
                    }
                }
            }
        }
    }
    return 0;
}