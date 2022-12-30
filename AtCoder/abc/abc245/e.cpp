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

int looper_method_count_less_k(vector<int> &a, int k){//区間の合計がk以下の区間数を数える尺取り法
    int n = a.size(), ans = 0;
    int sum = 0;
    for (int l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; r < n && sum + a[r] <= k; r++){//条件を満たす限り右に進む
            sum += a[r];
        }
        ans += r - l; //[l, r)がk以下なのでr-l個が解として足される
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ans;
}

int main(){
    ll N, M;
    cin >> N >> M;
    V_L A(N), B(N), C(M), D(M);
    cin >> A >> B >> C >> D;
    vector<P_L> choko;
    map<ll, multiset<ll>> box;
    rep(i, N){
        choko.push_back(P_L{A.at(i), B.at(i)});
    }
    rep(i, M){
        box[C.at(i)].insert(D.at(i));
    }

    string ans = "Yes";
    rep(i, N){
        auto ite = box.lower_bound(choko.at(i).first);
        if(ite == box.end()){
            ans = "No";
            break;
        }
        auto& p = ite->second;
        auto ite2 = p.lower_bound(choko.at(i).second);
        if(ite2 == p.end()){
            ans = "No";
            break;
        }
        p.erase(ite2);
        if(p.size() == 0){
            box.erase(ite->first);
        }
    }
    cout << ans << endl;
}