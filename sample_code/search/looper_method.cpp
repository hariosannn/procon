#include <iostream>
#include <vector>
using namespace std;
constexpr int INF = 1001001001;

int looper_method_count_less_k(vector<int> &a, int k){//区間の合計がk以下の区間数を数える尺取り法
    int n = a.size(), ans = 0;
    int sum = 0;
    for (int l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; r < n && sum + a[r] <= k; r++){//条件を満たす限り右に進む
            sum += a[r];
        }
        ans += r - l; //[l, r)がk以下なのでr-l個が解として足される
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ans;
}

int looper_method_count_more_k(vector<int> &a, int k){//区間の合計がk以上の区間数を数える尺取り法
    int n = a.size(), ans = 0;
    int sum = 0;
    for (int l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; r < n && sum + a[r] <= k; r++){//条件を満たす限り右に進む
            sum += a[r];
        }
        ans += n - r; //[l, r+1)からがk以上なのでn-r個が解として足される
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ans;
}

int looper_method_max_len(vector<int> &a, int k){//区間の合計がk以下の区間の最大長
    int n = a.size(), ans = 0;
    int sum = 0;
    for (int l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; r < n && sum + a[r] <= k; r++){//条件を満たす限り右に進む
            sum += a[r];
        }
        ans = max(ans,  r - l); //[l, r)がk以下なのでr-lが最大長候補
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ans;
}

int looper_method_min_len(vector<int> &a, int k){//区間の合計がk以上の区間の最小長
    int n = a.size(), ans = INF;
    int sum = 0;
    for (int l = 0, r = 0; l < n; l++){//左を1ずつ進める
        for (; r < n && sum + a[r] <= k; r++){//条件を満たす限り右に進む
            sum += a[r];
        }
        if (r == n) break; //r = nのとき、これ以上左を進めても区間合計がk以上になることはないので除く
        ans = min(ans, r - l + 1); //[l, r+1)からがk以上なのでr-l+1が最小長候補
        sum -= a[l];//左を1進めたので合計から今の左が指す値を消す
    }
    return ans;
}

int main(){
    vector<int> a {20, 3, 5, 0, 7, 2};
    int k = 8;

    cout << looper_method_min_len(a, k) << endl;

    int n = a.size(), ans = 0;
    for (int l = 0, r = 0, sum = 0; l < n; sum -= a[l++])
    {
        for (; r < n && sum + a[r] <= k; sum += a[r++]); // 右手さんの位置決めボーナスタイムです。
        ans += r - l;
    }
    cout << ans << endl;
}