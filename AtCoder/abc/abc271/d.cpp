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
    ll N, S;
    cin >> N >> S;
    vector<P_L> A;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        A.push_back(P_L{a, b});
    }
    
    // prev, turn_or_not
    vector<vector<pair<ll, char>>> dp(N+1, vector<pair<ll, char>>(S+1, P_L{-1, 'N'}));
    dp.at(0).at(0) = P_L{-1, 'H'};
    rep(i, N){
        rep(j, S+1){
            if((j-A.at(i).first >= 0) && (dp.at(i).at(j-A.at(i).first).second != 'N')){
                dp.at(i+1).at(j) = P_L{j-A.at(i).first, 'H'};
            }
            if((j-A.at(i).second >= 0) && (dp.at(i).at(j-A.at(i).second).second != 'N')){
                dp.at(i+1).at(j) = P_L{j-A.at(i).second, 'T'};
            }
        }
    }
    
    if(dp.at(N).at(S).second != 'N'){
        cout << "Yes" << endl;
        vector<char> ans;
        ll prev = S;
        rep(i, N){
            ans.push_back(dp.at(N-i).at(prev).second);
            prev = dp.at(N-i).at(prev).first;
        }
        reverse(ans.begin(), ans.end());
        for(char s:ans){
            cout << s;
        }
        cout << endl;
    }
    else{
        cout << "No" << endl;
    }
}