#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    long long u;
    long long v;
    char c;
    long long w;
};

vector <long long> l(2000005, 0);
vector <long long> vertix(2000005, 0);//vertix[k] 進入的邊是黑色的 vertix[k + n]進入的邊是白色的
vector <bool> visit_or_not(200005, false);
vector <pair<long long, long long>> neighbor[200005];
vector <Edge> edge;
vector <long long> topo_order;
vector <long long> dp_distance(2000005, LLONG_MIN);
vector <long long> l_is_zero;
queue <int> q_for_zerodegree;


int main(){
    long long n, m;
    cin>>n>>m;

    l_is_zero.push_back(0);
    for(int k = 1;k<=n;k++)
    {
        long long x;
        cin>>x;
        l[k] = x;
        l[k + n] = x;
        if(x == 0)
        {
            l_is_zero.push_back(k);
            l_is_zero.push_back(k+n);
        }
    }
    for(int k = 1;k<=m;k++)
    {
        Edge x;
        cin>>x.u>>x.v>>x.c>>x.w;
        edge.push_back(x);
        if(x.c == 'B')
        {
            vertix[x.v]++;
            neighbor[x.u + n].push_back({x.v, x.w});
        }
        else
        {
            vertix[x.v+n]++;
            neighbor[x.u].push_back({x.v + n, x.w});
        }
    }

    //拓樸
        //把degree 0的加進queue
    for (long long k = 1; k<=(2 * n); ++k)
    {
        if (vertix[k] == 0)
        {
            q_for_zerodegree.push(k);
        }

    }
        //開始排
    while(!q_for_zerodegree.empty())
    {
        long long index = q_for_zerodegree.front();
        q_for_zerodegree.pop();
        topo_order.push_back(index);
        visit_or_not[index] = true;
        for(long long k = 0;k<neighbor[index].size();k++)
        {
            if(visit_or_not[neighbor[index][k].first] == 0){
                vertix[neighbor[index][k].first]--;
                if(vertix[neighbor[index][k].first] == 0 && visit_or_not[neighbor[index][k].first] == false)
                {
                    q_for_zerodegree.push(neighbor[index][k].first);
                }
            }
        }
    }

    //dp
    for(long long k = 0;k<l_is_zero.size();k++)
    {
        dp_distance[l_is_zero[k]] = 0;
    }

    for(long long k = 0 ; k<topo_order.size() ; k++)
    {
        long long tmp = topo_order[k];
        if(dp_distance[tmp] != LLONG_MIN)
        {
            for(long long i = 0 ; i < neighbor[tmp].size(); i++)
            {
                if((dp_distance[neighbor[tmp][i].first] < dp_distance[tmp] + neighbor[tmp][i].second) && l[tmp] <= dp_distance[tmp])
                {
                    //cout<<l[tmp%n]<<"\n";
                    //cout<<dp_distance[neighbor[tmp][i].first] <<" "<< dp_distance[tmp] <<" "<< neighbor[tmp][i].second<<"\n";
                    dp_distance[neighbor[tmp][i].first] = dp_distance[tmp] + neighbor[tmp][i].second;

                }
            }
        }
    }
    /*for(long long k = 1;k<=2*n;k++)
    {
        cout<<dp_distance[k]<<" ";
    }
    cout<<"\n";*/
    for(int k = 1;k<=n;k++)
    {
        cout << max(max(0LL, dp_distance[k]), dp_distance[k+n])<<" ";
    }
    cout<<"\n";

    return 0;
}

