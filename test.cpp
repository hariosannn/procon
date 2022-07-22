#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using V_I = vector<int>;
using V_L = vector<ll>;
using P_I = pair<int, int>;
#define ALL(a) (a).begin(),(a).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};
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

ll counter(V_L &A, ll upper, ll lower){
    string state;
    map<string, ll> max_ind;
    ll ind = 0;
    while((A.at(ind) != upper) & (A.at(ind) != lower)){
        ind ++;
        if(ind == A.size()) break;
    }
    if(ind == A.size()) return 0;

    if(A.at(ind) == upper){
        state = "upper";
        max_ind["upper"] = ind;
    }
    else{
        state = "lower";
        max_ind["lower"] = ind;
    }

    ll ans=0;
    ll del=0;
    for(ll i=ind+1; i<A.size(); i++){
        if(state == "upper"){
            if(A.at(i) == upper){
                max_ind["upper"] = i;
            }
            if(A.at(i) == lower){
                max_ind["lower"] = i;
                ans += (max_ind["upper"]-del+1)*(A.size() - i);
                del = (max_ind["upper"]+1);
                state = "lower";
            }
        }
        else if(state == "lower"){
            if(A.at(i) == lower){
                max_ind["lower"] = i;
            }
            if(A.at(i) == upper){
                max_ind["upper"] = i;
                ans += (max_ind["lower"]-del+1)*(A.size() - i);
                del = (max_ind["lower"]+1);
                state = "upper";
            }
        }
    }
    return ans;
}

int main(){
    ll N, upper, lower;
    cin >> N >> upper >> lower;
    V_L A;
    rep(i, N){
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    ll ind=0;
    ll ans = 0;
    if(upper != lower){
        rep(i, N){
            if((A.at(i) > upper) | (A.at(i) < lower)){
                vector<ll> sub_vec {A.begin()+ind, A.begin()+i};
                if(sub_vec.size() > 1){
                    ans += counter(sub_vec, upper, lower);
                }
                ind = i+1;
            }
            else if((i == ll(A.size())-1)){
                vector<ll> sub_vec {A.begin()+ind, A.end()};
                ans += counter(sub_vec, upper, lower);
                ind = i+1;
            }
        }
    }
    else{
        rep(i, N){
            if((A.at(i) > upper) | (A.at(i) < lower)){
                vector<ll> sub_vec {A.begin()+ind, A.begin()+i};
                ans += (sub_vec.size()+1)*(sub_vec.size())/2;
                ind = i+1;
            }
            else if((i == ll(A.size())-1)){
                vector<ll> sub_vec {A.begin()+ind, A.end()};
                ans += (sub_vec.size()+1)*(sub_vec.size())/2;
                ind = i+1;
            }
        }
    }

    cout << ans << endl;

}