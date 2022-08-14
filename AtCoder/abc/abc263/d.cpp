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

int main(){
    int N, M;
    cin >> N >> M;
    vector<V_I> graph(N, V_I{});
    rep(i, M){
        int a, b;
        cin >> a >> b;
        graph.at(a-1).push_back(b-1);
    }

    set<set<int, int>> ans;
    rep(i, N){
        queue<int> que;
        int start = i;
        que.push(start);
        vector<int> dist(N, -1); 
        dist.at(start) = 0;

        while(!que.empty()){
            int v = que.front(); // キューから先頭頂点を取り出す
            que.pop();
            for(int next:graph.at(v)){
                if(dist.at(next) != -1) continue;
                que.push(next);
                dist.at(next) = dist.at(v) + 1;
                ans.insert(set<int, int>{start, next});
            }
        }
    }

    cout << ans.size() << endl;
}   