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
    ll H1, W1, C;
    cin >> H1 >> W1 >> C;
    vector<V_L> A1;
    rep(i, H1){
        V_L tmp(W1);
        cin >> tmp;
        A1.push_back(tmp);
    }
    vector<V_L> A2(W1, V_L(H1));
    rep(i, H1){
        rep(j, W1){
            A2.at(j).at(H1-i-1) = A1.at(i).at(j);
        }
    }
    vector<vector<V_L>> A_all = {A1, A2};
    ll ans = LINF;
    for(auto A:A_all){
        ll H = A.size();
        ll W = A.at(0).size();
        vector<V_L> dp(H, V_L(W, LINF));
        for(ll i=1; i<H; i++) dp.at(i).at(0) = min(dp.at(i-1).at(0), A.at(i-1).at(0) - C*(i-1));
        for(ll i=1; i<W; i++) dp.at(0).at(i) = min(dp.at(0).at(i-1), A.at(0).at(i-1) - C*(i-1));

        for(ll h=1; h<H; h++){
            for(ll w=1; w<W; w++){
                chmin(dp.at(h).at(w), dp.at(h-1).at(w));
                chmin(dp.at(h).at(w), dp.at(h).at(w-1));
                chmin(dp.at(h).at(w), A.at(h-1).at(w) - C*(h+w-1));
                chmin(dp.at(h).at(w), A.at(h).at(w-1) - C*(h+w-1));
            }
        }
        for(ll h=0; h<H; h++){
            for(ll w=0; w<W; w++){
                if(h==0 && w==0) continue;
                chmin(ans, A.at(h).at(w) + C*(h+w) + dp.at(h).at(w));
            }
        }
    }

    cout << ans << endl;
}