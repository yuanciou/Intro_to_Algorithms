#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long adj[3005][3005] = {0};
long long dp[3005][3005] = {0};;
vector<long long> choose;

int main(){
    long long n, m, p;
    cin>>n>>m>>p;
    for(long long k = 1; k<=m ; k++)
    {
        long long u, v;
        cin>>u>>v;
        adj[u][v] = abs(u-v);
        adj[v][u] = abs(u-v);
    }


    for(long long k = 1; k<=n; k++)
    {
        for(long long i = 1;i<=k; i++)
        {
            if((k - i) == __gcd(k, i))
            {
                adj[k][i] = k-i;
                adj[i][k] = k-i;
            }
        }
    }
    /*
    for(long long k = 0; k<=n; k++)
    {
        for(long long i = 0;i<=n; i++)
        {
            cout<<adj[k][i] <<" ";
        }
        cout<< "\n";
    }
    */


    //d= 1
    for(long long u = 1; u<=n; u++)
    {
        choose.clear();
        long long x = 0;
        long long y = 0;

        if((u + 1) <= n)
        {
            if(adj[u+1][u]>0)
            {
                x = (dp[0][u + 1] + 1)%p;
            }
        }
        if((u - 1) > 0)
        {
            if(adj[u-1][u]>0)
            {
                y = (dp[0][u - 1] + 1)%p;
            }
        }
        dp[1][u] = ((dp[0][u] + x)%p + y)%p;
    }


    for(long long d = 2; d<=n; d++)
    {
        for(long long u = 1; u<=n; u++)
        {
            long long x = 0;
            long long y = 0;
            if((u + d) <= n)
            {
                if(adj[u+d][u]>0)
                {
                    x =(dp[d - 1][u + d] + 1)%p;
                }
            }
            if((u - d) > 0)
            {
                if(adj[u-d][u]>0)
                {
                    y = (dp[d - 1][u - d] + 1)%p;
                }
            }
            dp[d][u] = ((dp[d-1][u] + x)%p + y)%p ;
        }
    }
    /*
    for(long long k = 0; k<=n; k++)
    {
        for(long long i = 0;i<=n; i++)
        {
            cout<<dp[k][i]<<" ";
        }
        cout<<"\n";
    }
    */
    long long tmp = 0;
    for(long long k = 1;k<=n;k++)
    {
        tmp = (tmp + dp[n][k])%p;
    }
    cout<<tmp<<"\n";

    return 0;
}
