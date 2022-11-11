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

struct road
{
    ll dist;
    ll time;
};

int main(){
    ll N, M;
    cin >> N >> M;

    vector<map<ll, road>> graph(N);
    rep(i, M){
        ll s, t, d, time;
        cin >> s >> t >> d >> time;
        s--;
        t--;
        graph.at(s)[t] = road{d, time};
        graph.at(t)[s] = road{d, time};
    }

    vector<vector<pair<ll, ll>>> dp(1<<N, vector<pair<ll, ll>>(N, pair<ll, ll>{LINF, 0}));
    dp.at(1).at(0) = pair<ll, ll>{0, 1};
    for(ll nbit=1; nbit<1<<N; nbit++){
        set<ll> visited;
        rep(place, N){
            if((nbit & (1<<place))) visited.insert(place);
        }
        rep(next, N){
            if(!(nbit & (1<<next))){
                for(ll last:visited){
                    if(graph.at(last).find(next) != graph.at(last).end()){
                        ll next_time = graph.at(last)[next].time;
                        ll next_dist = graph.at(last)[next].dist;
                        if(dp.at(nbit).at(last).first + next_dist > next_time) continue;
                        ll current_score = dp.at(nbit|(1<<next)).at(next).first;
                        ll new_score = dp.at(nbit).at(last).first + graph.at(last)[next].dist;
                        if(current_score == new_score) {
                            dp.at(nbit|(1<<next)).at(next).second += dp.at(nbit).at(last).second;
                        }
                        else if(current_score > new_score){
                            dp.at(nbit|(1<<next)).at(next) = pair<ll, ll>{new_score, dp.at(nbit).at(last).second};
                        }
                    }
                }
            }
        }
    }
    ll ans = LINF;
    ll num = 0;
    rep(last, N){
        if(graph.at(last).find(0) != graph.at(last).end()){
            ll next_time = graph.at(last)[0].time;
            ll next_dist = graph.at(last)[0].dist;
            if(dp.at((1<<N) - 1).at(last).first + next_dist > next_time) continue;
            chmin(ans, dp.at((1<<N) - 1).at(last).first + next_dist);
        }
    }

    rep(last, N){
        if(graph.at(last).find(0) != graph.at(last).end()){
            ll next_time = graph.at(last)[0].time;
            ll next_dist = graph.at(last)[0].dist;
            if(dp.at((1<<N) - 1).at(last).first + next_dist > next_time) continue;
            if(ans == dp.at((1<<N) - 1).at(last).first + next_dist){
                num += dp.at((1<<N) - 1).at(last).second;
            }
        }
    }
    if(ans == LINF) cout << "IMPOSSIBLE" << endl;
    else cout << ans << " "<< num << endl;
}