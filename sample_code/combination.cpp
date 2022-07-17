#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}
int main() {
    int k=1;
    vector<int> v{202, 20, 5, 1, 4, 2, 100};
    sort(v.begin(), v.end());
    do {
        for (int i = 0; i < k; i++) {
            cout << v[i] << " ";
        }
        cout << "| ";
        for (int i = k; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } while(next_combination(v.begin(), v.end(), k));
}