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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    cin >> S;
    sort(S.begin(), S.end());
    ll s_sum = 0;
    for(string s:S){
        s_sum += s.size();
    }
    vector<vector<string>> S_perm;
    do {
        S_perm.push_back(S);
    } while (next_permutation(S.begin(), S.end()));

    set<string> all_s;
    for(auto s_p:S_perm){
        add_name("", s_p, 0, s_sum, 0, 0, N, all_s);
    }
    
    rep(i, M){
        string t;
        cin >> t;
        all_s.erase(t);
    }

    if(all_s.size() == 0){
        cout << -1 << endl;
    }
    else{
        cout << *all_s.begin() << endl;
    }
    return 0;
}