#include <iostream>
#include <vector>
using namespace std;


// index が条件を満たすかどうか
bool isOK(int index, int key, vector<int> &a) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key, vector<int> &a) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    int ok = (int)a.size(); //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(int)a.size()
    int ng = -1; //ng以上から右端が条件を必ず満たさないような場合(int)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    cout << binary_search(2, a) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
}