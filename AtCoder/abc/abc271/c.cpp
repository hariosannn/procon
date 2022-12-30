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
    V_L A(N);
    cin >> A;

    set<ll> A_set;
    rep(i, N){
        A_set.insert(A.at(i));
    }
    deque<ll> A_sort;
    for(ll a:A_set){
        A_sort.push_back(a);
    }
    ll amari = A.size() - A_set.size();
    rep(i, amari){
        A_sort.push_back(2000000000 + i + 1);
    }
    ll ans;
    for(ll i=1; i<=N; i++){
        if(i != A_sort.front()){
            rep(sell, 2){
                if(A_sort.size() == 0){
                    cout << i-1 << endl;
                    return 0;
                }
                A_sort.pop_back();
            }
        }
        else{
            A_sort.pop_front();
        }
        if(A_sort.size() == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << ans << endl;
}