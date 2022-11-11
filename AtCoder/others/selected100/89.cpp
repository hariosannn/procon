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

// 最大公約数
ll gcd(ll a, ll b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}

// 最大公約数(配列版)
ll gcd_arr(vector<ll> &a){
    ll n = a.size();
    ll ret = a.at(0);
    for(ll i=1; i<n; i++){
        ret = gcd(ret, a.at(i));
    }
    return ret;
}

// 最小公倍数(配列版)
ll lcm_arr(vector<ll>& a){
    ll n = a.size();
    ll ret = a.at(0);
    for(ll i=1; i<n; i++){
        ret = lcm(ret, a.at(i));
    }
    return ret;
}

int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> graph;
    rep(i, H){
        vector<char> tmp(W);
        cin >> tmp;
        graph.push_back(tmp);
    }
    map<char, ll> char_map{{0, 'J'}, {1, 'O'}, {2, 'I'}};
    vector<vector<vector<ll>>> sum_m(H+1, vector<vector<ll>>(W+1, V_L{0, 0, 0}));

    rep(h, H){
        rep(w, W){
            rep(c, 3){
                if(graph.at(h).at(w) == char_map[c]) sum_m.at(h+1).at(w+1).at(c) = 1;
            }
        }
    }
    rep(h, H+1){
        rep(w, W){
            rep(c, 3){
                sum_m.at(h).at(w+1).at(c) = sum_m.at(h).at(w+1).at(c) + sum_m.at(h).at(w).at(c);
            }
        }
    }
    rep(w, W+1){
        rep(h, H){
            rep(c, 3){
                sum_m.at(h+1).at(w).at(c) = sum_m.at(h+1).at(w).at(c) + sum_m.at(h).at(w).at(c);
            }
        }
    }
    rep(i, K){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        rep(land, 2){
            cout << sum_m.at(c).at(d).at(land) - (sum_m.at(a-1).at(d).at(land) + sum_m.at(c).at(b-1).at(land)) + sum_m.at(a-1).at(b-1).at(land) << " ";
        }
        cout << sum_m.at(c).at(d).at(2) - (sum_m.at(a-1).at(d).at(2) + sum_m.at(c).at(b-1).at(2)) + sum_m.at(a-1).at(b-1).at(2);
        cout << endl;
    }
} 