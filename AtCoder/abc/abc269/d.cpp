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

ll sum_v(V_L &a){
    ll ret=0;
    for(ll el:a){
        ret += el;
    }
    return ret;
}


void add_name(string X, vector<string> &s_perm, ll ind_s, ll s_sum ,ll underbar_sum, ll u_ind, ll N, set<string> &all_X){
    if(ind_s == N-1){
        X += s_perm.back();
        if((X.size() >= 3) && (X.size() <= 16))
        all_X.insert(X);
    }
    else{
        X += s_perm.at(ind_s);
        string tmp_X = X;
        for(ll i=1; i<=16 - s_sum - underbar_sum - (N-1-u_ind)+1; i++){
            tmp_X = X;
            rep(j, i){
                tmp_X += '_';
            }
            add_name(tmp_X, s_perm, ind_s+1, s_sum, underbar_sum+i, u_ind+1, N, all_X);
        }
    }
}

bool is_grid_in(set<pair<ll, ll>> &grid_set, ll i, ll j){
    return !(grid_set.find(pair<ll, ll>{i, j}) == grid_set.end());
}
int main(){
    ll N;
    cin >> N;
    set<pair<ll, ll>> grid;
    vector<pair<ll, ll>> grid_v;
    map<pair<ll, ll>, ll> grid_ind;

    rep(i, N){
        ll a,b;
        cin >> a >> b;
        grid.insert(pair<ll, ll>{a, b});
        grid_v.push_back(pair<ll, ll>{a, b});
        grid_ind[pair<ll, ll>{a, b}] = i;
    }
    dsu uf(N);
    vector<pair<ll, ll>> diff{pair<ll, ll>{-1, -1},
                              pair<ll, ll>{-1, 0},
                              pair<ll, ll>{0, -1},
                              pair<ll, ll>{0, 1},
                              pair<ll, ll>{1, 0},
                              pair<ll, ll>{1, 1}};
    rep(i, N){
        pair<ll, ll> tmp_grid = grid_v.at(i);
        for(auto diff_p:diff){
                if(is_grid_in(grid, tmp_grid.first+diff_p.first, tmp_grid.second+diff_p.second)){
                    uf.merge(i, grid_ind[pair<ll, ll>{tmp_grid.first+diff_p.first, tmp_grid.second+diff_p.second}]);
            }
        }
    }
    cout << uf.groups().size() << endl;
}