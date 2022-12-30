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
    ll N;
    cin >> N;
    V_L A(N), B(N);
    cin >> A >> B;
    
    set<ll> only_a;
    set<ll> only_b;
    set<ll> common;

    // map[a_ind] = min(b_ind), max(b_ind)
    map<ll, P_L> ans;
    rep(i, N){
        ans[i] = P_L{LINF, -LINF};
    }
    ll b_ind = 0;
    for(ll a_ind=0; a_ind<N; a_ind++){
        ll current_a = A.at(a_ind);
        if(common.find(current_a) == common.end()){
            only_a.insert(current_a);
        }
        else{
            ans[a_ind] = ans[a_ind-1];
        }

        for(; (b_ind<N) && ((common.find(B.at(b_ind)) != common.end()) ||
                            (only_a.find(B.at(b_ind)) != only_a.end())); b_ind++){
            ll current_b = B.at(b_ind);
            if(common.find(B.at(b_ind)) == common.end()){
                if(only_a.find(current_b) != only_a.end()){
                    only_a.erase(current_b);
                    common.insert(current_b);
                }
            }
            if((only_a.size() == 0)){
                ans[a_ind].first = min(ans[a_ind].first, b_ind);
                ans[a_ind].second = max(ans[a_ind].second, b_ind);
            }

        }
    }

    ll Q;
    cin >> Q;
    rep(i, Q){
        ll a_i, b_i;
        cin >> a_i >> b_i;
        a_i--;
        b_i--;
        if((ans[a_i].first <= b_i) && (b_i <= ans[a_i].second)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}