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

constexpr int DX_H_even[] = {1, 0, -1, -1, -1, 0};
constexpr int DY_H_even[] = {0, -1, -1, 0, 1, 1};
constexpr int DX_H_odd[] = {1, 1, 0, -1, 0, 1};
constexpr int DY_H_odd[] = {0, -1, -1, 0, 1, 1};

int main(){
    ll W, H;
    cin >> W >> H;
    vector<V_L> Hex(1, V_L(W+2, 0));
    rep(i, H){
        V_L tmp{0};
        rep(j, W){
            ll a;
            cin >> a;
            tmp.push_back(a);
        }
        tmp.push_back(0);
        Hex.push_back(tmp);
    }
    Hex.push_back(V_L(W+2, 0));

    vector<V_L> graph((H+2)*(W+2), V_L{});
    rep(i, H+2){
        rep(j, W+2){
            rep(k, 6){
                ll next_x = j;
                ll next_y = i;
                if(i%2 == 0){
                    next_x += DX_H_even[k];
                    next_y += DY_H_even[k];
                }
                else{
                    next_x += DX_H_odd[k];
                    next_y += DY_H_odd[k];
                }
                if((next_x < 0) || (next_y < 0) || (next_x >= W+2) || (next_y >= H+2)) continue;
                graph.at(i*(W+2)+j).push_back(next_y*(W+2)+next_x);

            }
        }
    }

    ll ans = 0;
    queue<ll> que;
    ll start = 0;
    que.push(start);
    ll n = graph.size();
    vector<ll> dist(n, -1); 
    dist.at(start) = 0;

    while(!que.empty()){
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        for(ll next:graph.at(v)){
            if(Hex.at(next/(W+2)).at(next%(W+2)) == 1){
                ans ++;
                dist.at(next) = dist.at(v) + 1;
            }
            // すでに訪れているなら次の探索候補に入れない
            if(dist.at(next) != -1) continue;
                que.push(next);
                dist.at(next) = dist.at(v) + 1;
        }
    }

    cout << ans << endl;
}