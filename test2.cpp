#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    long long r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

//オーバフローしないようにかける順番を気を付ける
long long lcm(long long x,long long y){
    return (x/gcd(x,y))*y;
}

vector<long long> partial_p(long long N){
    vector<long long> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            res.push_back(a);
            N /= a;
        }
        // その結果を push
    }

    // 最後に残った数について
    if (N != 1) res.push_back(N);
    return res;
}

int main(){
    long long N, A, B;
    long long c = 1;
    cin >> N >> A >> B;
    long long A_sum, B_sum, AB_sum, all_sum = 0;
    vector<long long> A_vec, B_vec, AB_vec;
    long long AB;
    A_vec = partial_p(A);
    B_vec = partial_p(B);
    for(auto p_a: A_vec){
        auto ite_b = find(B_vec.begin(), B_vec.end(), p_a);
        if(ite_b != B_vec.end()){
            AB_vec.push_back(p_a);
            B_vec.erase(ite_b);
        }
    }
    if(AB_vec.size() == 0){
        AB = A*B;
    }
    else{
        for(auto ab: AB_vec){
            c *= ab;
        }
        AB = (A/c) * (B/c) * c;
    }
    if(AB == lcm(A, B)){
        //cout << "True" << endl;
    }
    AB = lcm(A, B);
    A_sum = (A*(1+N/A)*(N/A))/2;
    B_sum = (B*(1+N/B)*(N/B))/2;
    AB_sum = (AB*((1+N/AB))*(N/AB))/2;
    auto tes = ((1+N))*N;
    all_sum = (((1+N))*N)/2;
    cout << all_sum-(A_sum + B_sum - AB_sum) << endl;
    }