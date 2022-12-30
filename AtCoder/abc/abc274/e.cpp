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

struct state
{
    ll c_number;
    ll n_booster;
};

ld power_2(ll a){
    ld ret = 1;
    rep(i, a){
        ret *= 2;
    }
    return ret;
}
int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ld>> graph(N+M+1, vector<ld>(N+M+1, 0));
    vector<P_L> coords{P_L(0, 0)};
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        coords.push_back(P_L{x, y});
    }
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        coords.push_back(P_L{x, y});
    }
    rep(i, N+M+1){
        rep(j, N+M+1){
            ll x1 = coords.at(i).first;
            ll y1 = coords.at(i).second;
            ll x2 = coords.at(j).first;
            ll y2 = coords.at(j).second;
            if(i == j) continue;
            graph.at(i).at(j) = sqrt(ld(x1-x2)*(x1-x2) + ld(y1-y2)*(y1-y2));
        }
    }



    // dp[bit][last_node][num_booster] = min_cost
    vector<vector<vector<ld>>> dp((1<<(N+M+1)), vector<vector<ld>>(N+M+1, vector<ld>(M+1, LINF)));
    dp.at(0).at(0).at(0) = 0;
    for(ll bit_s=0; bit_s<(1<<(N+M+1)); bit_s++){
        rep(last_node, N+M+1){
            if(bit_s != 0 && !(bit_s & (1 << last_node))) continue;
            rep(next_node, N+M+1){
                if((bit_s & (1<<next_node)) != 0) continue;
                if(next_node == last_node) continue;
                rep(n_booster, M+1){
                    if(next_node > N){
                        if(n_booster == M) continue;
                        ld current_cost = dp.at((bit_s | (1<<next_node))).at(next_node).at(n_booster+1);
                        ld new_cost = dp.at(bit_s).at(last_node).at(n_booster) + graph.at(last_node).at(next_node)/power_2(n_booster);
                        if(current_cost > new_cost){
                            dp.at((bit_s | (1<<next_node))).at(next_node).at(n_booster+1) = new_cost;
                        }
                    }
                    else{
                        ld current_cost = dp.at((bit_s | (1<<next_node))).at(next_node).at(n_booster);
                        ld new_cost = dp.at(bit_s).at(last_node).at(n_booster) + graph.at(last_node).at(next_node)/power_2(n_booster);
                        if(current_cost > new_cost){
                            dp.at((bit_s | (1<<next_node))).at(next_node).at(n_booster) = new_cost;
                        }
                    }

                }
            }
        }
    }

    ld ans = LINF;
    for(ll bit_s=1; bit_s<(1<<(N+M+1)); bit_s++){
        if((((1<<(N+1))-1) & bit_s) == (1<<(N+1))-1){
            rep(n_booster, M+1){
                chmin(ans, dp.at(bit_s).at(0).at(n_booster));
            }
        }
    }
    cout << fixed << setprecision(12) << ans << endl;

}