#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll LINF = 1001001001001001001ll;

         
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
    ll V, E;
    cin >> V >> E;
    vector<vector<ll>> graph(V, vector<ll>(V, LINF));
    for(ll i=0; i<E; i++){
        ll s, t, d;
        cin >> s >> t >> d;
        graph.at(s).at(t) = d;
    }
    for(ll i=0; i<V; i++){
        graph.at(i).at(i) = 0;
    }
    vector<vector<ll>> next(V);
    for(ll i=0; i<V; i++){
        for(ll j=0; j<V; j++){
            next.at(i).push_back(j);
        }
    }

    warshall_floyd(V, graph, next);

    for(ll i=0; i<V; i++){
            if(graph.at(i).at(i) < 0){
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
        }
    }
    for(ll i=0; i<V; i++){
        for(ll j=0; j<V; j++){
            if(j==V-1){
                if(graph.at(i).at(j) == LINF) cout << "INF" << endl;
                else cout << graph.at(i).at(j) << endl;
            }
            else{
                if(graph.at(i).at(j) == LINF) cout << "INF" << " ";
                else cout << graph.at(i).at(j) << " ";   
            }
        }
    }
}