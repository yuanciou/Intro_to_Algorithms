#include <bits/stdc++.h>
//#define int long long 
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, k;
    cin>>n>>m>>k;
    long long count = 0;

    if(n>m)
    {
        swap(n,m);
    }

    for(long long r = 1;r <= n;r++)
    {
        //cout<<m+1-(n*m-k+1)/(n-r+1)<<"\n";
        //cout<<max(1, m+1-(n*m-k+1)/(n-r+1))<<" "<<min(m, k/r)<<"\n";
        count = count + ((min(m, k/r))-(max(1LL, (m+1)-(n*m-k+1)/(n-r+1)))) + 1LL;
    }
    cout<<count<<"\n";
    return 0;
}