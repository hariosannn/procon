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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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


map<int, int> looper_method_count_less_k(vector<ll> &a, ll k){//区間の合計がk以下の区間数を数える尺取り法
    ll n = a.size(), ans = 0;
    ll sum = 0;
    map<int, int> ret;
    for (int l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; r < n && sum + a[r] <= k; r++){//条件を満たす限り右に進む
            sum += a[r];
        }
        if(sum == k) ret[l] = r;
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ret;
}

int main(){
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;
    V_L A(N);
    cin >> A;

    map<int, int> map_p = looper_method_count_less_k(A, P);
    map<int, int> map_q = looper_method_count_less_k(A, Q);
    map<int, int> map_r = looper_method_count_less_k(A, R);

    string ans = "No";
    for(auto p:map_p){
        if(map_q.find(p.second) != map_q.end()){
            int next = map_q[p.second];
            if(map_r.find(next) != map_r.end()){
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
}