#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*TO DO
sort 每個小vector再乘*/
bool compare(long long i, long long j) {
    return (i < j);
}

bool compare_pair(pair<long long, long long> i, pair<long long, long long>  j) {
    return (i.first < j.first);
}

bool compare_index(pair<long long, long long> i, pair<long long, long long>  j) {
    return (i.second < j.second);
}

int main(){
    int n, m;
    cin>>n>>m;
    vector <long long> fear_level;
    vector <long long> potential;
    vector <pair <long long, long long>> levpot;
    vector <long long> a;
    for(long long k = 0; k<n; k++)
    {
        long long x;
        cin>>x;
        fear_level.push_back(x);
    }
    for(long long k = 0; k<m; k++)
    {
        long long x;
        cin>>x;
        potential.push_back(x);
    }
    long long z = 0;
    for(long long k = 0; k<n; k++)
    {
        for(int r = 0;r<m;r++)
        {
            levpot.push_back({fear_level[k] * potential[r], z});
            z++;
        }
    }
    for(long long k = 0 ; k < n*m ; k++)
    {
        long long x;
        cin>>x;
        a.push_back(x);
    }
    
    sort(levpot.begin(), levpot.end(), compare_pair);
    sort(a.begin(), a.end(), compare);
    vector <pair <long long, long long>> index;
    for(long long k = 0; k < m*n ; k++)
    {
        index.push_back({a[k], levpot[k].second});
    }
    sort(index.begin(), index.end(), compare_index);
    /*for(int k = 0;k<n*m;k++)
    {
        cout<<index[k].first<<" ";
    }
    cout<<"\n";
    for(int k = 0;k<n*m;k++)
    {
        cout<<index[k].second<<" ";
    }
    cout<<"\n";*/

    long long result = 0;
    for(long long k = 0; k < m*n ; k++)
    {
        result = result + levpot[k].first * a[k];
    }
    cout << result<< "\n";

    for(long long k = 0;k<n;k++)
    {
        cout<<fear_level[k]<<" ";
    }
    cout<<"\n";
    for(long long k = 0;k<m;k++)
    {
        cout<<potential[k]<<" ";
    }
    cout<<"\n";

    z = 0;
    for(long long k = 0 ; k < n ; k++)
    {
        for(long long r = 0; r<m ;r++)
        {
            cout << index[z].first << " ";
            z++;

        }
        cout<<"\n";
    }

    return 0;
}