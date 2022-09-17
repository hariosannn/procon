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

int isInside(double ax, double ay, double bx, double by, double cx, double cy, double tx, double ty)
{
    double abXat, bcXbt, caXct;
 
    abXat = (bx-ax)*(ty-ay) - (by-ay)*(tx-ax);
    bcXbt = (cx-bx)*(ty-by) - (cy-by)*(tx-bx);
    caXct = (ax-cx)*(ty-cy) - (ay-cy)*(tx-cx);
  
    if(( abXat > 0.0 && bcXbt > 0.0 && caXct > 0.0) || ( abXat < 0.0 && bcXbt < 0.0 && caXct < 0.0))
    {
        return 1;
    }
    else if(abXat*bcXbt*caXct == 0.0)
    {
        return 0;
    }
 
    return 0;
 
}
 
int isConcave(double px[], double py[])
{
    int i;
    for(i=0; i<4; i++)
    {
        if(isInside(px[i%4], py[i%4], px[(i+1)%4], py[(i+1)%4], px[(i+2)%4], py[(i+2)%4], px[(i+3)%4], py[(i+3)%4]))
        {
            return 1;
        }
    }
 
    return 0;
}
 
int main()
{
 
    double px[4], py[4];
    int i;
    for(i=0; i<4; i++)
    {
        cin >> px[i];
        cin >> py[i];
    }
 
    if(isConcave(px,py))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
 