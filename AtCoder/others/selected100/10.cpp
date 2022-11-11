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

void reshape_puzzle(vector<V_L> &puzzle){
    ll H = puzzle.size();

    rep(v, 5){
        V_L next_col;
        rep(h, H){
            if(puzzle.at(h).at(v) != 0){
                next_col.push_back(puzzle.at(h).at(v));
            }
        }
        reverse(next_col.begin(), next_col.end());
        ll zero_fill_num = H-next_col.size();
        rep(i, zero_fill_num){
            next_col.push_back(0);
        }
        rep(i, next_col.size()){
            puzzle.at(H-i-1).at(v) = next_col.at(i);
        }
    }
}

int main(){
    while(true){
        ll H;
        cin >> H;
        if(H == 0) break;
        vector<V_L> puzzle(H, V_L(5, 0));
        rep(i, H){
            V_L tmp(5);
            cin >> tmp;
            puzzle.at(i) = tmp;
        }

        ll ans = 0;
        ll del_num;
        bool do_next;
        do
        {
            do_next = false;
            rep(i, H){
                for(ll j=0; j<5;){
                    del_num = 0;
                    ll k = j;
                    while((k<5) && (puzzle.at(i).at(j) == puzzle.at(i).at(k))){
                        k++;
                    }
                    del_num += k - j;
                    if((del_num >= 3) && (puzzle.at(i).at(j) != 0)){
                        do_next = true;
                        ans += del_num*puzzle.at(i).at(j);
                        for(ll del_ind=j; del_ind<k; del_ind++){
                            puzzle.at(i).at(del_ind) = 0;
                        }
                    }
                    j = k;
                }
            }
            reshape_puzzle(puzzle);
        } while (do_next);
        cout << ans << endl;
    }
}