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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}
 
int main()
{
    string S;
    cin >> S;
    vector<string> pins{string{S.at(6)}, string{S.at(3)}, string{S.at(1), S.at(7)}, 
                        string{S.at(0), S.at(4)}, string{S.at(2), S.at(8)}, string{S.at(5)}, string{S.at(9)}};
    bool is_one = S.at(0) == '0';
    if(!is_one) {
        cout << "No" << endl;
        return 0;
    }
    V_L all_down;
    V_L not_all_down;

    rep(i, 7){
        bool alld = true;
        for(char c:pins.at(i)){
            if(c == '1') alld = false;
        }
        if(alld) all_down.push_back(i);
        else not_all_down.push_back(i);
    }

    for(ll i=1; i<6; i++){
        auto result = find(all_down.begin(), all_down.end(), i);
        if(result != all_down.end()){
            bool left_both_alive = false;
            for(ll j=i-1; j>=0; j--){
                result = find(not_all_down.begin(), not_all_down.end(), j);
                if(result != not_all_down.end()) left_both_alive = true;
            }
            bool right_both_alive = false;
            for(ll j=i+1; j<7; j++){
                result = find(not_all_down.begin(), not_all_down.end(), j);
                if(result != not_all_down.end()) right_both_alive = true;
            }
            if(right_both_alive && left_both_alive){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
 