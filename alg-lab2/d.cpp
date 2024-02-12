#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    node* left;
    node* right;
    int data;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector <int> val;
    vector <int> ino;
    vector <int> pos;
    vector <int> visit;
    visit.assign(n+2, 0);
    visit[0] = 1;
    visit[n+1] = 1;
    vector <int> index(n+1);
    for(int k = 0;k<n;k++)
    {
        int x;
        cin>>x;
        val.push_back(x);
    }
    for(int k = 0;k<n;k++)
    {
        int x;
        cin>>x;
        ino.push_back(x);
        index[x] = k+1;
    }
    for(int k = 0;k<n;k++)
    {
        int x;
        cin>>x;
        pos.push_back(x);
    }
    
    cout<<pos[n-1]<<"\n";
    long long sum = 0;
    
    for(int k = (n-1); k>=0;k--)
    {
        visit[index[pos[k]]] = 1;
        if(visit[index[pos[k]]-1] == 1&& visit[index[pos[k]]+1] == 1)
        {
            //cout<<pos[k]<<" "<<index[pos[k]]<<"\n";
            sum = sum + val[pos[k]-1];
        }
    }
    cout<<sum<<"\n";
    return 0;
}