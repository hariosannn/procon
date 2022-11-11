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

struct node
{
    node *parent;
    ll a;
};

int main(){
    ll Q;
    cin >> Q;
    //vector<node> graph(1, node{0, -1, -1});
    map<ll, node> note;

    node root_node = node{nullptr, -1};
    node *current_node = &root_node;
    rep(i, Q){
        string ope;
        cin >> ope;
        ll a;
        if(ope == "ADD"){
            cin >> a;
            node *new_node = new node{current_node, a};
            current_node = new_node;
        }
        else if(ope == "DELETE"){
            if(current_node->parent != nullptr) current_node = current_node->parent;
        }
        else if(ope == "SAVE"){
            cin >> a;
            note[a] = *current_node;
        }
        else{
            cin >> a;
            if(note.find(a) == note.end()) current_node = &root_node;
            else current_node = &note[a];
        }
        cout << current_node->a << " ";

    }
}