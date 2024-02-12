#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/* TO DO
用pair pair存區間跟值如果他沒有變大就更新他的second值*/

long long bi_search_max(vector <pair <pair <long long, long long>, long long>> &a, long long b)
{
    long long l = 0;
    long long r = a.size();
    while(l<r)
    {
        long long mid = l + (r-l) / 2;
        if(a[mid].first.second < b)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    /*
    cout<<"\n";
    for(int k = 0;k<a.size();k++)
    {
        cout<<a[k].first.first<<" "<<a[k].first.second<<" "<<a[k].second<<"\n";
    }
    cout<<"L: "<<l<<"R: "<<r<<"\n";
    cout<<"\n";*/
    if(l>r)
    {
        return a[0].second;
    }
    else{return a[l].second;}
    
}


struct node{
    long long start;
    long long end;
    long long value;
};

bool compare(node i, node j) {
    return (i.end < j.end);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    vector <node> initial_arr;
    int n;
    cin>>n;
    initial_arr.push_back({0, 0, 0});
    
    for(int k = 0;k<n;k++)
    {
        node x;
        cin>>x.start>>x.end>>x.value;
        initial_arr.push_back(x);
    }
    
    sort(initial_arr.begin(), initial_arr.end(), compare);
    vector <pair <pair <long long, long long>, long long>> maxinteval;
    maxinteval.push_back({{0, initial_arr[1].end}, 0LL});

    for(long long k = 1 ; k < n; k++)
    {
        long long x = max(initial_arr[k].value + bi_search_max(maxinteval, initial_arr[k].start), maxinteval[k-1].second);
        maxinteval.push_back({{initial_arr[k].end+1, initial_arr[k+1].end}, x});
        //cout<<"X: "<<x<<"\n";
        /*cout<<"\n";
        for(int k = 0;k<maxinteval.size();k++)
        {
            cout<<maxinteval[k].first.first<<" "<<maxinteval[k].first.second<<" "<<maxinteval[k].second<<"\n";
        }
        cout<<"\n";*/
    }
    long long x = max(initial_arr[n].value + bi_search_max(maxinteval, initial_arr[n].start), maxinteval[n-1].second);
    /*
    cout<<"\n";
    for(int k = 0;k<maxinteval.size();k++)
    {
        cout<<maxinteval[k].first.first<<" "<<maxinteval[k].first.second<<" "<<maxinteval[k].second<<"\n";
    }
    cout<<"\n";
    */
    cout<<x<<"\n";
    return 0;
}
