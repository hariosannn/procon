#include <bits/stdc++.h>
using namespace std;


int main(){
    string S="aaaabbcccccdaaaaeeeeee";
    int N = S.size();
    vector<pair<char, int>> rl;

    for(int i=0; i<N;){
        int j=i;
        while((j<N) && (S.at(i) == S.at(j))){
            j++;
        }
        rl.push_back(pair<char, int>{S.at(i), j-i});
        i = j;
    }
    for(auto p:rl){
        cout << p.first << ":" << p.second << endl;
    }
}