#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long a[2005];
long long dp[2005];
long long sum[2005];

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        fill(a, a+2005, -1);
        fill(dp, dp+2005, 0);
        fill(sum, sum+2005, 0);
        int n;
        cin>>n;
        for(int k = 0;k<n;k++)
        {
            cin>>a[k];
        }
        for(int k = 0;k<n;k++)
        {
            long long max_before = 0;
            for(int i = k-1;i>=0;i--)
            {
                if(max_before<a[i]&&a[i]<=a[k])
                {
                    dp[k] = (dp[k] + dp[i])%1000000007;
                    sum[k] = ((sum[k] + sum[i])%1000000007 + dp[i]*a[k])%1000000007;
                	max_before = max(max_before, a[i]);
                }
            }
            if(dp[k] == 0){
            	dp[k] = 1;
                sum[k] = a[k];
			}
			//cout<<sum[k]<<' ';
        }
        //cout<<"\n";
        long long cur_max = 0;
        long long count = 0;
        long long final_sum = 0;
        for(int k = n-1;k>=0;k--)
        {
            if(a[k]>cur_max)
            {
                count = (count + dp[k])%1000000007;
                final_sum = (final_sum + sum[k])%1000000007;
            }
            cur_max = max(a[k],cur_max);
        }
        cout<<count<<" "<<final_sum<<"\n";
    }
    return 0;
}

