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
    ll N, K;
    cin >> N >> K;

    map<ll, ll> decided;
    rep(i, K){
        ll d, r;
        cin >> d >> r;
        decided[d] = r;
    }

    map<queue<ll>, V_L> dp;
    vector<queue<ll>> keys;
    rep(i, 4){
        rep(j, 4){
            rep(k, 4){
                queue<ll> que;
                que.push(i);
                que.push(j);
                que.push(k);
                dp[que] = V_L(N+1, 0);
                keys.push_back(que);
            }
        }
    }

    set<queue<ll>> all_same;
    rep(i, 3){
        queue<ll> same_que;
        rep(j, 3) same_que.push(i+1);
        all_same.insert(same_que);
    }

    queue<ll> init_que;
    rep(i, 3) init_que.push(0);
    dp[init_que].at(0) = 1;

    for(ll day=1; day<=N; day++){
        for(auto key:keys){
            if(decided.find(day) != decided.end()){
                ll next = decided[day];
                queue<ll> last_3 = key;
                last_3.pop();
                last_3.push(next);
                if(all_same.find(last_3) != all_same.end()) continue;
                dp[last_3].at(day) += dp[key].at(day-1);
                dp[last_3].at(day) %= 10000;
            }
            else{
                for(ll next=1; next<4; next++){
                    queue<ll> last_3 = key;
                    last_3.pop();
                    last_3.push(next);
                    if(all_same.find(last_3) != all_same.end()) continue;
                    dp[last_3].at(day) += dp[key].at(day-1);
                    dp[last_3].at(day) %= 10000;
                }
            }
        }
    }

    ll ans = 0;
    for(auto p:dp){
        ans += p.second.at(N);
    }
    cout << ans%10000 << endl;
}