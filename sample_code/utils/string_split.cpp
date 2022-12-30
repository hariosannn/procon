#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


vector<string> split(string S, string separator){
    auto separator_length = separator.length(); // 区切り文字の長さ
    auto list = vector<string>();

    if (separator_length == 0) {
        list.push_back(S);
    } 
    else {
    auto offset = string::size_type(0);
        while (1) {
            auto pos = S.find(separator, offset);
            if (pos == string::npos) {
            list.push_back(S.substr(offset));
            break;
            }
            list.push_back(S.substr(offset, pos - offset));
            offset = pos + separator_length;
        }
    }
    return list; 
}

int main(){
    auto splited = split("aa_bb_cc", "_");
    for(string s:splited){
        cout << s << endl;
    }
}