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
    ll N;
    cin >> N;
    ll A = 1000;
    vector<vector<ll>> M(A+1, V_L(A+1, 0));

    rep(i, N){
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        ly = A-ly;
        ry = A-ry;
        M.at(ry).at(lx) = M.at(ry).at(lx)+ 1;
        M.at(ly).at(lx) = M.at(ly).at(lx)- 1;
        M.at(ry).at(rx) = M.at(ry).at(rx) - 1;
        M.at(ly).at(rx) = M.at(ly).at(rx) + 1;
    }

    for(ll i=0; i<A+1; i++){
        ll tmp_s = 0;
        for(ll j=0; j<A+1; j++){
            tmp_s += M.at(i).at(j);
            M.at(i).at(j) = tmp_s;
        }
    }
    for(ll i=0; i<A+1; i++){
        ll tmp_s = 0;
        for(ll j=0; j<A+1; j++){
            tmp_s += M.at(j).at(i);
            M.at(j).at(i) = tmp_s;
        }
    }

    map<ll, ll> area;
    rep(i, N){
        area[i+1] = 0;
    }

    for(ll i=0; i<A; i++){
        for(ll j=0; j<A; j++){
            if(M.at(i).at(j) != 0){
                area[M.at(i).at(j)] += 1;
            }
        }
    }

    for(auto p:area){
        cout << p.second << endl;
    }

}