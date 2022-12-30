#include <bits/stdc++.h>
using namespace std;
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

bool is_ok(V_L &A){
    map<P_L, ll> m_num;
    rep(i, 8){
        rep(dir, 8){
            P_L next{i, A.at(i)};
            while((next.first >= 0) && (next.first < 8) && (next.second >= 0) && (next.second < 8)){
                next.first += DX2[dir];
                next.second += DY2[dir];
                m_num[next] += 1;
            }
        }
    }
    bool ret = true;
    rep(i, 8){
        P_L tmp{i, A.at(i)};
        if(m_num[tmp] > 0) ret = false;
    }
    return ret;
}

int main(){
    ll N, Q;
    cin >> N;
    V_L A(N);
    cin >> A;

    set<ll> ans_set;
    rep(bit_num, (1<<N)){
        ll tmp_ans = 0;
        rep(i, N){
            if(bit_num & (1<<i)) tmp_ans += A.at(i);
        }
        ans_set.insert(tmp_ans);
    }
    cin >> Q;
    V_L Q_v(Q);
    cin >> Q_v;
    for(ll q:Q_v){
        if(ans_set.find(q) == ans_set.end()) cout << "no" << endl;
        else cout << "yes" << endl;
    }

}