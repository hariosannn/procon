#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int N = 4;
void monotonic_increase(vector<int> &A, vector<vector<int>> &ret){
    // 1~5までの数字を使った長さＮの単調増加列を作る関数
    if(A.size() == N){
        ret.push_back(A);
    }
    else{
        int v_back;
        if(A.size() == 0)  v_back = 0;
        else v_back = A.back();
        for(int i=v_back; i<5; i++){
            A.push_back(i);
            monotonic_increase(A, ret);
            A.pop_back();
        }
    }
}

int main(){
    vector<vector<int>> V;
    vector<int> first_A{};
    monotonic_increase(first_A, V);
    for(auto v:V){
        for(int el:v){
            cout << el << " ";
        }
        cout << endl;
    }
}
