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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main(){
    ll N;
    cin >> N;
    set<string> S_set;
    bool is_comp = true;
    rep(i, N){
        string S;
        cin >> S;
        S_set.insert(S);
        if((S.at(0) != 'H') && (S.at(0) != 'D') && (S.at(0) != 'C') && (S.at(0) != 'S'))is_comp = false;
        if((S.at(1) != 'A') && (S.at(1) != '2') && (S.at(1) != '3') && 
           (S.at(1) != '4') && (S.at(1) != '5') && (S.at(1) != '6') &&
           (S.at(1) != '7') && (S.at(1) != '8') && (S.at(1) != '9') &&
           (S.at(1) != 'T') && (S.at(1) != 'J') && (S.at(1) != 'Q') && (S.at(1) != 'K'))is_comp = false;

    }
    if(is_comp){
        if(S_set.size() == N) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        cout << "No" << endl;
    }
}