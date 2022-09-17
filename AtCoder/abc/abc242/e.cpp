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


mint fast_pow(mint x, ll n) {
    mint ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

mint calc_palindrome_num(string S, ll ind){
    if(ind == (S.size()-1)/2){
        mint ret = 0;
        string tmp_S = S;
        rep(i, ind+1){
            tmp_S.at(tmp_S.size()-i-1) = tmp_S.at(i);
        }
        if(tmp_S.size() %2 == 0){
            rep(i, 26){
                tmp_S.at(ind) = char('A' + i);
                tmp_S.at(ind+1) = char('A' + i);
                if(tmp_S <= S) ret++;
            }
        }
        else{
            rep(i, 26){
                tmp_S.at(ind) = char('A' + i);
                if(tmp_S <= S) ret++;
            }
        }
        return ret;
    }
    else{
        mint ret = 0;
        ret += S.at(ind) - 'A';
        if(S.size() % 2 == 0) ret *= fast_pow(26, (S.size()-2*ind-2)/2);
        else ret *= fast_pow(26, (S.size()-2*ind - 1)/2);
        ret += calc_palindrome_num(S, ind+1);
        return ret;
    }
}

int main(){
    ll T;
    cin >> T;
    rep(i, T){
        ll N;
        string S;
        cin >> N >> S;
        calc_palindrome_num(S, 0);
        cout << calc_palindrome_num(S, 0).val() << endl;
    }
}