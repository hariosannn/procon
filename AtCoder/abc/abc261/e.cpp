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

void into_bit(ll n, vector<bool> &V){
    ll counter = 0;
    while(n > 0){
        if(n%2 == 1){
            V.at(counter) = true;
        }
        n /= 2;
        counter++;
    }
}

ll int_from_bit(vector<bool> &V){
    ll ret = 0;
    ll pow_2 = 1;
    rep(i, V.size()){
        if(V.at(i)) ret += pow_2;
        pow_2 *= 2;
    }
    return ret;
}

int main(){
    ll N, C;
    cin >> N >> C;
    ll bit_size = 31;
    // f_map[n step][1 or 0][n bit] = ?
    vector<vector<vector<bool>>> f_map(N+1, vector<vector<bool>>(2, vector<bool>(bit_size, false)));
    f_map.at(0).at(1) = vector<bool>(bit_size, true);

    rep(n_step, N){
        ll t, a;
        cin >> t >> a;
        rep(input_bool, 2){
            vector<bool> a_bit(bit_size, false);
            into_bit(a, a_bit);
            vector<bool> next_bit(bit_size, false);
            vector<bool> current_bit = f_map.at(n_step).at(input_bool);
            rep(i, bit_size){
                if(t == 1){
                    next_bit.at(i) = current_bit.at(i) && a_bit.at(i);
                }
                else if(t == 2){
                    next_bit.at(i) = current_bit.at(i) || a_bit.at(i);
                }
                else{
                    next_bit.at(i) = current_bit.at(i) ^ a_bit.at(i);
                }
            }
            f_map.at(n_step+1).at(input_bool) = next_bit;
        }
    }

    vector<bool> c_bit(bit_size, false);
    into_bit(C, c_bit);
    vector<bool> prev_ans_bit = c_bit;

    rep(n_step, N){
        vector<bool> ans_bit(bit_size, false);
        rep(i, bit_size){
            if(!prev_ans_bit.at(i)){
                ans_bit.at(i) = f_map.at(n_step+1).at(0).at(i);
            }
            else{
                ans_bit.at(i) = f_map.at(n_step+1).at(1).at(i);
            }
        }
        cout << int_from_bit(ans_bit) << endl;
        prev_ans_bit = ans_bit;
    }
}