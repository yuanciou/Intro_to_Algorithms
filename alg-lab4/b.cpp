#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long cost[1000000];
long long value[1000000];

map<long long, long long> Map;
long long result[1000005];

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);           
    
    int t;
    cin >> t;
    long long n, v;
    long long tmp;
    while(t--)
    {
        Map.clear();
        cin >> n >> v;
        for(int k = 0;k<n;k++)
        {
            cin>>cost[k];
            Map[cost[k]] = 0;
        }
        for(int k = 0;k<n;k++)
        {
            cin>>value[k];
            Map[cost[k]] = max(Map[cost[k]], value[k]);
        }

        fill(result, result + 1000005, 0);
        map<long long, long long>::iterator iteration = Map.begin();
        while(iteration != Map.end())
        {
            for (int p = iteration->first; p <= v; ++p)
            {
                result[p] = max(result[p], result[p - iteration->first] + iteration->second);
            }
            ++iteration;
        }
        
        cout<<result[v]<<"\n";
    }
    return 0;
}