#include <bits/stdc++.h>
using namespace std;
 

int main(){
    string ret = "Yes";
    int N= 10, K=9;
    set<int> A{1,30, 4, 30, 3, 30, 304, 40, 30, 10};
    map<int, vector<int>> A_map;
    for(int i=0; i<=N-K; i++){
        int tmp_a = A.at(i);
        A_map[tmp_a].push_back(i%K);
    }
    vector<int> origin_A = A;
    sort(A.begin(), A.end());
    for(int i=0; i<=N-K; i++){
        vector<int> tmp_v = A_map.at(A.at(i));
        auto ite_f = find(tmp_v.begin(), tmp_v.end(), i%K);
        if(ite_f == tmp_v.end()){
            ret = "No";
            break;
        }
        else{
            tmp_v.erase(ite_f);
            A_map.at(A.at(i)) = tmp_v;
        }
    }
    cout << ret << endl;
 }