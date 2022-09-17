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

// index が条件を満たすかどうか
bool isOK(ll index, ll key, vector<ll> &a) {
    if (a[index] > key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key, vector<ll> &a) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = (ll)a.size(); //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = -1; //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

string map_to_str(map<ll, ll> &m){
    string ret = "";
    for(auto p:m){
        ret += to_string(p.second);
        ret += "_";
    }   
    return ret;
}
int main(){
    ll N;
    cin >> N;
    map<ll, V_L> all_p;
    vector<vector<pair<ll, ll>>> ps;
    rep(i, N){
        ll m;
        cin >> m;
        vector<pair<ll, ll>> tmp_ps;
        rep(j, m){
            ll p, e;
            cin >> p >> e;
            all_p[p].push_back(e);
            tmp_ps.push_back(pair<ll, ll>{p, e});
        }
        ps.push_back(tmp_ps);
    }

    map<ll, ll> max_ans;
    map<ll, pair<ll, ll>> p_max1_max2;
    for(auto &es:all_p){
        all_p[es.first].push_back(0);
        sort(all_p[es.first].begin(), all_p[es.first].end());
        p_max1_max2[es.first] = pair<ll, ll>{all_p[es.first].at(all_p[es.first].size()-1), all_p[es.first].at(all_p[es.first].size()-2)};
        max_ans[es.first] = all_p[es.first].back();
    }

    set<map<ll, ll>> lcm_diffs;
    rep(i, N){
        map<ll, ll> tmp_lcm_diff;
        for(auto p:ps.at(i)){
            ll p_val = p.first;
            ll p_num = p.second;
            if(p_num == p_max1_max2[p_val].first){
                if(p_max1_max2[p_val].second - p_num < 0){
                    tmp_lcm_diff[p_val] = p_max1_max2[p_val].second;
                }
            }
        }
        lcm_diffs.insert(tmp_lcm_diff);
    }

    cout << lcm_diffs.size() << endl;
}