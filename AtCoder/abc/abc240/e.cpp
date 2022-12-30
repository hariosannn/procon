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


void dfs_make_leaf_section(vector<V_L> &Tree, ll current_node, ll &visited_leaf_num, V_L &visited, vector<P_L> &sections){

    visited.at(current_node) = 1;
    if((Tree.at(current_node).size() == 1) && (current_node != 0)){
        sections.at(current_node) = P_L{visited_leaf_num, visited_leaf_num};
        visited_leaf_num++;
        return;
    }
    else{
        for(ll next_node:Tree.at(current_node)){
            if(visited.at(next_node)) continue;
            dfs_make_leaf_section(Tree, next_node, visited_leaf_num, visited, sections);
        }
    }
    return;
}

P_L dfs_make_node_section(vector<V_L> &Tree, ll current_node, V_L &visited, vector<P_L> &sections){
    visited.at(current_node) = 1;
    P_L section{LINF, -LINF};
    if(sections.at(current_node) != section) return sections.at(current_node);

    for(ll next_node:Tree.at(current_node)){
        if(visited.at(next_node)) continue;
        P_L tmp_section;
        tmp_section = dfs_make_node_section(Tree, next_node, visited, sections);
        chmin(section.first, tmp_section.first);
        chmax(section.second, tmp_section.second);
    }
    sections.at(current_node) = section;
    return section;
}

int main(){
    ll N;
    cin >> N;
    vector<V_L> Tree(N, V_L{});
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        Tree.at(u).push_back(v);
        Tree.at(v).push_back(u);
    }
    vector<P_L> sections(N, P_L{LINF, -LINF});
    V_L visited(N, 0);
    ll visit_num = 0;
    dfs_make_leaf_section(Tree, 0, visit_num, visited, sections);

    visit_num = 0;
    rep(i, N) visited.at(i) = 0;

    dfs_make_node_section(Tree, 0, visited, sections);
    rep(i, N){
        cout << sections.at(i).first+1 << " " << sections.at(i).second+1 << endl;
    }
    return 0;
}