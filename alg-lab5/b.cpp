#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*TO DO 
******1 base******
1. find SCC
2. 把vertix 1所在的SCC走完然後前往下一個SCC直到找到7
3. 進到SCC後直接找出口(find shortest path 1->7 把經過的SCCsize都加起來??)
*/
//拓譜點權重??


/*TIPS
陣列10^6 * 10^6 會爆 極限大概相乘為10^8
*/
vector<long long> adj_list[200005]; 
vector<long long> rev_adj_list[200005]; 
vector<long long> finish_time;

vector<vector<long long> >scc_adj_list(200005); 
int visited[200005] = {0};
long long belong_scc[200005];
long long scc_weight[200005];

//Dijkstra
vector<long long> dist(200005);
long long prev[200005]; 
//long long count_weight = 0;

//第一次DFS
void dfs(long long x)
{
    visited[x] = 1;
    for(long long i = 0; i<adj_list[x].size() ; i++)
    {
        if(visited[adj_list[x][i]] == 0)
        {
            dfs(adj_list[x][i]);
        }
    }
    finish_time.push_back(x);
}

void dfs_rev(long long x, long long scc)
{
    belong_scc[x] = scc;
    visited[x] = 1;
    for(long long i = 0; i<rev_adj_list[x].size() ; i++)
    {
        if(visited[rev_adj_list[x][i]] == 0)
        {
            dfs_rev(rev_adj_list[x][i], scc);
            //count_weight++;
        }
    }
}

void dijkstra(vector<long long> &distance, vector<vector<long long>> &graph, long long scc, long long src){
    for(int i = 1;i <= scc;i++){
        distance[i] = LLONG_MAX;
    }
    distance[src] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long , long long>>, greater<>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto &e: graph[cur]){
            int next = e;
            int weight = scc_weight[cur];
            if(distance[next] > distance[cur] + weight){
                distance[next] = distance[cur] + weight;
                pq.push({distance[next], next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    long long n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        long long x, y;
        cin>>x>>y;
        adj_list[x].push_back(y);
        rev_adj_list[y].push_back(x);
    }
    finish_time.clear();
    fill(visited, visited+n+1, 0);
    for(long long i = 1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }
    long long scc = 1;
    fill(visited, visited+n+2, 0);
    //scc_weight.clear();
    for(long long i = n-1; i>=0; i--)
    {
        if(visited[finish_time[i]] == 0)
        {
            //count_weight = 1;
            dfs_rev(finish_time[i], scc++);
            //scc_weight.push_back(count_weight);
        }
    }
    fill(visited, visited+n+2, 0);
   /* for(int i = 1; i<=n; i++)
    {
        cout<<belong_scc[i]<<" ";
    }
    cout<<"\n";*/
    for(int i = 1;i<=n;i++)
    {
        if(belong_scc[i] == belong_scc[n])
        {
            belong_scc[i] = scc;
            scc++;
        }
    }
    fill(scc_weight, scc_weight + n+2, 0);
    for(int i = 1; i<n; i++)
    {
        scc_weight[belong_scc[i]]++;
    }
    /*
    for(int i = 1; i<=n; i++)
    {
        cout<<belong_scc[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i<=n; i++)
    {
        cout<<scc_weight[i]<<" ";
    }
    cout<<"\n";*/
    
    for(long long i = 1; i<=n;i++)
    {
        for(long long j = 0; j<adj_list[i].size();j++)
        {
            if(belong_scc[i] != belong_scc[adj_list[i][j]])
            {
                scc_adj_list[belong_scc[i]].push_back(belong_scc[adj_list[i][j]]);
            }
        }
    }
    /*for(long long i = 1; i<=n;i++)
    {
        for(long long j = 0; j<scc_adj_list[i].size();j++)
        {
            
            cout<<scc_adj_list[i][j]<<" ";
            
        }
        cout<<"\n";
    }*/
    //Dijstra
    dijkstra(dist, scc_adj_list, scc, belong_scc[1]);
    /*for(int k = 1; k<scc; k++)
    {
        cout<<dist[k]<<" ";
    }
    cout<<"\n";*/
    if(dist[belong_scc[n]] == LLONG_MAX)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<dist[belong_scc[n]]+1<<"\n";
    
    


    return 0;
}