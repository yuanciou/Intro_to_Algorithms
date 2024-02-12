#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*TO
建一個min heap heapfy max(k, size)次->priority queue pop k 次
把拿出來的所有東西加起來再丟回去*/

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    //改變優先序
    priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> participant;

    vector <vector <long long>> battle;

    for(long long r = 1; r <= n ; r++)
    {
        pair<long long, long long> x;
        cin>>x.first;
        x.second = r;
        participant.push(x);
    }
    long long num_battle = 1;
    long long total_sum = 0;
    //cout<<n % (k - 1)<<"\n";
    //cout<<(n - 1)%(k - 1) + 1<<"\n";
    if(n == 1)
    {
        cout<<"0"<<"\n"<<"0"<<"\n";
        return 0;
    }
    if(n <= k)
    {
        vector <long long> x;
        x.push_back(n);
        for(int r = 0;r < n;r++)
        {
            x.push_back(participant.top().second);
            total_sum = total_sum + participant.top().first;
            participant.pop();
        }
        cout<<total_sum<<"\n"<<"1"<<"\n";
        for(int r = 0;r<x.size();r++)
        {
            cout<<x[r]<<" ";
        }
        return 0;
    }
    if((n - 1)%(k - 1)!= 0)
    {
        vector <long long> x;
        x.push_back((n - 1)%(k - 1) + 1);
        long long sum = 0;
        for(int r = 0;r < (n - 1)%(k - 1) + 1;r++)
        {
            x.push_back(participant.top().second);
            sum = sum + participant.top().first;
            participant.pop();
        }
        battle.push_back(x);
        pair<long long, long long> y = {sum, n + num_battle};
        num_battle++;
        total_sum = total_sum + sum;
        participant.push(y);
    }
    //cout<<"sum: "<<sum<<"\n";
    while(participant.size() >= k + 1)
    {
        vector <long long> x;
        x.push_back(k);
        long long sum = 0;
        for(int r = 0 ; r < k; r++)
        {
            x.push_back(participant.top().second);
            sum = sum + participant.top().first;
            participant.pop();
        }
        battle.push_back(x);
        pair<long long, long long> y = {sum, n + num_battle};
        //cout<<"sum: "<<sum<<"\n";
        total_sum = total_sum + sum;
        num_battle++;
        participant.push(y);
    }
    vector <long long> x;
    //long long size = participant.size();
    x.push_back(k);
    while(participant.size() > 0)
    {
        x.push_back(participant.top().second);
        total_sum = total_sum + participant.top().first;
        //cout<<"sum: "<<sum<<"\n";
        participant.pop();
    }
    battle.push_back(x);
    cout<<total_sum<<"\n"<<num_battle<<"\n";
    for(int r = 0;r<battle.size();r++)
    {
        for(int z = 0; z<battle[r].size();z++)
        {
            cout<<battle[r][z]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}