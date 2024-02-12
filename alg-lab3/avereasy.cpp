#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare(long long a, long long b){ return a < b; }

long long bisearch_lefteat(long long l, long long r, long long aim, long long curlevel, vector <long long> &presum)
{
    long long maxpre = presum[r];
    while(l < r)
    {
        long long mid = l + (r - l) / 2;
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
    long long n, q;
    cin>>n>>q;
    vector <long long> v;
    v.push_back(0LL);
    for(int k = 0;k<n;k++)
    {
        long long z;
        cin>>z;
        v.push_back(z);
    }
    sort(v.begin(), v.end(), compare);
    while(q--)
    {
        long long x, y;
        cin>>x>>y;
        long long times = 0;
        long long curr = 1;
        if(x < 1000000000)
        {
            
            stack <long long> st;
            int en = 0;
            while(x<y)
            {
                //cout<<"X: "<<x<<"\n";
                if(en == 1)
                {
                    break;
                }
                else
                {
                    if(curr > n)
                    {
                        while(x < y && !st.empty())
                        {
                            x = x + st.top();
                            times++;
                            st.pop();
                        }
                        en = 1;
                    }
                    else if(x >= v[curr])
                    {
                        st.push(v[curr]);
                        curr++;
                    }
                    else
                    {
                        while((x < v[curr] && x < y )&& !st.empty())
                        {
                            x = x + st.top();
                            times++;
                            st.pop();
                        }
                        if(x < v[curr] && x < y && st.empty())
                        {
                            en = 1;
                        }
                    }
                }
            }
            
        }
        else
        {
            vector <long long> presum;
            presum.push_back(0LL);
            for(int r = 1; r<=n; r++)
            {
                presum.push_back(presum[r - 1] + v[r]);
            }
            if(x+presum[n] < y)
            {
                
            }
            else
            {
                long long index = bisearch_lefteat(1, n, y, x, presum);
                times = times + n - index + 1;
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
}