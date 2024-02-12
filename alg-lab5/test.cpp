#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#define MAX 2147483647
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll n, m, v, w, c;
vector<int> h;
vector<vector<pll>> g;
vector<ll> BF;
vector<ll> dist;

struct cmp {
    bool operator()(pll a, pll b) {
        if (a.second != b.second){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

void Dijkstra(void)
{
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        if (dist[1] < 0){
            return;
        }
        pll cur = pq.top();     //  cur = {id, shortest_path_cost (dist[id])}
        pq.pop();
        for(pll e : g[cur.second]){
            if (dist[e.first] > dist[cur.second] + e.second){
                dist[e.first] = dist[cur.second] + e.second;
                pq.push(make_pair(dist[e.first], e.first));
            }
        }
    }
}



int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> v >> w >> c;
    h = vector<int>(n + 1, 0);
    g = vector<vector<pll>>(n + 1);
    dist = vector<ll>(n + 1, LLONG_MAX);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= m; i++){    //  total 2m edges
        int x, y;
        cin >> x >> y;
        if (h[x] < h[y]){
            swap(x, y);
        }
        if (h[x] != h[y]){
            ll glide_w = v * (h[y] - h[x]);
            glide_w += v * (h[x] - h[y]);   //  every glding edge is 0
            g[x].emplace_back(make_pair(y, glide_w));
        }    //  negative
        ll walk_w = w * abs(h[x] - h[y]) + c;       //  positive
        walk_w += v * (h[y] - h[x]);
        g[y].emplace_back(make_pair(x, walk_w));
        if (walk_w < 0){
            cout << "inf\n";
            return 0;
        }
    }

    for(long long i = 1; i<=n; i++)
    {
        for(auto e: g[i])
            cout<<e.second<<" ";
        cout<<"\n";
    }
    
//    for(int i = 1; i <= n; i++){        //  add a source
//        g[0].emplace_back(make_pair(i, 0));
//    }
//
//
//    // assign new weight
//    for(int i = 0; i <= n; i++){
//        for(pll e : g[i]){
//            e.second = e.second + BF[i] - BF[e.second];
//        }
//    }
    
    //  Dijkstra
    Dijkstra();
    
//    if (dist[1] < 0){
//        cout << "inf\n";
//        return 0;
//    }
    for(ll i = 1 ;i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    ll mini = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        mini = min(mini, dist[i] - v * (h[1] - h[i]));
    }
    
    cout << -1 * mini << '\n';
    return 0;
}