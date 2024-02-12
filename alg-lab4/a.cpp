#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
#pragma GCC optimize("O2")
#pragma GCC optimizw(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
*/
/*TO DOS
    ex:11111 -> create 00000~11111
    11111 是 11000 + 00111 or 11100 + 00011 or ... 裡面最小的
    如果要找11000 前面已經dp過了
*/

int matrix[19][19];
int dp[1<<18];
int number_of_element[1<<18];
vector <int> choose;
int how_to_gruop[1<<18];

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    fill(dp, dp+(1<<18), 0);
    fill(number_of_element, number_of_element+(1<<18), 0);
    int n;
    cin>>n;
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            cin>>matrix[k][i];
        }
    }

    //dp score
    //2^n n^2
    
    for (int mask = 0; mask < (1 << n); mask++){
        int cnt = 0;
        how_to_gruop[mask] = mask;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                cnt++;
                for(int j = 0; j < i; j++){
                    if(mask & (1 << j)){
                        dp[mask] += matrix[i+1][j+1];
                    }
                }
            }
        }
        number_of_element[mask] = cnt; 
        if (cnt <= 1) {
            dp[mask] = 3000;
        } 
         
    }
    /*
    for(int w = 0;w<(1<<n);w++)
    {
        cout<<number_of_element[w]<<" ";
    }
    cout<<"\n";*/
    /*
    for(int k = 0; k<(1<<n);k++)
    {
        int count = 0;
        choose.clear();
        while(count < n)
        {
            if(((1<<count) & k) == (1<<count))
            {
                choose.push_back(n - count);
            }
            count++;
        }
        //cout<<choose.size()<<"\n";
        if(choose.size()<=1)
        {
            dp[k] = 3000;
            how_to_gruop[k] = k;
            continue;
        }
        int tmp = 0;
        for(int i = 0; i < choose.size(); i++)
        {
            for(int w = i; w<choose.size();w++)
            {
                tmp = tmp + matrix[choose[i]][choose[w]];
            }
        }
        how_to_gruop[k] = k;
        dp[k] = tmp;
    }
    for(int w = 0;w<(1<<n);w++)
    {
        cout<<dp[w]<<" ";
    }
    cout<<"\n";*/
    
    //dp

    for (int mask = 0; mask < (1 << n); mask++){
        for(int i = mask; i > 0; i = (i-1) & mask){
            if(number_of_element[i]<=3)
            {
                if((dp[i] + dp[i ^ mask]) < dp[mask])
                {
                    dp[mask] = dp[i] + dp[i ^ mask];
                    //cout<<"HI "<<mask<<'\n';
                    how_to_gruop[mask] =(i^mask);
                }
                else
                {
                    dp[mask] = dp[mask];
                }
            }
        }
        
    }
/*
    for(int w = 0;w<(1<<n);w++)
    {
        cout<<dp[w]<<" ";
    }
    cout<<"\n";*/
/*
    for (int mask = 0; mask < (1<<n); mask++)
    {        
        for(int i = mask; i > 0; i = (i-1) & mask)
        {
            int count = 0;
            choose.clear();
            while(count < n)
            {
                if(((1<<count) & i) == (1<<count))
                {
                    choose.push_back(n - count);
                }
                count++;
            }
            if(choose.size()<=3)
            {
                if((dp[i] + dp[i ^ mask]) < dp[mask])
                {
                    dp[mask] = dp[i] + dp[i ^ mask];
                    //cout<<"HI "<<mask<<'\n';
                    how_to_gruop[mask] =(i ^ mask);
                }
                else
                {
                    dp[mask] = dp[mask];
                }
            }
            
        }
    }*//*
    for(int w = 0;w<(1<<n);w++)
    {
        cout<<dp[w]<<" ";
    }
    for(int w = 0;w<(1<<n);w++)
    {
        cout<<how_to_gruop[w]<<" ";
    }*/
   // cout<<"\n";
    cout << dp[(1<<n) - 1]<< "\n";
    int group_result[18+5];
    fill(group_result, group_result+23, 1);
    int group = (1<<n) - 1;
    int count_group = 2;
    while((group^how_to_gruop[group])!=0)
    {
        int w = group^how_to_gruop[group];
        int count = 0;
        choose.clear();
        while(count < n)
        {
            if(((1<<count) & w) == (1<<count))
            {
                group_result[count+1] = count_group;
            }
            count++;
        }
        count_group++;
        group = how_to_gruop[group];
    }
    for(int k = 1; k<=n;k++)
    {
        cout<<group_result[k]<<" ";

    }
    cout<<"\n";
    return 0;
}