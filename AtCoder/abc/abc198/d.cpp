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



int main(){
    vector<string> S;
    rep(i, 3){
        string tmp;
        cin >> tmp;
        S.push_back(tmp);
    }

    set<char> unique_char_set;
    rep(i, 3){
        for(char c:S.at(i)) unique_char_set.insert(c);
    }

    if(unique_char_set.size() > 10){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<char> unique_char;
    for(char c:unique_char_set) unique_char.push_back(c);

    V_L numbers;
    rep(i, 10) numbers.push_back(i);

    V_L pow10;
    rep(i, 3){
        ll tmp_pow10 = 1;
        rep(j, S.at(i).size()-1) tmp_pow10*= 10;
        pow10.push_back(tmp_pow10);
    }
    
    do {
        map<char, ll> c_to_num;
        rep(i, unique_char.size()){
            c_to_num[unique_char.at(i)] = numbers.at(i);
        }

        bool is_ok = true;
        V_L N;
        rep(i, 3){
            string s = S.at(i);
            ll tmp_N = 0;
            ll tmp_pow10 = pow10.at(i);
            if(c_to_num[s.at(0)] == 0){
                is_ok = false;
                break;
            }
            for(char c:s){
                tmp_N += (c_to_num[c])*tmp_pow10;
                tmp_pow10 /= 10;
            }
            N.push_back(tmp_N);
        }
        if(!is_ok) continue;
        if(N.at(0) + N.at(1) == N.at(2)){
            for(ll n:N) cout << n << endl;
            return 0;
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    cout << "UNSOLVABLE" << endl;
    return 0;
}