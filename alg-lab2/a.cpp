#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector <long long> powtwo;

void outp(int head, int coun)
{
    cout<<head<<" "<<head+1<<" ";
    
    for(int k = 0;k<=n;k++)
    {
        outp(head + powtwo[k] * powtwo[k], k);        
    }
    if(coun == coun>=3)
    {
        for(int k = 0;k<=coun;k++)
        {
            outp(head + powtwo[k] * powtwo[k], k);        
        }
    }
    else
    {
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //vector <long long> powtwo;
    cin>>n;
    //頭+(2^(n-1))^2
    powtwo.push_back(0);
    for(int w = 1; w<=10; w++)
    {
        long long temp = 1;
        for(int k = 1; k<=w;k++)
        {
            temp = temp * 2;
        }
        powtwo.push_back(temp);
    }
    /*long long a = 1; //1,3象限的頭
    long long b = a + powtwo[n-1] * powtwo[n - 1];
    for(long long w = 0; w< powtwo[n - 1]; w++)
    {
        for(long long k = 0; k < powtwo[n - 1]; k++)
        {
            cout<<a++<<" ";
        }
        //a += pow(2, n-1);
        for(long long k = 0; k < powtwo[n - 1]; k++)
        {
            cout<<b++<<" ";
        }
        //b += pow(2, n-1);
        cout<<"\n";
    }
    a = 2 * (a - 1) + 1;
    b = a + powtwo[n-1] * powtwo[n-1];
    for(long long w = 0; w< powtwo[n - 1]; w++)
    {
        for(long long k = 0; k < powtwo[n - 1]; k++)
        {
            cout<<a++<<" ";
        }
        //a += pow(2, n-1);
        for(long long k = 0; k < powtwo[n - 1]; k++)
        {
            cout<<b++<<" ";
        }
        //b += pow(2, n-1);         
        cout<<"\n";
    }
    */
    int head1 = 1;
    //int a = head;
    int head2 = head1;
    cout<<"test\n";
    //cout<<a<<" "<<a+1<<" ";
    cout<<powtwo[0]<<"\n";
    cout<<head2<<"\n";
    //for(int k = 0;k<=n;k++)
    //{
    outp(head2 ,n);        
    //}
    /*head2 = head2 + 2;
    for(int k = 0;k<=n;k++)
    {
        outp(head2 + powtwo[k] * powtwo[k], k);
    }
    
    for(int r = 1;r<n;r++)
    {
        head1 = head1 + 2 * powtwo[r] * powtwo[r]; 
        
        head2 = head1;
        for(int k = 0;k<=n;k++)
        {
            outp(head2 + powtwo[k] * powtwo[k], k);
        }
        head2 = head2 + 2;
        for(int k = 0;k<=n;k++)
        {
            outp(head2 + powtwo[k] * powtwo[k], k);
        }
    }
    */
    return 0;
} 