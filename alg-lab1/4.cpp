#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[100005] = {0};
int id[100005] = {0};
vector<pair<int, int>> qq;
/*
int compare(int a, int b)
{
    return a<b;
}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    int b;
    pair <int, int> c;
    for(int k = 1;k<=n;k++)
    {
        cin>>b;
        arr[b] = k;
    }
    for(int k = 0;k<q;k++)
    {
        cin>>c.first>>c.second;
        qq.push_back(c);
        //sort(arr+c.first, arr+c.second);
    }
    
    for(int k = 1;k<=n;k++)
    {
        id[arr[k]] = k;
    }

    for(int k = 0;k<q;k++)
    {
        int count = 0;
        //cout<<qq[k].first<<" "<< qq[k].second<<"\n";
        //sort(arr + qq[k].first, arr + qq[k].second+1, compare);
        /*for(int r = 0;r<n;r++)
        {
            cout<<arr[r+1]<<" ";
        }
        cout<<"\n";*/
        
        //sort
        int rightb = qq[k].second;
        for(int r = n;r>0;r--)
        {
            if(id[r]<=qq[k].second&&id[r]>=qq[k].first)
            {
                arr[rightb]=r;
                id[r]=rightb;
                //swap(arr[id[r]], arr[rightb]);
                //swap(id[id[r]], id[rightb]);
                rightb--;
                /*for(int z = 1;z<=n;z++)
                {
                    cout<<arr[z]<<" ";
                }
                cout<<"\n";
                for(int z = 1;z<=n;z++)
                {
                    cout<<id[z]<<" ";
                }
                cout<<"\n";*/
            }
            else {
                
            }
        }

        
        for(int r = 1 ; r<=n ; r++)
        {
            if(arr[r]!=r)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        if(count == n)
        {
            cout<<k+1<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
    return 0;
}