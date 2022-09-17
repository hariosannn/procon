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


int main(){
    ll N = 1048576;
    dsu uf(N);
    V_L A(N, -1);
    ll Q;
    cin >> Q;
    map<ll, ll> root_max;
    rep(i, N){
        root_max[i] = i;
    }
    rep(i, Q){
        ll t, x;
        cin >> t >> x;
        if(t == 1){
            ll ind = x%N;
            ll next = root_max[uf.leader(ind)]%N;
            ll max_ind = (next+1)%N;
            if(next-1 >= 0){
                if(A.at(next-1) != -1){
                    ll tes = uf.leader(ind);
                    uf.merge(next-1, ind);
                }
            }
            if(next+1 < N){
                if(A.at(next+1) != -1){
                    ll tes = uf.leader(ind);
                    max_ind = root_max[uf.leader(next+1)];
                    uf.merge(next+1, ind);
                }
            }
            A.at(next) = x;
            uf.merge(next, ind);
            root_max[uf.leader(ind)] = max_ind;
        }
        else{
            ll ind = x%N;
            cout << A.at(ind) << endl;
        }
    }
}