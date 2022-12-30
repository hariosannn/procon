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
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define reps(i, x) for (ll i = 1; i <= (ll)(x); i++)
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};
constexpr int DX2[] = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int DY2[] = {0, 1, 0, -1, 1, 1, -1, -1};
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}

/* compress
    X を座標圧縮して書き換える（副作用）
    返り値: ソート済みの値
    計算量: O(n log n)
*/
template <typename T>
void compress(vector<T> &X) {
    // ソートした結果を vals に
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
}
template <typename T>
struct SEGMENT_TREE {//segment木　※インデックスは1から始まる
    ll SEG_LEN;
    T init_val=0;
    vector<T> seg;
    SEGMENT_TREE(ll n_){ // 葉の数は 2^x の形
        ll x = 1;
        while (n_ > x) {
            x *= 2;
        }
        SEG_LEN = x;
        rep(i, SEG_LEN*2){
            seg.push_back(init_val);
        }
    }    


    void add(ll ind, T v){//値の更新を行う関数
        ind += SEG_LEN;
        seg[ind] += v;
        while(true){
            //親ノードへ
            ind /= 2;
            //一番上の親まで登ったらループ抜ける
            if(ind == 0) break;
            //合計なのでindの子nodeの合計を新たな値へ
            seg[ind] = seg[ind*2] + seg[ind*2 + 1];
        }
    }

    T sum(ll l, ll r){
        //半開区間で[l, r]を表すので[l, r+1)
        r += 1;
        l += SEG_LEN;
        r += SEG_LEN;
        T ans = 0;
        while(l < r){// 左右から登っていき、左右が出会ったら終了
            if(l % 2 == 1){
                ans += seg[l];
                l++;
            }
            l /= 2;
            if(r % 2 == 1){
                ans += seg[r-1];
                r--;
            }
            r /= 2;
        }
        return ans;
    }
};

// 転倒数を求める関数　転倒数はバブルソートでの最小交換回数に等しい
// max_A+1の長さのsegtreeが作られるためAの最大値が大きすぎる場合は事前に座標圧縮すること
ll inversion_num(V_L &A){
    ll N = A.size();
    ll seg_len = -LINF;
    for(ll a:A){
        chmax(seg_len, a);
    }
    seg_len ++;

    SEGMENT_TREE<ll> seg_t(seg_len);

    ll inv = 0;
    rep(i, N){
        seg_t.add(A.at(i), 1);
        inv += seg_t.sum(A.at(i)+1, seg_len-1);
    }
    return inv;
}


int main() {
    string S{"000"}, T{"000"};
    rep(i, 3) cin >> &S.at(i);
    rep(i, 3) cin >> &T.at(i);

    vector<P_L> P;
    map<char, ll> convert{{'R',1}, {'G',2}, {'B',3}};
    rep(i, S.size()){
        P_L tmp{convert[T.at(i)], convert[S.at(i)]};
        P.push_back(tmp);
    }
    sort(P.begin(), P.end());
    V_L S_v;
    rep(i, 3) S_v.push_back(P.at(i).second);
    if(inversion_num(S_v) %2 == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}