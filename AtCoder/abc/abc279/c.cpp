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

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S, T;
    rep(i, H){
        string tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
    rep(i, H){
        string tmp;
        cin >> tmp;
        T.push_back(tmp);
    }
    map<vector<char>, ll> S_col, T_col;
    rep(i, W){
        vector<char> tmp;
        rep(j, H){
            tmp.push_back(S.at(j).at(i));
        }
        S_col[tmp]+=1;
    }
    rep(i, W){
        vector<char> tmp;
        rep(j, H){
            tmp.push_back(T.at(j).at(i));
        }
        T_col[tmp] +=1;
    }

    for(auto p:T_col){
        if(S_col.find(p.first) == S_col.end()){
            cout << "No" << endl;
            return 0;
        }
        S_col[p.first] -= p.second;
    }

    ll a_sum = 0;
    for(auto p:S_col){
        if(p.second < 0){
                        cout << "No" << endl;
            return 0;
        }
        a_sum += p.second;
    }
    if(a_sum == 0){
        cout << "Yes" << endl;
    }
    else{
            cout << "No" << endl;

    }
}