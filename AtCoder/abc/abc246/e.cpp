//https://atcoder.jp/contests/abc246/tasks/abc246_e
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
 
 
 
 
 
 
 
 
 
 
 
 
 
int N;
int Ax, Ay, Bx, By;
string S[1510];
 
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int dx[4] = { 1, 1, -1, -1 };
int dy[4] = { 1, -1, 1, -1 };
int opt[1510][1510][5];
bool vis[1510][1510][5];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	//cin >> Ax >> Ay >> Bx >> By;
    cin >> Ay >> Ax >> By >> Bx;
	Ax--; Ay--; Bx--; By--;
	rep(y, 0, N) cin >> S[y];
 
    min_priority_queue<pair<int, tuple<int, int, int>>> que;
    rep(x, 0, N) rep(y, 0, N) rep(dir, 0, 5) opt[y][x][dir] = inf;
    rep(x, 0, N) rep(y, 0, N) rep(dir, 0, 5) vis[y][x][dir] = false;
 
    opt[Ay][Ax][4] = 0;
    que.push({ 0, { Ax, Ay, 4 } });
 
    while (!que.empty()) {
        int x, y, dir;
        tie(x, y, dir) = que.top().second;
        que.pop();
 
        if (vis[y][x][dir]) continue;
        vis[y][x][dir] = true;
 
        if (x == Bx && y == By) {
            cout << opt[y][x][dir] << endl;
            return;
        }
 
        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (0 <= xx && xx < N && 0 <= yy && yy < N) {
                if (S[yy][xx] == '#') continue;
                if (chmin(opt[yy][xx][d], opt[y][x][dir] + (dir != d))) {
                    que.push({ opt[yy][xx][d], { xx, yy, d } });
                }
            }
        }
    }
 
    cout << -1 << endl;
}
 
 
 
 
 
/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */