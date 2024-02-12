#include <iostream>
#include <bits/stdc++.h> 
#define int long long 
using namespace std;

typedef struct presum{
    int index;
    int psum;
    int w;
}presum;

int compare(presum a, presum b)
{
    return a.psum<b.psum;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <presum> a;
    int b;
    presum cou;
    cou.psum = 0;
    for(int k = 0; k<n; k++)
    {
        cin>>b;
        cou.psum = cou.psum + b;
        cou.index = k;
        a.push_back(cou);
    }
    int coun = 0;
    for(int k = 0; k<n; k++)
    {
        cin>>b;
        coun = coun + b;
        a[k].w = b;
    }
    sort(a.begin(), a.end(),compare);
    coun = coun/2 + coun%2;
    int addr = 0;
    int x = 0;
    for(int k = 0;k<n;k++)
    {
        if(x>=coun)
        {
            addr = k-1;
            break;
        }
        else
        {
            x = x + a[k].w;
        }
    }
    //cout<<coun<<" "<<addr<<"\n";
    int mink = LLONG_MAX;
    for (int idx=max(0LL,addr-10);idx<min(n,addr+10);idx++){
        int tmp=0;
        for(int k = 0;k<n;k++)
        {
            tmp = tmp + abs(a[k].psum - a[idx].psum) * a[k].w;
        }
        mink=min(mink,tmp);    
    }
    
    /*
    int mink = 10000000;
    for(int k = 0; k<n-1;k++)
    {
        int curk = 0;
        int x = a[k];
        for(int r = k;r>0;r--)//做到1就好了
        {
            curk = curk + abs(x)*w[r-1];
            x = x + a[r-1]; 
        }
        x = a[k+1];
        for(int r = k+1;r<n-1;r++)
        {
            curk = curk + abs(x)*w[r];
            x = a[r+1] + x;
        }
        if(curk < mink)
        {
            mink = curk;
        }
    }
    */
    cout<<mink<<"\n";
    return 0;
}