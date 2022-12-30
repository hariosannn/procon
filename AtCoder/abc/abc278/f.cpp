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


int main(){
    ll N;
    cin >> N;
    vector<string> S;
    rep(i, N){
        string s;
        cin >> s;
        S.push_back(s);
    }

    vector<vector<bool>> dp((1<<N), vector<bool>(N, false));
    rep(i, N){
        dp.at(0).at(i) = false;
    }
    for(ll remain_bit=1; remain_bit<(1<<N); remain_bit++){
        rep(last_i, N){
            if(!((1<<last_i) & (remain_bit))) continue;
            bool is_win = false;
            rep(next_i, N){
                if(!((1<<next_i) & (remain_bit))) continue;
                if(S.at(next_i).at(0) == S.at(last_i).back()){
                    is_win = (is_win | dp.at(remain_bit - (1<<last_i)).at(next_i));
                }
            }
            dp.at(remain_bit).at(last_i) = (!is_win);
        }
    }

    bool first_win = false;
    rep(i, N){
        if(dp.at((1<<N)-1).at(i)){
            first_win = true;
        }
    }
    if(first_win){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
}