#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector <int> a;
    vector <int> b;
    a.push_back(INT_MIN);
    b.push_back(INT_MIN);
    for(int r = 0;r<n;r++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int r = 0;r<n;r++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    
    int l = 1, r = n;
    int mid;
    int a_result, b_result;
    if(k == 1)
    {
        cout<< min(a[1], b[1])<<"\n";
        return 0;
    }
    if(k == 2*n)
    {
        cout<< max(a[n], b[n])<<"\n";
        return 0;
    }

    while(r>=l){
        mid = (r - l)/2 + l;
        cout<<l<<" "<<r<<"\n";
        if(k-mid < 0)
        {
            /*if(a[mid] < b[0])
            {
                a_result = a[mid];
            }*/
            r = mid-1;
        }
        else if(a[mid] < b[k-mid])
        {
            l = mid + 1;
            //a_result = a[mid-1];
        }
        else
        {
            r = mid-1;
            //a_result = a[mid-1];
        }

        if(mid == n && a[mid] < b[k-mid])
        {
            a_result = INT_MAX;
            break;
        }
        a_result = a[l];
    }
    cout<<l<<"\n";
    l = 1;
    r = n;
    while(r >= l){
        mid = (r - l)/2 + l;
        
        if(k-mid < 0)
        {
            /*if(a[mid] < b[0])
            {
                a_result = a[mid];
            }*/
            r = mid - 1;
        }
        else if(b[mid] < a[k-mid])
        {
            l = mid + 1;
            //a_result = a[mid-1];
        }
        else
        {
            r = mid - 1;
            //a_result = a[mid-1];
        }

       if(mid == n && b[mid] < a[k-mid])
        {
            b_result = INT_MAX;
            break;
        }
        b_result = b[l];
    }
    for(int k = 0;k<=n;k++)
    {
        cout<<a[k]<<" ";
    }
    cout<<"\n";
    cout << a_result << " "<< b_result <<"\n";
    /*if(b_result < a_result)
    {
        cout<< a_result<<"\n";
    }
    else{
        cout<< b_result<<"\n";
    }*/
    return 0;
}