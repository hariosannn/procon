#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
int inf=1e8;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename T>
struct SEGMENT_TREE {//segment木　※インデックスは1から始まる
    T SEG_LEN;
    T init_val=0;
    vector<T> seg;
    SEGMENT_TREE(int n_){ // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        SEG_LEN = x;
        rep(i, SEG_LEN*2){
            seg.push_back(init_val);
        }
    }    


    void add(int ind, int v){//値の更新を行う関数
        ind += SEG_LEN;
        seg[ind] += v;
        while(true){
            //親ノードへ
            ind /= 2;
            //一番上の親まで登ったらループ抜ける
            if(ind == 0) break;
            //合計なのでindの子nodeの合計を新たな値へ
            seg[ind] = seg[ind*2] + seg[ind*2 + 1];
        }
    }

    int sum(int l, int r){
        //半開区間で[l, r]を表すので[l, r+1)
        r += 1;
        l += SEG_LEN;
        r += SEG_LEN;
        int ans = 0;
        while(l < r){// 左右から登っていき、左右が出会ったら終了
            if(l % 2 == 1){
                ans += seg[l];
                l++;
            }
            l /= 2;
            if(r % 2 == 1){
                ans += seg[r-1];
                r--;
            }
            r /= 2;
        }
        return ans;
    }
};

int main(){
    int n, q, com, ind, v, l, r;
    cin >> n >> q;
    SEGMENT_TREE<int> seg_t(n);
    rep(i, q){
        cin >> com;
        if(com == 0){//add
            cin >> ind >> v;
            seg_t.add(ind, v);
        }
        if(com == 1){
            cin >> l >> r;
            cout << seg_t.sum(l, r) << endl;
        }
    }
    return 0;
}