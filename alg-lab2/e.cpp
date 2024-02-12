#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair <long long, long long> multi (pair <long long, long long> a, pair <long long, long long> b, long long k, long long p)
{
    pair <long long, long long> result;
    result.first = (((a.first * b.first)%p*k)%p + (a.first * b.second) %p + (a.second * b.first) %p + (a.second * b.second / k)%p)%p;
    result.second = ((a.second * b.second) %k);
    return result;
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        long long x, y, k, p;
        cin>>x>>y>>k>>p;
        //to do floor((x^y)/k)%p
        //(a*b)%c = (a%c * b%c)%n;
        
        pair <long, long> number;
        number.first = x / k;
        number.second = x % k;

        pair <long, long> res;
        res.first = 1/k;
        res.second = 1%k;

        vector <long long> exp;
        vector <pair <long, long>> exp_x;
        long long exper_y = y;
        while(exper_y){
            
            
                exp.push_back(exper_y & 1LL);
            
            exper_y = exper_y>>1;
        }
        // exp_x.push_back(res);
        exp_x.push_back(number);
        for(int r = 0; r <= exp.size(); r++)
        {
            exp_x.push_back(multi(exp_x[r], exp_x[r], k, p));
        }
        
        //res = number;
        for(int r = 0; r < exp.size(); r++)
        {
            if(exp[r] == 1)
            {
                res = multi(res, exp_x[r], k, p);
            }
        }
        cout<< res.first%p<<"\n";
    }
    return 0;
}