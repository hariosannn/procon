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

         
ll combination(ll n, ll k) {
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

ll dist(ll start, ll left_end, ll right_end, string end_dir){
    ll ret = right_end - left_end;
    if(end_dir == "left"){
        ret += abs(start - right_end);
    }
    else{
        ret += abs(start - left_end);
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    map<ll, ll> left_end;
    map<ll, ll> right_end;
    set<ll> unique_num_set;
    rep(i, N){
        ll x, c;
        cin >> x >> c;
        if(left_end.find(c) == left_end.end()) left_end[c] = x;
        else left_end[c] = min(left_end[c], x);
        if(right_end.find(c) == right_end.end()) right_end[c] = x;
        else right_end[c] = max(right_end[c], x);
        unique_num_set.insert(c);
    }
    left_end[0] = 0;
    right_end[0] = 0;
    unique_num_set.insert(0);
    V_L unique_num(unique_num_set.begin(), unique_num_set.end());
    unique_num.push_back(0);
    vector<P_L> dp(right_end.size()+1, P_L{LINF, LINF});
    dp.at(0) = P_L{0, 0};
    rep(i, right_end.size()){
        ll current_num = unique_num.at(i);
        ll next_num = unique_num.at(i+1);
        dp.at(i+1).first = min(dist(left_end[current_num], left_end[next_num], right_end[next_num], "left") + dp.at(i).first, dp.at(i+1).first);
        dp.at(i+1).first = min(dist(right_end[current_num], left_end[next_num], right_end[next_num], "left") + dp.at(i).second, dp.at(i+1).first);
        dp.at(i+1).second = min(dist(left_end[current_num], left_end[next_num], right_end[next_num], "right") + dp.at(i).first, dp.at(i+1).second);
        dp.at(i+1).second = min(dist(right_end[current_num], left_end[next_num], right_end[next_num], "right") + dp.at(i).second, dp.at(i+1).second);
    } 
    cout << min(dp.at(right_end.size()).first, dp.at(right_end.size()).second) << endl;
}