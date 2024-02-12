#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/* TO DO
value = max (前一個一上來的自己, 自己的起始-1 + 自己的value)*/

vector <long long> result_arr;

struct node{
    long long start;
    long long end;
    long long value;
};

bool compare(node i, node j) {
    return (i.end < j.end);
}

int main(){
    vector <node> initial_arr;
    int n;
    cin>>n;
    for(int k = 0;k<n;k++)
    {
        node x;
        cin>>x.start>>x.end>>x.value;
        initial_arr.push_back(x);
    }
    
    sort(initial_arr.begin(), initial_arr.end(), compare);
    
    //到下個end 之前全部洗掉
    result_arr.resize(initial_arr[0].end, 0);
    for(long long k = initial_arr[0].end; k < initial_arr[1].end; k++)
    {
        result_arr.push_back(initial_arr[0].value);
    }
    /*for(int k = 0;k<result_arr.size();k++)
    {
        cout<<result_arr[k]<<" ";
    }
    cout<<"\n";*/
    for(long long k = 1 ; k < n - 1; k++)
    {
        long long x = max(initial_arr[k].value + result_arr[initial_arr[k].start - 1], result_arr[initial_arr[k].end - 1]);
        /*for(int k = 0;k<result_arr.size();k++)
        {
            cout<<result_arr[k]<<" ";
        }
        cout<<"\n";*/
        for(long long z = initial_arr[k].end; z < initial_arr[k+1].end; z++)
        {
            result_arr.push_back(x);
        }
    }
    
    long long x = max(initial_arr[n - 1].value + result_arr[initial_arr[n - 1].start - 1], result_arr[initial_arr[n-1].end - 1]);
    /*for(int k = 0;k<result_arr.size();k++)
    {
        cout<<result_arr[k]<<" ";
    }
    cout<<"\n";*/
    cout<<x<<"\n";
    
    return 0;
}