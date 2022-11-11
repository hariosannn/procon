#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

map<ll, ll> make_comb_list(ll N){
    // map[nC2] = n
    map<ll, ll> ret;
    ll tmp_c = 0;
    ll n = 2;
    while(tmp_c <= N){
        tmp_c = (n*(n-1))/2;
        ret[tmp_c] = n;
        n++;
    }    
    return ret;
}

int main(){
    ll N;
    cin >> N;
    map<ll, ll> comb_map = make_comb_list(N);
    if(comb_map[N] == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    ll node_n = comb_map[N];
    cout << node_n << endl;
    map<ll, V_L> node_numbers;
    ll counter = 1;
    rep(i, node_n){
        for(ll j=i+1; j<node_n; j++){
            node_numbers[i].push_back(counter);
            node_numbers[j].push_back(counter);
            counter++;
        }
    }
    for(auto v:node_numbers){
        cout << v.second.size() << " ";
        for(ll a:v.second){
            cout << a << " ";
        }
        cout << endl;
    }
}