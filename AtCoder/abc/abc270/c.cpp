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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<V_L> graph(N, V_L{});
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back(v);
        graph.at(v).push_back(u);
    }


    stack<ll> sta;
    ll start = X;
    sta.push(start);
    ll n = graph.size();
    vector<ll> dist(n, -1); 
    vector<ll> prev(n, -1);
    dist.at(start) = 0;

    while(!sta.empty()){
        ll v = sta.top(); // キューから先頭頂点を取り出す
        sta.pop();
        for(ll next:graph.at(v)){
            // すでに訪れているなら次の探索候補に入れない
            if(dist.at(next) != -1) continue;
            sta.push(next);
            dist.at(next) = dist.at(v) + 1;
            prev.at(next) = v;
        }
    }

    ll tmp_prev = prev.at(Y);
    V_L ans{Y};
    while(tmp_prev != -1){
        ans.push_back(tmp_prev);
        tmp_prev = prev.at(tmp_prev);
    }

    reverse(ans.begin(), ans.end());
    for(ll a:ans){
        cout << a+1 << " ";
    }
    cout << endl;
}