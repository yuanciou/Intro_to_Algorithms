#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long n = 0;

/* TO DO
二分搜到哪裡打不過
二分搜要往回加到哪裡*/

bool compare(long long a, long long b){ return a < b; }


long long bisearch_righteat(long long curlevel, long long start, vector <long long> &monster)
{
    long long l = start;
    long long r = n;
    while(l < r)
    {
        long long mid = l + (r - l) / 2;
        if(monster[mid] > curlevel)
        {
            r = mid;
        }
        else 
        {
            l = mid + 1;
        }
    }
    return l;
}

long long bisearch_lefteat(long long l, long long r, long long aim, long long curlevel, vector <long long> &presum)
{
    long long maxpre = presum[r];
    while(l < r)
    {
        long long mid = l + (r - l) / 2;
        //cout<<mid<<" "<<(maxpre - presum[mid])<<"\n";
        if(curlevel + (maxpre - presum[mid]) < aim)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}


int main(){
    long long q;
    cin>>n>>q;
    vector <long long> v;
    vector <long long> presum_mon;
    v.push_back(0);
    presum_mon.push_back(0LL);
    
    for(int k = 0;k<n;k++)
    {
        long long z;
        cin>>z;
        v.push_back(z);
    }
    sort(v.begin(), v.end(), compare);
    for(int k = 1;k<=n;k++)
    {
        presum_mon[k] = v[k] + v[k - 1];
    }
    while(q--)
    {
        long long x, y;
        cin>>x>>y;
        stack <pair<long long, long long>> st;
        long long curr = 0;
        long long times = 0;
        while(x < y&&curr <= n)
        {
            if(x >= v[curr + 1])
            {
                //二分搜最大可以吃到哪裡
                long long index = bisearch_righteat(x, curr, v);
                //cout<<index<<"\n";
                st.push({curr, index - 1});
                curr = index;
                x = x + v[index];
                times++;
            }
            else
            {
                //把stack pop 出來看吃完整個會不會超過
                //會超過->二分搜要吃到哪裡
                //else直接吃整個區間 
                if(st.empty())
                {
                    break;
                }
                pair<long long, long long> tmp_inteval = st.top();
                st.pop();
                long long tmp_sum = presum_mon[tmp_inteval.second] - presum_mon[tmp_inteval.first];
                while((x < y||x < v[curr + 1]) && !st.empty())
                if((x + tmp_sum) >= y)
                {
                    long long index = bisearch_lefteat(tmp_inteval.first, tmp_inteval.second, y, x, presum_mon);
                    st.push({tmp_inteval.first, index - 1});
                    x = x + presum_mon[tmp_inteval.second] - presum_mon[index - 1];
                    times = times + tmp_inteval.second - index + 1;
                }
                else if((x + tmp_sum) >= v[curr + 1])
                {
                    long long index = bisearch_lefteat(tmp_inteval.first, tmp_inteval.second, v[curr + 1], x, presum_mon);
                    st.push({tmp_inteval.first, index - 1});
                    x = x + presum_mon[tmp_inteval.second] - presum_mon[index - 1];
                    times = times + tmp_inteval.second - index + 1;
                }
                else
                {
                    x = x + tmp_sum;
                    times = times + tmp_inteval.second - tmp_inteval.first;
                }
            }
        }
        if(x<y)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<times<<"\n";
        }
    }
    return 0;
}