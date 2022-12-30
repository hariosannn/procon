#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll LINF = 1001001001001001001ll;

vector<vector<ll>> graph = {{0 , 5, 0, 10, 0, 0, 0},
                             {5 , 0, 3, 0 , 0, 0, 2},
                             {0 , 3, 0, 1 , 0, 8, 9},
                             {10, 0, 1, 0 , 6, 0, 0},
                             {0 , 0, 0, 6 , 0, 4, 0},
                             {0 , 0, 8, 0 , 4, 0, 6},
                             {0 , 2, 9, 0 , 0, 6, 0}};
         
void warshall_floyd(ll n, vector<vector<ll>> &wf_graph, vector<vector<ll>> &next){
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if((wf_graph.at(i).at(k) == LINF) || (wf_graph.at(k).at(j) == LINF)) continue;
                ll d_via_ks = wf_graph.at(i).at(k) + wf_graph.at(k).at(j); 
                if(d_via_ks < wf_graph.at(i).at(j)){
                    wf_graph.at(i).at(j) = d_via_ks;
                    next.at(i).at(j) = next.at(i).at(k);
                }
            }
        }
    }
}

void printPath(ll start, ll goal,vector<vector<ll>> &next) {
    for (ll cur = start; cur != goal; cur = next[cur][goal])
        printf("%d ", cur+1);
    printf("%d\n", goal+1);
}

int main(){
    vector<vector<ll>> wf_graph = graph;
    ll n = wf_graph.size();
    for(ll i=0; i<wf_graph.size(); i++){
        for(ll j=0; j<wf_graph.at(i).size(); j++){
            if((wf_graph.at(i).at(j) == 0) && (i != j)){
                wf_graph.at(i).at(j) = LINF;
            }
        }
    }
    vector<vector<ll>> next(7);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            next.at(i).push_back(j);
        }
    }

    warshall_floyd(n, wf_graph, next);
    ll start = 4-1, end = 7-1;

    printPath(start, end, next);
}