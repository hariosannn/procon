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
    vector<V_L> graph_in(N, V_L{});
    vector<V_L> graph_to(N, V_L{});
    set<ll> graph_node;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph_to.at(a).push_back(b);
        graph_in.at(b).push_back(a);
        graph_node.insert(a);
        graph_node.insert(b);
    }
    V_L in_num(N);
    V_L dist(N, -1);
    priority_queue<ll, vector<ll>, greater<ll> > queue;
    rep(i, N){
        in_num.at(i) = graph_in.at(i).size();
        if(graph_in.at(i).size() == 0){
            queue.push(i);
            dist.at(i) = 1;
        }
    }

    V_L ans;
    while(!queue.empty()){
        ll next = queue.top();
        ans.push_back(next);
        queue.pop();
        for(ll n:graph_to.at(next)){
            if(dist.at(n) == -1){
                in_num.at(n) -= 1;
                if(in_num.at(n) == 0){
                    queue.push(n);
                    dist.at(n) = 1;
                }
            }
        }
    }

    for(ll n:graph_node){
        if(dist.at(n) == -1){
            cout << -1 << endl;
            return 0;
        }
    }
    for(ll a:ans){
        cout << a+1 << " ";
    }
    cout << endl;
    return 0;
}