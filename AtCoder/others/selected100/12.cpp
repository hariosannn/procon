#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

struct piece
{
    ll number;
    ll x;
    ll y;

    pair<piece, piece> cut(ll cut_num, ll s){
        s %= (x+y);
        pair<piece, piece> ret;
        // 縦方向に切られる場合
        if(s <= x){
            ret.first = piece{cut_num, s, y};
            ret.second = piece{cut_num, x-s, y};
        }
        else if((s >= x+y) && (s <= 2*x+y)){
            ret.first = piece{cut_num, s-x-y, y};
            ret.second = piece{cut_num, 2*x+y-s, y};
        }
        // 横方向に切られる場合
        else if((s >= x) && (s <= x+y)){
            ret.first = piece{cut_num, x, y-(s-x)};
            ret.second = piece{cut_num, x, (s-x)};
        }
        else{
            ret.first = piece{cut_num, x, y-(s-2*x-y)};
            ret.second = piece{cut_num, x, (s-2*x-y)};
        }
        return ret;
    }
};

bool operator<(const piece &left, const piece &right) {
    if(left.number < right.number){
        return true;
    }
    else if(left.number > right.number){
        return false;
    }
    else{
        if(left.x*left.y < right.x*right.y){
            return true;
        }
        return false;
    }
// left < right の場合に true を返すように実装する
}

int main(){
    while(true){
        ll n, w, d;
        cin >> n >> w >> d;
        if((n==0) && (w==0) && (d==0)) break;
        multiset<piece> P;
        P.insert(piece{0, w, d});
        rep(i, n){
            ll p, s;
            cin >> p >> s;
            p--;
            auto ite = P.begin();
            rep(j, p){
                ite++;
            }
            piece current_p = *ite;
            pair<piece, piece> new_pieces = current_p.cut(i+1, s);
            P.erase(ite);
            P.insert(new_pieces.first);
            P.insert(new_pieces.second);
        }

        multiset<ll> ans;
        for(piece p:P){
            ans.insert(p.x*p.y);
        }
        vector<ll> ans_v;
        for(ll s:ans){
            ans_v.push_back(s);
        }
        rep(i, ans_v.size()-1){
            cout << ans_v.at(i) << " ";
        }
        cout << ans_v.back() << endl;
    }
}