#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
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
    ll X;
    cin >> X;
    if(X <= 10){
        cout << X << endl;
        return 0;
    }
    string s_X = to_string(X);
    ll ans = LINF;
    V_L diff;
    rep(i, 19){
        diff.push_back(i-9);
    }
    for(int i=s_X.at(0)-'0'; i<10; i++){
        string tmp = "";
        ll tmp_score;
        int num;
        rep(j, diff.size()){
            tmp = "";
            rep(k, s_X.size()){
                num = i;
                num += diff.at(j)*k;
                if(num < 0) break;
                tmp.push_back(num+'0');
            }
            if((num >= 0) && (tmp.at(0)-'0' > 0)){
                tmp_score = stol(tmp);
                if(tmp_score >= X) chmin(ans, tmp_score);
            }
        }
    }
    if(ans != LINF) cout << ans << endl;
    else{
        rep(i, s_X.size()+1)
        cout << 1;
    }
    cout << endl;
}
