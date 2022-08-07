#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
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

struct coord
{
    int lx, ly, rx, ry;
};


int main(){
    map<int, int> M;
    set<int> S;
    rep(i, 5){
        int tmp;
        cin >> tmp;
        M[tmp] += 1;
        S.insert(tmp);
    }
    V_I unique;
    for(int a:S){
        unique.push_back(a);
    }
    string ans = "No";
    if((M[unique.at(0)] == 3) & (M[unique.at(1)] == 2)) ans="Yes";
    if((M[unique.at(0)] == 2) & (M[unique.at(1)] == 3)) ans="Yes";
    cout << ans << endl;
}