#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector<int> X, C;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        X.push_back(tmp-1);
    }
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        C.push_back(tmp);
    }
    atcoder::dsu uf(N);
    ll ans = 0;
    for(int i=0; i<N; i++){
        int i_hate = X.at(i);
        if(!uf.same(i, i_hate)){
            uf.merge(i, i_hate);
            continue;
        }
        int min_hate =  C.at(i);
        int tmp_i = i;
        do{
            if(min_hate > C.at(tmp_i)){
                min_hate = C.at(tmp_i);
            }
            tmp_i = X.at(tmp_i);
        }
        while(tmp_i != i);
        ans += min_hate;
    }

    cout << ans << endl;
}
