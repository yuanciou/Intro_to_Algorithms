//
//  main.cpp
//  Algorithm_HW3_2
//
//  Created by 蔡昀錚 on 2023/11/9.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct auction{
    int start, end;
    long long profit;
};

struct node{
    int endtime;
    long long earn;
};

vector<auction> aucs;
vector<node> dp(1, {0, 0});

bool compare_end_time(auction a, auction b){
    return a.end < b.end;
}

int binary_search_end(int start_time, int lx, int rx){
    if (lx == rx){return rx;}
    int mid = (lx + rx) / 2;
    if (dp[mid].endtime >= start_time){
        return binary_search_end(start_time, lx, mid);
    }
    else{
        return binary_search_end(start_time, mid + 1, rx);
    }
}


int main(void)
{
    int n;
    long long max = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        auction tmp;
        cin >> tmp.start >> tmp.end >> tmp.profit;
        aucs.push_back(tmp);
    }
    sort(aucs.begin(), aucs.end(), compare_end_time);
    for(int i = 0; i < n; i++){
        int closest_endt = binary_search_end(aucs[i].start, 0, (int)dp.size() - 1);
        if (dp[closest_endt].endtime >= aucs[i].start){closest_endt--;}
        long long tmp = (dp[closest_endt].earn + aucs[i].profit > dp[i].earn)? dp[closest_endt].earn + aucs[i].profit : dp[i].earn;
        node new_node({aucs[i].end, tmp});
        dp.push_back(new_node);
        max = (max > tmp)? max : tmp;
    }
    cout << max << '\n';
    return 0;
}