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

V_L looper_method_count_less_k(vector<ll> &a, ll k, ll a_sum){//区間の合計がk以下の区間数を数える尺取り法
    ll n = a.size();
    V_L ret;
    ll sum = 0;
    sum += (k/a_sum)*a_sum;
    for (ll l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; sum + a[r%n] < k; r++){//条件を満たす限り右に進む
            sum += a[r%n];
        }
        ret.push_back((r + 1)%n); //[l, r)がk以下なのでr-l個が解として足される
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ret;
}

V_L looper_method_counter(vector<ll> &a, ll k, ll a_sum, ll ind){//区間の合計がk以下の区間数を数える尺取り法
    ll n = a.size();
    V_L ret;
    ll sum = 0;
    sum += (k/a_sum)*a_sum;
    ll init_ret = (k/a_sum)*n;
    ll counter = 0;
    for (ll l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; sum + a[r%n] < k; r++){//条件を満たす限り右に進む
            counter++;
            sum += a[r%n];
        }
        ret.push_back(counter + init_ret + 1); //[l, r)がk以下なのでr-l個が解として足される
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
        counter--;
    }
    return ret;
}

int main(){
    ll N, M;
    cin >> N >> M;
    V_L S(N-1);
    cin >> S;
    V_L X(M);
    cin >> X;

    V_L diff{0};
    unordered_map<ll, ll> odd_diff;
    unordered_map<ll, ll> even_diff;
    even_diff[0] = 1;
    rep(i, N-1){
        if(i%2 == 0) odd_diff[S.at(i) - diff.back()] += 1;
        else even_diff[S.at(i) - diff.back()] += 1;
        diff.push_back(S.at(i) - diff.back());
    }

    unordered_map<ll, ll> init_list;
    for(ll x:X){
        rep(i, N){
            if(i%2 == 0){
                init_list[x-diff.at(i)] += 1;
            }
            else{
                init_list[-x+diff.at(i)] += 1;
            }
        }
    }

    ll ans = 0;
    for(auto p:init_list){
        chmax(ans, p.second);
    }
    cout << ans << endl;
}