#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <long long> powtwo;
vector <int> start;
int n;

int arr[2048][2048] = {0};

/*void result(int bighead, int head, int currstate, int coun)
{
    if(currstate == n)
    {
        cout<<"\n";
    }
    else
    {
        cout<<head<<" "<<head+1<<" ";
        if(coun>1)
        {
            result(bighead, head + powtwo[coun - 1] * powtwo[coun - 1], currstate, coun-1);
        }
        else
        {
            coun = currstate + 1;
            currstate = currstate + 1;
            head = bighead;
            result(bighead, head + powtwo[currstate] * powtwo[currstate], currstate , coun);
        }
    }
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;

    //產生2的次方序列
    powtwo.push_back(1);
    for(int w = 1; w<=10; w++)
    {
        long long temp = 1;
        for(int k = 1; k<=w;k++)
        {
            temp = temp * 2;
        }
        powtwo.push_back(temp);
    }
    /*
    for(int k = 0;k<10;k++)
    {
        cout<<powtwo[k]<<" ";
    }
    cout<<"\n";
    */
    //產生頭
    arr[0][0] = 1;
    arr[0][1] = 3;
    arr[0][2] = 9;
    arr[0][3] = 11;
    int curr = 4;
    for(int k = 3;k<=n;k++)
    {
        for(int r = 0;(r<powtwo[k]-powtwo[k-1])&&(curr<2048);r++)
        {
            arr[0][curr++] = (arr[0][r] + 2*powtwo[k-1]*powtwo[k-1]);
        }
    }
    
    //cout<<"HH\n";
    
    for(int k = 0;k<powtwo[n];k++)
    {
        arr[1][k] = arr[0][k] + 1; 
    }
    for(int k = 0;k<powtwo[n];k++)
    {
        arr[2][k] = arr[0][k] + powtwo[1] * powtwo[1]; 
        arr[3][k] = arr[1][k] + powtwo[1] * powtwo[1]; 
    }
    //cout<<"HH\n";
    
   
    for(int z = 0;z<powtwo[n];z++)
    {
        curr = 4;
        for(int k = 3;k<=n;k++)
        {
            for(int r = 0;(r<powtwo[k]-powtwo[k-1])&&(curr<2048);r++)
            {
                //cout<<powtwo[k]<<" "<<powtwo[k] * powtwo[k]<<" "<<arr[r][z] + (powtwo[k] * powtwo[k])<<"\n";
                arr[curr][z] = (arr[r][z] + (powtwo[k-1] * powtwo[k-1]));
                int a1 = arr[r][z];
                int a2 = powtwo[k];
                int a3 = powtwo[k] * powtwo[k];
                int test = arr[curr][z];
                curr++;
            }
        }
    }
    
    
    //cout<<powtwo[n]<<"\n";
    for(int y = 0;y<powtwo[n];y++)
    {
        for(int z = 0;z<powtwo[n];z++)
        {
            cout<<arr[z][y]<<" ";
        }
        cout<<"\n";  
    }
    

/*

    int start = 1;
    result(start, start, 0, 0);    
    result(start + 2, start + 2, 0, 0);
    for(int k =1; k<n;k++)
    {
        int startp = start;
        result(startp + 2 * powtwo[k] * powtwo[k], startp + 2 * powtwo[k] * powtwo[k], 0, 0);
        result(2 + startp + 2 * powtwo[k] * powtwo[k], 2 +startp + 2 * powtwo[k] * powtwo[k], 0, 0);
        for(int r = 1; r<k;r++)
        {
            startp = startp + 2 * powtwo[r] * powtwo[r];
            result(startp + 2 * powtwo[k] * powtwo[k], startp + 2 * powtwo[k] * powtwo[k], 0, 0);
            result(2 + startp + 2 * powtwo[k] * powtwo[k], 2 +startp + 2 * powtwo[k] * powtwo[k], 0, 0);
        }
    }
    */
    return 0;
}