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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int dist(pair<int, int> p1, pair<int, int> p2){
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

bool is_vert(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    pair<int, int> diff1, diff2;
    diff1.first = (p2.first - p1.first);
    diff2.first = (p3.first - p2.first);
    diff1.second = (p2.second - p1.second);
    diff2.second = (p3.second - p2.second);
    return ((diff1.first * diff2.first + diff1.second * diff2.second) == 0);
}
int main(){
    set<set<pair<int, int>>> squares;

    vector<pair<int, int>> coords;
    rep(i, 9){
        rep(j, 9){
            coords.push_back(pair<int, int>{i, j});
        }
    }
    rep(i, 81){
        rep(j, 81){
            rep(k, 81){
                rep(l, 81){
                    if((i==j) || (i==k) || (i==l) || (j==k) || (j==l) || (k==l)) continue;
                    if((dist(coords.at(i), coords.at(j)) == dist(coords.at(j), coords.at(k))) && 
                       (dist(coords.at(j), coords.at(k)) == dist(coords.at(k), coords.at(l))) && 
                       (dist(coords.at(k), coords.at(l)) == dist(coords.at(l), coords.at(i)))){
                        if(is_vert(coords.at(i), coords.at(j), coords.at(k))){
                            squares.insert(set<pair<int, int>>{coords.at(i), coords.at(j), coords.at(k), coords.at(l)});
                        }
                       }

                }
            }
        }
    }
    vector<vector<char>> graph;
    rep(i, 9){
        vector<char> tmp(9);
        cin >> tmp;
        graph.push_back(tmp);
    }

    ll ans = 0;
    for(auto v_c:squares){
        bool is_filled = true;
        for(auto v:v_c){
            if(graph.at(v.first).at(v.second) == '.') is_filled = false;
        }
        if(is_filled) ans++;
    }
    cout << ans << endl;
}

