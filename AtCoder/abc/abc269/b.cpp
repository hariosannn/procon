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

int main(){
    vector<string> S;
    rep(i, 10){
        string tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
    ll A, B, C, D;
    bool finish = false;
    rep(i, 10){
        rep(j, 10){
            if(S.at(i).at(j)=='#'){
                A = i+1;
                finish=true;
                break;
            }
        }
        if(finish) break;
    }
    finish = false;
    rep(i, 10){
        rep(j, 10){
            if(S.at(10-i-1).at(j)=='#'){
                B = 10-i;
                finish=true;
                break;
            }
        }
        if(finish) break;
    }

    finish = false;
    rep(i, 10){
        rep(j, 10){
            if(S.at(i).at(j)=='#'){
                C = j+1;
                finish=true;
                break;
            }
        }
        if(finish) break;
    }

    finish = false;
    rep(i, 10){
        rep(j, 10){
            if(S.at(i).at(10-j-1)=='#'){
                D = 10-j;
                finish=true;
                break;
            }
        }
        if(finish) break;
    }
    cout << A << " " << B << endl;
    cout << C << " " << D<<endl;
}