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
    ll H, W;
    cin >> H >> W;
    vector<V_L> A;
    rep(i, H){
        string tmp_S;
        cin >> tmp_S;
        V_L tmp;
        for(char c:tmp_S){
            if(c == '+') tmp.push_back(1);
            else tmp.push_back(-1);
        }
        A.push_back(tmp);
    }

    // takahashi - aoki
    vector<V_L> dp(H, V_L(W, 0));
    rep(i, H){
        rep(j, W){
            if((i+j)%2 == 0) dp.at(i).at(j) = -LINF;
            else dp.at(i).at(j) = LINF;
        }
    }
    dp.at(H-1).at(W-1) = 0;
    for(ll h=H-1; h>=0; h--){
        for(ll w=W-1; w>=0; w--){
            // takahashi turn
            if((h+w)%2 == 0){
                if(h+1 < H) chmax(dp.at(h).at(w), dp.at(h+1).at(w) + A.at(h+1).at(w));
                if(w+1 < W) chmax(dp.at(h).at(w), dp.at(h).at(w+1) + A.at(h).at(w+1));
            }
            //aoki turn
            else{
                if(h+1 < H) chmin(dp.at(h).at(w), dp.at(h+1).at(w) - A.at(h+1).at(w));
                if(w+1 < W) chmin(dp.at(h).at(w), dp.at(h).at(w+1) - A.at(h).at(w+1));
            }
        }
    }
    if(dp.at(0).at(0) < 0) cout << "Aoki" << endl;
    else if(dp.at(0).at(0) > 0) cout << "Takahashi" << endl;
    else cout << "Draw" << endl;
}