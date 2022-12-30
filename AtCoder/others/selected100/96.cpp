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
    V_L A;
    rep(i, 8){
        A.push_back(i);
    }
    ll K;
    cin >> K;
    map<ll, ll> r_to_c;
    rep(i, K){
        ll r, c;
        cin >> r >> c;
        r_to_c[r] = c;
    }

    vector<V_L> candidates;
    do {
        bool if_add = true;
        rep(i, 8){
            if(r_to_c.find(i) != r_to_c.end()){
                if(r_to_c[i] != A.at(i)) if_add = false;
            }
        }
        if(if_add) candidates.push_back(A);
    } while (next_permutation(A.begin(), A.end()));

    is_ok(tmp);
    for(auto v:candidates){
        if(is_ok(v)){
            rep(i, 8){
                rep(j, 8){
                    if(j == v.at(i)) cout << "Q";
                    else cout << ".";
                }
                cout << endl;
            }
            return 0;
        }
    }
}