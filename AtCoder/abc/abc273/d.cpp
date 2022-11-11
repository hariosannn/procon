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
    if (a[index] < key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key, vector<ll> &a) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    ll ok = -1; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(ll)a.size()
    ll ng = (ll)a.size(); //ng以上から右端が条件を必ず満たさないような場合(ll)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

// index が条件を満たすかどうか
bool isOK2(ll index, ll key, vector<ll> &a) {
    if (a[index] > key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search2(ll key, vector<ll> &a) {
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

        if (isOK2(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

struct coord
{
    ll r;
    ll c;
};

int main(){
    ll H, W, rs, cs, N, Q;
    cin >> H >> W >> rs >> cs;
    rs--;
    cs--;
    coord start = coord{rs, cs};
    cin >> N;

    map<ll, V_L> r_wall_map;
    map<ll, V_L> c_wall_map;

    rep(i, N){
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        r_wall_map[r].push_back(c);
        c_wall_map[c].push_back(r);
    }
    for(auto p:r_wall_map){
        V_L tmp = p.second;
        tmp.push_back(-1);
        tmp.push_back(W);
        sort(tmp.begin(), tmp.end());
        r_wall_map[p.first] = tmp;
    }
    for(auto p:c_wall_map){
        V_L tmp = p.second;
        tmp.push_back(-1);
        tmp.push_back(H);
        sort(tmp.begin(), tmp.end());
        c_wall_map[p.first] = tmp;
    }

    cin >> Q;
    coord current_c = start;
    rep(q, Q){
        char d;
        ll l;
        cin >> d >> l;
        if(d == 'R'){
            
            ll c_plus_l = min(ll(W-1), current_c.c + l);
            if(r_wall_map[current_c.r].size() == 0){
                current_c.c = c_plus_l;
            }
            else{
                ll next_wall = r_wall_map[current_c.r][binary_search2(current_c.c, r_wall_map[current_c.r])];
                ll next_wall_2 = r_wall_map[current_c.r][binary_search2(c_plus_l, r_wall_map[current_c.r])];
                current_c.c = min(next_wall, next_wall_2) -1;
                current_c.c = min(c_plus_l, current_c.c);
            }
        }
        else if(d == 'L'){
            ll c_plus_l = max(ll(0), current_c.c - l);
            if(r_wall_map[current_c.r].size() == 0){
                current_c.c = c_plus_l;
            }
            else{
                ll next_wall = r_wall_map[current_c.r][binary_search(current_c.c, r_wall_map[current_c.r])];
                ll next_wall_2 = r_wall_map[current_c.r][binary_search(c_plus_l, r_wall_map[current_c.r])];
                current_c.c = max(next_wall, next_wall_2) +1;
                current_c.c = max(c_plus_l, current_c.c);
            }
        }
        else if(d == 'D'){
            ll r_plus_l = min(ll(H-1), current_c.r + l);
            if(c_wall_map[current_c.c].size() == 0){
                current_c.r = r_plus_l;
            }
            else{
                ll next_wall = c_wall_map[current_c.c][binary_search2(current_c.r, c_wall_map[current_c.c])];
                ll next_wall_2 = c_wall_map[current_c.c][binary_search2(r_plus_l, c_wall_map[current_c.c])];
                current_c.r = min(next_wall, next_wall_2) -1;
                current_c.r = min(r_plus_l, current_c.r);
            }
        }
        else{
            ll r_plus_l = max(ll(0), current_c.r - l);
            if(c_wall_map[current_c.c].size() == 0){
                current_c.r = r_plus_l;
            }
            else{
                ll next_wall = c_wall_map[current_c.c][binary_search(current_c.r, c_wall_map[current_c.c])];
                ll next_wall_2 = c_wall_map[current_c.c][binary_search(r_plus_l, c_wall_map[current_c.c])];
                current_c.r = max(next_wall, next_wall_2) +1;
                current_c.r = max(r_plus_l, current_c.r);
            }
        }
        cout << current_c.r+1 << " " << current_c.c+1 << endl;
    }
}