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

struct coord
{
    ll x;
    ll y;
};

bool operator<(const coord& a, const coord& b) {
    if(a.x != b.x){
        return a.x < b.x;
    } 
    else return a.y < b.y; 
    }

int main(){
    ll N;
    cin >> N;
    vector<coord> P;

    set<coord> P_set;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        P.push_back(coord{x, y});
        P_set.insert(coord{x, y});
    }

    ll ans = 0;
    rep(i, N){
        rep(j, N){
            coord p1 = P.at(i);
            coord p2 = P.at(j);
            if(p1.x > p2.x) swap(p1, p2);
            if(p1.y > p2.y){
                ll a = p2.x - p1.x;
                ll b = p1.y - p2.y;
                coord p3 = coord{p1.x - b, p1.y - a};
                coord p4 = coord{p1.x - b + a, p1.y -a -b};
                if((P_set.find(p3) != P_set.end()) && (P_set.find(p4) != P_set.end())){
                    chmax(ans, a*a + b*b);
                }
                coord p5 = coord{p1.x + b, p1.y + a};
                coord p6 = coord{p1.x + b + a, p1.y + a -b};
                if((P_set.find(p5) != P_set.end()) && (P_set.find(p6) != P_set.end())){
                    chmax(ans, a*a + b*b);
                }
            } 
            else{
                ll a = p2.x - p1.x;
                ll b = p2.y - p1.y;
                coord p3 = coord{p1.x + b, p1.y - a};
                coord p4 = coord{p1.x + b + a, p1.y -a + b};
                if((P_set.find(p3) != P_set.end()) && (P_set.find(p4) != P_set.end())){
                    chmax(ans, a*a + b*b);
                }
                coord p5 = coord{p1.x - b, p1.y + a};
                coord p6 = coord{p1.x - b + a, p1.y + a + b};
                if((P_set.find(p5) != P_set.end()) && (P_set.find(p6) != P_set.end())){
                    chmax(ans, a*a + b*b);
                }
            } 
        }
    }

    cout << ans << endl;
}