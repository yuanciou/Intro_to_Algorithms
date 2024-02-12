#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*TO DO
1. 找u,v之間的最短路徑
2. 再u, v之間加一個權重w的邊
3. 把u到v的邊全部刪掉
*/
vector<vector<pair<long long, pair<long long, bool>>>> adj_list(2005); // 權重 點 valid
vector<vector<pair<long long, pair<long long, bool>>>> adj_list_h(2005);
vector<long long> h(2005, 0);
vector<long long> visited(2005, 0);
vector<vector<long long>> oper(2005);
vector<long long> dist(2005);

bool bellmanford(vector<long long> &h, vector<vector<pair<long long, pair<long long, bool>>>> &adj, long long src, long long &n)
{
    fill(h.begin(), h.begin()+n+2, LLONG_MAX);
    h[src] = 0;
    //bool change = false; //true 有換; false沒換
    for(long long k = 0; k<=n; k++)
    {
        for(long long i = 0; i<=n; i++)
        {
            for(auto &e : adj[i])
            {
                if((h[e.second.first] > h[i] + e.first))
                {
                    h[e.second.first] = h[i] + e.first;
                }
            }
        }
    }
    

    //負環
    for(long long k = 0; k<= n; k++)
    {
        for(long long i = 0; i<=n; i++)
        {
            for(auto &e : adj[i])
            {
                if((h[e.second.first] > h[i] + e.first))
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

void Dijstra(vector<long long> &dist, vector<vector<pair<long long, pair<long long, bool>>>> &adj, long long src, long long &n)
{
    fill(visited.begin(), visited.begin() + n + 2, 0);
    fill(dist.begin(), dist.begin()+n+2, LLONG_MAX);
    dist[src] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        long long cur = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if (visited[cur] == 1) continue;
        visited[cur] = 1;
        for(auto &e: adj[cur]){
            long long next = e.second.first;
            long long weight = e.first;
            if((dist[next] > dist[cur] + weight)){
                dist[next] = dist[cur] + weight;
                pq.push({dist[next], next});
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n, m;
    cin>>n>>m;
    for(long long i = 1;i<=n;i++)
    {
        adj_list_h[0].push_back({0, {i, true}});
    }
    for(long long i = 0; i< m; i++)
    {
        long long s, e, x;
        cin>>s>>e>>x;
        adj_list[s].push_back({x, {e, true}});
        adj_list_h[s].push_back({x, {e, true}});
    }
    long long q;
    cin>>q;
    for(long long i = 0; i<q; i++)
    {
        int op;
        cin>>op;
        if(op == 2)
        {
            long long u, v, w;
            cin>>u>>v>>w;
            oper[i].push_back(op);
            oper[i].push_back(u);
            oper[i].push_back(v);
            oper[i].push_back(w);
            adj_list_h[u].push_back({w, {v, true}});
        }
        else
        {
            long long u,v;
            cin>>u>>v;
            oper[i].push_back(op);
            oper[i].push_back(u);
            oper[i].push_back(v);
        }
    }
    bool neg;
    neg = bellmanford(h, adj_list_h, 0, n);
    if(!neg)
    {
        cout<<"BROKEN!\n";
        return 0;
    }
    /*for(long long k = 0; k<h.size(); k++)
    {
        cout<<h[k]<<" ";
    }
    cout<<"\n";*/
    for(long long i = 1; i<=n; i++)
    {
        for(auto &e : adj_list[i])
        {
            e.first = e.first + h[i] - h[e.second.first];
        }
    }
    for(long long i = 0; i<q; i++)
    {
        if(oper[i][0] == 1)
        {
            Dijstra(dist, adj_list, oper[i][1], n);
            if(dist[oper[i][2]] == LLONG_MAX)
            {
                cout<< "NO ROUTE!\n";
            }
            else
            {
                cout<<dist[oper[i][2]] + h[oper[i][2]] - h[oper[i][1]]<<"\n";
            }
        }
        else if(oper[i][0] == 2)
        {
            adj_list[oper[i][1]].push_back({oper[i][3] + h[oper[i][1]] - h[oper[i][2]] , {oper[i][2], true}});
        }
        else if(oper[i][0] == 3)
        {
            for(long long k = 0; k <adj_list[oper[i][1]].size();k++)
            {
                if(adj_list[oper[i][1]][k].second.first == oper[i][2])
                {
                    adj_list[oper[i][1]].erase(adj_list[oper[i][1]].begin() + k);
                    k--;
                }
            
            }
        }
    }
    return 0;
}