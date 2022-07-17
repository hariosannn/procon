#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
ll inf=1e17;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// index が条件を満たすかどうか
bool isOK_R(int index, int key, vector<int> &a) {
    if (a[index] > key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search_R(int key, vector<int> &a) {
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

        if (isOK_R(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

// index が条件を満たすかどうか
bool isOK_L(int index, int key, vector<int> &a) {
    if (a[index] < key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search_L(int key, vector<int> &a) {
    //単調性(あるインデックス以上、もしくは以下はすべて条件を満たす)がある場合使える
    //条件を満たす解が存在する区間を[ok, ng)または(ng, ok]で持つ
    //okとngの差が1になるまでループして解の存在区間を縮めていくことで、
    //ok以下から左は条件をみたす[ok, ng)のとき、okは条件を満たす最大のind, ngは条件を満たさない最小のind
    //ok以上から右は条件をみたす(ng, ok]のとき、okは条件を満たす最小のind, ngは条件を満たさない最大のind
    int ok = -1; //ok以下から左端が条件を必ず満たすような場合-1, ok以上から右端〃(int)a.size()
    int ng = (int)a.size(); //ng以上から右端が条件を必ず満たさないような場合(int)a.size(), ng以下から左端〃-1

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK_L(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int N;
    cin >> N;

    vector<int> A;
    map<int, vector<int>> index_map;

    rep(i, N){
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
        if(!index_map.count(tmp)){
            index_map[tmp] = vector<int>{i};
        }
        else{
            index_map.at(tmp).push_back(i);
        }
    }

    int Q;
    cin >> Q;
    rep(i, Q){
        int L, R, X;
        cin >> L >> R >> X;
        if(!index_map.count(X)){
            cout << 0 << endl;
        }
        else{
            int l_ind = binary_search_L(L-1, index_map.at(X));
            int r_ind = binary_search_R(R-1, index_map.at(X));
            cout << r_ind-l_ind-1 << endl;
        }
    }
}