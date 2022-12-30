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

struct alter_seg
{
    int head;
    int tail;
    int length;
};

int main(){
    ll N;
    cin >> N;
    V_I A(N);
    cin >> A;
    vector<alter_seg> alters;
    for(ll i=0; i<N;){
        int start = A.at(i);
        ll j=i+1;
        if(j == N){
            alters.push_back(alter_seg{A.at(i), A.at(i), 1});
            break;
        }
        while((A.at(j) != start)){
            start = A.at(j);
            j++;
            if(j == N) break;
        }
        alters.push_back(alter_seg{A.at(i), A.at(j-1), int(j-i)});
        i = j;
    }

    if(alters.size() == 1){
        cout << alters.at(0).length << endl;
        return 0;
    }
    ll ans = 0;
    rep(i, alters.size()){
        ll tmp_ans = alters.at(i).length;
        if(i == 0){
            if(alters.at(i).tail == alters.at(i+1).head) tmp_ans += alters.at(i+1).length;
        }
        else if(i == alters.size()-1){
            if(alters.at(i).head == alters.at(i-1).tail) tmp_ans += alters.at(i-1).length;
        }
        else{
            if(alters.at(i).tail == alters.at(i+1).head) tmp_ans += alters.at(i+1).length;
            if(alters.at(i).head == alters.at(i-1).tail) tmp_ans += alters.at(i-1).length;
        }
        chmax(ans, tmp_ans);
    }

    cout << ans << endl;
    return 0;
}