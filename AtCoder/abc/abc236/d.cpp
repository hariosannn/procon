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

void add_combination(set<ll> left, vector<vector<P_L>> &all_combinations, vector<P_L> current_combination){
    if(left.size() == 0){
        all_combinations.push_back(current_combination);
        return;
    }
    ll max_number = *left.rbegin();
    left.erase(max_number);
    set<ll> left_copy = left;
    for(ll p2: left_copy){
        current_combination.push_back(P_L{max_number, p2});
        left.erase(p2);
        add_combination(left, all_combinations, current_combination);
    }
    return;
}

int main(){
    ll N;
    cin >> N;
    vector<V_L> A(2*N, V_L(2*N, 0));
    rep(i, 2*N-1){
        V_L tmp(2*N - i -1);
        cin >> tmp;
        rep(j, tmp.size()){
            A.at(i).at(j+i+1) = tmp.at(j);
        }
    }

    vector<vector<P_L>> all_combinations;
    set<ll> left;
    vector<P_L> current_combinatinon;
    rep(i, 2*N){
        left.insert(i);
    }
    add_combination(left, all_combinations, current_combinatinon);

    ll ans = 0;
    for(auto V_P:all_combinations){
        ll tmp_ans = 0;
        for(auto p:V_P){
            tmp_ans ^= (A.at(p.second).at(p.first));
        }
        chmax(ans, tmp_ans);
    }

    cout << ans << endl;
    return 0;
}