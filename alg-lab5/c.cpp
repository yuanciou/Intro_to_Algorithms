#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector <long long> h(200005, 0);
vector <long long> dist(200005);
vector <vector<pair<long long, long long>>> adj_list(200005);
long long n;

void dijkstra(vector<long long> &distance, vector<vector<pair<long long, long long>>> &adj_list, long long src){
    fill(distance.begin(), distance.begin() + n + 2, LLONG_MAX);
    distance[src] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long , long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        long long cur = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(d >distance[cur]) continue;
        for(auto &e : adj_list[cur]){
            long long next = e.second;
            long long weight = e.first;
            if(distance[next] > distance[cur] + weight){
                distance[next] = distance[cur] + weight;
                pq.push({distance[next], next});
            }
        }
    }
}


int main(){
    long long m, v, w, c;
    cin>>n>>m>>v>>w>>c;
    for(long long i = 1 ; i<=n; i++)
    {
        cin>>h[i];
    }
    for(long long i = 1; i<=m; i++)
    {
        long long p, q;
        cin>>p>>q;
        if((min(h[p] - h[q], h[q] - h[p]) * v + w * abs(max(h[p] - h[q], h[q] - h[p])) + c) < 0)
        {
            cout<<"inf\n";
            return 0;
        }
        
        if(h[p] >=  h[q])
        {
            long long weight_g = v * (h[q] - h[p]) + v * (h[p] - h[q]);
            adj_list[p].push_back({weight_g, q});
            long long weight_w = w * abs(h[p] - h[q]) + c + v * (h[q] - h[p]);
            adj_list[q].push_back({weight_w, p});
        }
        else
        {
            long long weight_g = v * (h[p] - h[q]) + v * (h[q] - h[p]);
            adj_list[q].push_back({weight_g, p});
            long long weight_w = w * abs(h[q] - h[p]) + c + v * (h[p] - h[q]);
            adj_list[p].push_back({weight_w, q});
        }
      
    }
    /*
    for(long long i = 1; i<=n; i++)
    {
        for(auto e: adj_list[i])
            cout<<e.first<<" ";
        cout<<"\n";
    }
    */
    dijkstra(dist, adj_list, 1);
    /*for(long long k = 1; k <= n; k++)
    {
        cout<<dist[k]<<" ";
    }
    cout<<"\n";*/
    long long tmp = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        tmp = min(tmp, dist[i] - v * (h[1] - h[i]));
    }
    
    cout << -1 * tmp << "\n";
    return 0;
}