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
    ll N;
	cin >> N;
	string S;
	cin >> S;
	vector<vector<vector<modint998244353>>> dp(N+1, vector<vector<modint998244353>>(1<<10, vector<modint998244353>(11, 0)));
	dp[0][0][10] = 1;
	rep(i, N){
		rep(msk, 1<<10){
			rep(last, 11){
				dp[i+1][msk][last] += dp[i][msk][last];
				ll next = S.at(i) - 'A';
				if(!(msk & (1<<next)) | (last == next)){
					dp[i+1][msk | 1<<next][next] += dp[i][msk][last];
				}
			}
		}
	}

	modint998244353 ans = 0;
	rep(msk, 1<<10){
		rep(last, 10){
			ans += dp[N][msk][last];
		}
	}
	cout << ans.val() << endl;
}