#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/* TO DO
value = max (前一個一上來的自己, 自己的起始-1 + 自己的value)*/

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
    for(int k = 0;k<n;k++)
    {
        node x;
        cin>>x.start>>x.end>>x.value;
        initial_arr.push_back(x);
    }
    
    sort(initial_arr.begin(), initial_arr.end(), compare);
    
    vector <long long> result_arr(n + 1, 0);
    result_arr[0] = initial_arr[0].value;
    result_arr.push_back(0);

    for(int k = 1;k<n;k++)
    {
        
        long long r = k - 1;
        while (initial_arr[r].end >= initial_arr[k].start)
        {
            if(r<0) break;
            else r--;
        }
        if(r < 0)
        {
            result_arr[k] = max(initial_arr[k].value, result_arr[k]);
            result_arr[k+1] = result_arr[k];
        }
        else
        {
            result_arr[k] = max(initial_arr[k].value + result_arr[r], result_arr[k]);
            result_arr[k+1] = result_arr[k];
        }
    }
            
    /*for(int k = 0;k<result_arr.size();k++)
    {
        cout<<result_arr[k]<<" ";
    }
    cout<<"\n";*/
    cout<<result_arr[n-1]<<"\n";
    return 0;
}