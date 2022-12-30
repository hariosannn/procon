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
    V_L A(N);
    cin >> A;
    ll Q;
    cin >> Q;

    bool is_changed = false;
    ll base_num = -1;
    map<ll, ll> diff_num;
    rep(i, Q){
        ll ope;
        cin >> ope;
        if(ope == 1){
            ll x;
            cin >> x;
            if(!is_changed){
                is_changed = true;
            }
            base_num = x;
            map<ll, ll> tmp_map;
            diff_num = tmp_map;
        }
        else if(ope == 2){
            ll ind, x;
            cin >> ind >> x;
            ind--;
            diff_num[ind] += x;
        }
        else{
            ll ind;
            cin >> ind;
            ind--;
            if(!is_changed){
                cout << A.at(ind) + diff_num[ind] << endl;
            }
            else{
                cout << base_num + diff_num[ind] << endl;
            }
        }
    }
}