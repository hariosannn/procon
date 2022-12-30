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

struct rect
{
    ll min_h, max_h, min_w, max_w;
};

int main(){
    ll H, W, N, h_len, w_len;
    cin >> H >> W >> N >> h_len >> w_len;
    vector<V_L> A;
    rep(i, H){
        V_L tmp(W);
        cin >> tmp;
        A.push_back(tmp);
    }

    set<ll> unique_n;
    rep(i, H){
        rep(j, W){
            unique_n.insert(A.at(i).at(j));
        }
    }
    ll unique_size = unique_n.size();

    map<ll, rect> min_square;
    for(ll num:unique_n){
        ll min_h=LINF, max_h=-LINF, min_w=LINF, max_w=-LINF;
        rep(i, H){
            rep(j, W){
                if(A.at(i).at(j) == num){
                    chmin(min_h, i);
                    chmax(max_h, i);
                    chmin(min_w, j);
                    chmax(max_w, j);
                }
            }
        }
        min_square[num] = rect{min_h, max_h, min_w, max_w};
    }

    rep(i, H-h_len+1){
        rep(j, W-w_len+1){
            ll delete_num = 0;
            for(auto p:min_square){
                rect tmp_reqt = p.second;
                if((tmp_reqt.min_h >= i) && (tmp_reqt.max_h <= i+h_len-1) 
                    && (tmp_reqt.min_w >= j) && (tmp_reqt.max_w <= j+w_len-1)){
                        delete_num++;
                }
            }
            cout << (unique_size - delete_num) << " ";
        }
        cout << endl;
    }
}