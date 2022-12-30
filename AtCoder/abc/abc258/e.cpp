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
    ll N, Q, X;
    cin >> N >> Q >> X;
    V_L W(N);
    cin >> W;
    ll w_sum = 0;
    rep(i, N){
        w_sum += W.at(i);
    }
    vector<V_L> doubling(60, V_L(N, 0));
    V_L d_first = looper_method_count_less_k(W, X, w_sum);
    doubling.at(0) = d_first;
    rep(i, 59){
        rep(j, N){
            doubling.at(i+1).at(j) = doubling.at(i).at(doubling.at(i).at(j));
        }
    }

    V_L ans = looper_method_counter(W, X, w_sum, 0);
    rep(i, Q){
        ll k;
        cin >> k;
        k--;
        ll last_ind=0;
        ll counter = 0;
        while(k>0){
            if(k%2 == 1) last_ind = doubling.at(counter).at(last_ind);
            k /= 2;
            counter++;
        }
        cout << ans.at(last_ind) << endl;
    }
}