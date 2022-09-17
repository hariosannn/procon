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

int main(){
    ll N, M;
    cin >> N >> M;
    vector<stack<ll>> cylinder(M);
    map<ll, vector<ll>> color_to_cylinder;

    rep(i, M){
        ll k;
        cin >> k;
        V_L tmp_v(k);
        cin >> tmp_v;
        rep(j, k){
            color_to_cylinder[tmp_v.at(k-j-1)-1].push_back(i);
            cylinder.at(i).push(tmp_v.at(k-j-1)-1);
        }
    }
    
    map<ll, ll> color_to_num;
    rep(i, M){
        color_to_num[cylinder.at(i).top()] += 1;
        cylinder.at(i).pop();
    }

    set<ll> color_two;
    V_L current_pair;
    rep(i, N){
        if(color_to_num[i] == 2){
            color_two.insert(i);
        }
    }
    if(color_two.size() == 0){
        cout << "No" << endl;
        return 0;
    }

    while(color_two.size() > 0){
        set<ll> tmp_color_two = color_two;
        for(ll c:tmp_color_two){
            current_pair = color_to_cylinder[c];
            for(ll c_i:current_pair){
                if(cylinder.at(c_i).size() == 0) continue;
                ll next_c = cylinder.at(c_i).top();
                color_to_num[next_c] += 1;
                cylinder.at(c_i).pop();
                if(color_to_num[next_c] == 2){
                    color_two.insert(next_c);
                }
            }
            color_two.erase(c);
        }
    }

    string ans = "Yes";
    rep(i, M){
        if(cylinder.at(i).size() > 0) ans = "No";
    }
    cout << ans << endl;
}