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

ll need_money(V_L &A, V_L &S_v){
    ll ret = 0;
    ll max_height = A.at(0)-1;
    set<ll> S;
    for(ll s:S_v){
        S.insert(s);
    }
    rep(i, A.size()){
        if(S.find(i) != S.end()){
            if(max_height >= A.at(i)){
                ret += (max_height - A.at(i)) + 1;
                max_height += 1;
            }
            else{
                max_height = A.at(i);
            }
        }
        else{
            if(max_height < A.at(i)){
                max_height = A.at(i);
            }
        }
    }
    return ret;
}

int main(){
    ll H, W, K, V;
    cin >> H >> W >> K >> V;
    vector<V_L> ground(1, V_L(W+1, 0));
    rep(i, H){
        V_L tmp = {0};
        rep(j, W){
            ll a;
            cin >> a;
            tmp.push_back(a);
        }
        ground.push_back(tmp);
    }

    rep(i, H+1){
        rep(j, W){
            ground.at(i).at(j+1) = ground.at(i).at(j) + ground.at(i).at(j+1);
        }
    }

    rep(j, W+1){
        rep(i, H){
            ground.at(i+1).at(j) = ground.at(i+1).at(j) + ground.at(i).at(j);
        }
    }

    ll ans = 0;
    ll money = 0;
    rep(h1, H){
        for(ll h2=h1+1; h2<H+1; h2++){
            rep(w1, W){
                for(ll w2=w1+1; w2<W+1; w2++){
                    money = (h2 - h1)*(w2 - w1)*K + 
                            (ground.at(h2).at(w2) - ground.at(h1).at(w2)) - (ground.at(h2).at(w1) - ground.at(h1).at(w1));
                    if(money <= V) chmax(ans, (h2 - h1)*(w2 - w1));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}