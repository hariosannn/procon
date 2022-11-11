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

ll horizontal_calc(V_L &A, ll K){
    ll score = 0;
    ll N = A.size();
    for(int i=0; i<N;){
        int j=i;
        while((j<N) && (A.at(i) == A.at(j))){
            j++;
        }
        if((j-i) >= K){
            if(A.at(i) != -1) score += (j-i)*A.at(i);
            for(int k=i; k<j; k++){
                A.at(k) = -1;
            }
        }
        i = j;
    }
    return score;
}

V_L vertical_calc(V_L &A){
    ll N = A.size();
    V_L ret(N, -1);
    ll ind = N-1;
    rep(i, N){
        if(A.at(N-i-1) != -1){
            ret.at(ind) = A.at(N-i-1);
            ind--;
        }
    }
    return ret;
}

ll reshape_puzzle(vector<V_L> &puzzle, ll K){
    ll H = puzzle.size();
    ll W = puzzle.at(0).size();
    ll total_score = 0;
    ll tmp_score;
    ll vanish_counter = 0;
    do
    {
        tmp_score = 0;
        rep(h, W){
            V_L tmp_row;
            rep(v, H){
                tmp_row.push_back(puzzle.at(v).at(h));
            }
            V_L next_row = vertical_calc(tmp_row);
            rep(j, H){
                puzzle.at(j).at(h) = next_row.at(j);
            }
        }

        rep(v, H){
            ll add_score = horizontal_calc(puzzle.at(v), K);
            tmp_score += add_score;
        }
        rep(i, vanish_counter){
            tmp_score *= 2;
        }
        vanish_counter++;
        total_score += tmp_score;
    } while (tmp_score > 0);
    return total_score;
}

int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    vector<V_L> puzzle;
    rep(i, H){
        string S;
        cin >> S;
        V_L tmp;
        for(char c:S){
            tmp.push_back(c-'0');
        }
        puzzle.push_back(tmp);
    }

    ll ans = 0;
    rep(i, H){
        rep(j, W){
            vector<V_L> tmp_puzzle = puzzle;
            tmp_puzzle.at(i).at(j) = -1;
            ll tmp_ans = reshape_puzzle(tmp_puzzle, K);
            chmax(ans, tmp_ans);
        }
    }
    cout << ans << endl;
}