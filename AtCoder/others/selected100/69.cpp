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

int main(){
    ll N;
    cin >> N;
    vector<V_L> graph(N, V_L{});
    rep(i, N){
        ll u;
        ll k;
        cin >> u >> k;
        V_L tmp(k);
        cin >> tmp;
        rep(j, k){
            tmp.at(j) -= 1;
        }
        graph.at(u-1) = tmp;
    }

    ll start = 0;
    queue<ll> que;
    que.push(start);
    V_L dist(N, -1);
    dist.at(start) = 0;
    ll current_node;
    while(!que.empty()){
        current_node = que.front();
        que.pop();
        for(ll next_node:graph.at(current_node)){
            if(dist.at(next_node) != -1) continue;
            dist.at(next_node) = dist.at(current_node) + 1;
            que.push(next_node);
        }
    }

    rep(i, N){
        cout << i+1 << " " << dist.at(i) << endl;
    }
}