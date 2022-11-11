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

bool is_same_VL(V_L &A, V_L B){
    rep(i, A.size()){
        if(A.at(i) != B.at(i)) return false;
    }
    return true;
}

int main(){
    ll N;
    cin >> N;
    V_L P(N), Q(N);
    cin >> P >> Q;
    V_L A;
    rep(i, N){
        A.push_back(i+1);
    }

    vector<V_L> Perm;
    do {
        Perm.push_back(A);
    } while (next_permutation(A.begin(), A.end()));

    sort(Perm.begin(), Perm.end());

    ll p_ind, q_ind;
    rep(i, Perm.size()){
        if(is_same_VL(Perm.at(i), P)){
            p_ind = i;
        }
        if(is_same_VL(Perm.at(i), Q)){
            q_ind = i;
        }
    }
    cout << abs(p_ind - q_ind) << endl;
    return 0;
}
