#include <bits/stdc++.h>
using namespace std;
#define N 100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define pb push_back
vector<int>e[N];
bool used[N];
int x, y;
void dfs(int k) {
	used[k] = true;
	x++;
	y += e[k].size();
	rep(i, e[k].size())if (!used[e[k][i]])dfs(e[k][i]);
	return;
}
int main(void) {
	int n, m;
	ll ans = 1;
	cin >> n >> m;
	rep(i, n)used[i] = false;
	rep(i, m) {
		cin >> x >> y;
		e[x - 1].pb(y - 1);
		e[y - 1].pb(x - 1);
	}
	rep(i, n) {
		if (!used[i]) {
			x = 0;
			y = 0;
			dfs(i);
			if (y == (x * 2))ans = (ans * 2) % MOD;
			else ans = 0;
		}
	}
	cout << ans << endl;
	return 0;
}