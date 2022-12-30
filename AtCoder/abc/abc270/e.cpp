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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

struct state{
    ll fetch_sum;
    ll left_bagage;
    ll zero_f;
};

int main(){
    ll N, K;
    cin >> N >> K;
    V_L A(N);
    cin >> A;

    map<ll, ll> f_map;
    ll left_bagage = 0;
    rep(i, N){
        if(A.at(i) > 0){
            left_bagage++;
            f_map[A.at(i)] += 1;
        }
    }

    vector<state> cycles{state{0, 0, 0}};
    ll n_cycles = 0;
    ll fetch_sum = 0;
    ll zero_f = 0;
    for(auto p:f_map){
        fetch_sum += (p.first-n_cycles)*left_bagage;
        cycles.push_back(state{fetch_sum, left_bagage, zero_f});
        left_bagage -= p.second;
        n_cycles += p.first-n_cycles;
        zero_f = p.first;
    }

    for(ll i=1; i<cycles.size(); i++){
        state cycle = cycles.at(i);
        state prev_cycle = cycles.at(i-1);
        if(cycle.fetch_sum >= K){
            ll left_K = K - prev_cycle.fetch_sum;
            rep(i, N){
                A.at(i) = max(ll(0), A.at(i) - cycle.zero_f);
            }
            ll amari = left_K%cycle.left_bagage;
            V_L left_ind;
            rep(i, N){
                A.at(i) = max(ll(0), A.at(i) - (left_K/cycle.left_bagage));
                if(A.at(i) > 0) left_ind.push_back(i);
            }
            left_K -= (left_K/cycle.left_bagage)*cycle.left_bagage;
            rep(a_ind, amari){
                A.at(left_ind.at(a_ind)) --;
            }
            break;
        }
    }
    for(ll a:A){
        cout << a << " ";
    }
    return 0;
}